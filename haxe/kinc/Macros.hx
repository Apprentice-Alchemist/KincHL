package kinc;

import haxe.macro.MacroStringTools;
import haxe.macro.Expr;
import haxe.macro.Expr.Metadata;
import haxe.macro.Expr.TypePath;
import haxe.macro.Type;
import haxe.macro.Expr.TypeDefinition;
import haxe.xml.Printer;
import haxe.macro.Context;
import haxe.macro.Expr.Field;

using haxe.macro.Tools;
using StringTools;

#if macro
class Macros {
	public static function build_struct(s:String, ?no_new:Bool = false, ?no_alloc = false, ?no_destroy = false) {
		var type = Context.getLocalType();
		var actual_type = switch type {
			case TInst(t, params):
				t.get();
			default: null;
		}
		var meta = switch type {
			case TInst(t, params):
				t.get().meta;
			case TAbstract(t, params):
				t.get().meta;
			default: null;
		}
		var fields = haxe.macro.Context.getBuildFields();
		var ret:Array<Field> = [];
		for (x in fields) {
			switch x.kind {
				case FProp(get, set, t, e):
					function has(m:Metadata, n:String) {
						for (x in m)
							if (x.name == n)
								return true;
						return false;
					}
					if (!has(x.meta, ":no_get"))
						ret.push({
							name: get + "_" + x.name,
							doc: "",
							access: [],
							kind: FFun({
								args: [],
								expr: {
									var expr = null;
									if (has(x.meta, ":default_value")) {
										for (m in x.meta) {
											if (m.name == ":default_value") {
												expr = m.params[0];
											}
										}
									}
									if (expr == null)
										macro return null;
									else
										macro return $e{expr};
								},
								ret: t
							}),
							pos: x.pos,
							meta: [{name: ":hlNative", pos: x.pos, params: [macro "kinc", macro $v{s + "_hl_get_" + x.name}]}]
						});
					if (!has(x.meta, ":no_set"))
						ret.push({
							name: set + "_" + x.name,
							doc: "",
							access: [],
							kind: FFun({
								args: [{name: "v", type: t}],
								expr: {
									var expr = null;
									if (has(x.meta, ":default_value")) {
										for (m in x.meta) {
											if (m.name == ":default_value") {
												expr = m.params[0];
											}
										}
									}
									if (expr == null)
										macro return null;
									else
										macro return $e{expr};
								},
								ret: t
							}),
							pos: x.pos,
							meta: [{name: ":hlNative", pos: x.pos, params: [macro "kinc", macro $v{s + "_hl_set_" + x.name}]}]
						});
				default:
			}
		}
		if (!no_alloc)
			ret.push({
				name: "alloc",
				pos: haxe.macro.Context.currentPos(),
				kind: FFun({
					args: [],
					expr: macro return null,
					ret: switch Context.getLocalType() {
						case TAbstract(t, params): t.get().type.toComplexType();
						default: null;
					}
				}),
				access: [AStatic],
				meta: [{
					name: ":hlNative",
					params: [macro "kinc", macro $v{s + "_hl_alloc"}],
					pos: haxe.macro.Context.currentPos()
				}]
			});
		if (!no_destroy)
			ret.push({
				name: "destroy",
				pos: haxe.macro.Context.currentPos(),
				kind: FFun({
					args: [],
					expr: macro {},
					ret: TPath({pack: [], name: "Void"})
				}),
				access: [APublic],
				meta: [{
					name: ":hlNative",
					params: [macro "kinc", macro $v{s + "_hl_destroy"}],
					pos: haxe.macro.Context.currentPos()
				}]
			});
		if (!no_new)
			ret.push({
				name: "new",
				pos: haxe.macro.Context.currentPos(),
				kind: FFun({
					args: [],
					expr: macro this = alloc(),
					ret: TPath({pack: [], name: "Void"})
				}),
				access: [APublic]
			});
		return ret.concat(fields);
	}

	public static function build_native_array() {
		function get_return(t:ComplexType):Expr {
			switch t {
				case TPath({
					name: "F32",
					params: [],
					pack: ["hl"]
				}):
					return macro return 0;
				case TPath({
					name: "StdTypes",
					params: [],
					sub: "Int",
					pack: []
				}), TPath({
						name: "Int",
						params: [],
						pack: []
					}):
					return macro return 0;
				default:
					return macro return null;
			}
		}
		var type = haxe.macro.Context.getLocalType().followWithAbstracts(true);
		var paramst:ComplexType = null;
		var hl_name:String = null;
		switch type {
			case TInst(t, params):
				paramst = params[0].toComplexType();
				switch params[1] {
					case TInst(t, params): hl_name = t.get().name.substr(1);
					case x: trace(x);
				}
			default:
				throw "Expected TInst";
		}
		var tparams = switch type {
			case TInst(t, params):
				switch params[0] {
					case TInst(t, ps): if (t.toString() == "hl.Abstract") {
							ps;
						} else params;
					default: params;
				}
			case TAbstract(t, params): params;
			case TType(t, params): params;
			default: [];
		}
		var tname2 = hl_name;
		var tname = "NativeArray_" + tname2;
		var tpath:TypePath = {pack: ["kinc", "util"], name: tname}
		try {
			return haxe.macro.Context.getType("kinc.util." + tname);
		} catch (e:Dynamic) {
			var tdef:TypeDefinition = {
				pack: ["kinc", "util"],
				name: tname,
				fields: [{
					name: "alloc",
					pos: haxe.macro.Context.currentPos(),
					kind: FFun({
						args: [{
							name: "length",
							type: TPath({
								pack: [],
								name: "Int"
							})
						}],
						expr: macro return null,
						ret: TPath(tpath)
					}),
					meta: [{
						name: ":hlNative",
						params: [macro "kinc", macro $v{tname2 + "_hl_array_alloc"}],
						pos: haxe.macro.Context.currentPos()
					}],
					access: [AStatic, APublic]
				}, {
					name: "get",
					pos: haxe.macro.Context.currentPos(),
					kind: FFun({
						args: [{
							name: "i",
							type: TPath({
								pack: [],
								name: "Int"
							})
						}],
						expr: get_return(paramst),
						ret: paramst
					}),
					access: [APublic],
					meta: [{
						name: ":arrayAccess",
						pos: haxe.macro.Context.currentPos()
					}, {
						name: ":hlNative",
						params: [macro "kinc", macro $v{tname2 + "_hl_array_get"}],
						pos: haxe.macro.Context.currentPos()
					}]
				}, {
					name: "set",
					pos: haxe.macro.Context.currentPos(),
					kind: FFun({
						args: [{
							name: "i",
							type: TPath({
								pack: [],
								name: "Int"
							})
						}, {
							name: "v",
							type: paramst
						}],
						expr: get_return(paramst),
						ret: paramst
					}),
					access: [APublic],
					meta: [{
						name: ":arrayAccess",
						pos: haxe.macro.Context.currentPos()
					}, {
						name: ":hlNative",
						params: [macro "kinc", macro $v{tname2 + "_hl_array_set"}],
						pos: haxe.macro.Context.currentPos()
					}]
				}, {
					name: "fromArray",
					meta: [{name: ":from", pos: haxe.macro.Context.currentPos()}],
					kind: FFun({
						args: [{name: "arr", type: TPath({pack: [], name: "Array", params: [TPType(paramst)]})}],
						expr: macro {
							var ret = alloc(arr.length);
							for (x in 0...arr.length) {
								ret[x] = arr[x];
							}
							ret[arr.length] = $e{
								macro(function() {
									$e{get_return(paramst)}
								})()
							};
							return ret;
						},
						ret: null
					}),
					pos: haxe.macro.Context.currentPos(),
					access: [APublic, AStatic]
				}],
				pos: haxe.macro.Context.currentPos(),
				kind: TDAbstract(TPath({
					pack: ["hl"],
					name: "Ref",
					params: [TPType(paramst)]
				}))
			};
			haxe.macro.Context.defineType(tdef);
			return haxe.macro.Context.getType("kinc.util." + tname);
		}
	}
}
#end
