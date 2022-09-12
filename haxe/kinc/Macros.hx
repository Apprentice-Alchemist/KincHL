package kinc;

#if macro
import haxe.macro.Expr;
import haxe.macro.Context;

using haxe.macro.Tools;
using StringTools;
using Lambda;
#end

class Macros {
	#if macro
	public static function getDefaultReturn(t:ComplexType) {
		return switch t.toType().followWithAbstracts().toComplexType() {
			case TPath({
				pack: _,
				name: "StdTypes",
				params: _,
				sub: sub
			}): switch sub {
				case "Void": macro {};
				case "Int", "Single", "Float": macro return 0;
				case "Bool": macro return false;
				default: macro return null;
			}
			default: macro return null;
		}
	}

	public static function build_struct(s:String, no_new:Bool = false, no_alloc = false, no_destroy = false) {
		var fields = haxe.macro.Context.getBuildFields();
		var ret:Array<Field> = [];
		var real_type = switch Context.getLocalType() {
			case TInst(_.get() => _.kind => KAbstractImpl(_.get() => _.type => t), []): t.toComplexType();
			case _: null;
		}

		for (x in fields) {
			ret.push(switch x.kind {
				case FFun({
					args: args,
					ret: t,
					expr: null,
					params: params
				}):
					{
						name: x.name,
						doc: x.doc,
						access: x.access,
						kind: FFun({
							args: args,
							ret: t,
							expr: getDefaultReturn(t),
							params: params
						}),
						pos: x.pos,
						meta: x.meta
					}

				case FProp(get, set, t, e):
					if (get == "get")
						ret.push({
							name: "get_" + x.name,
							doc: "",
							access: [],
							kind: FFun({
								args: [],
								expr: getDefaultReturn(t),
								ret: t
							}),
							pos: x.pos,
							meta: [
								{name: ":hlNative", pos: x.pos, params: [macro "kinc", macro $v{"hl_" + s + "_get_" + x.name}]}
							]
						});
					if (set == "set")
						ret.push({
							name: "set_" + x.name,
							doc: "",
							access: [],
							kind: FFun({
								args: [{name: "v", type: t}],
								expr: getDefaultReturn(t),
								ret: t
							}),
							pos: x.pos,
							meta: [
								{name: ":hlNative", pos: x.pos, params: [macro "kinc", macro $v{"hl_" + s + "_set_" + x.name}]}
							]
						});
					x;
				default: x;
			});
		}
		if (!no_alloc)
			ret.push({
				name: "alloc",
				pos: haxe.macro.Context.currentPos(),
				kind: FFun({
					args: [],
					expr: macro return null,
					ret: real_type
				}),
				access: [AStatic],
				meta: [
					{
						name: ":hlNative",
						params: [macro "kinc", macro $v{"hl_" + s + "_alloc"}],
						pos: haxe.macro.Context.currentPos()
					}
				]
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
				meta: [
					{
						name: ":hlNative",
						params: [macro "kinc", macro $v{"hl_" + s + "_destroy"}],
						pos: haxe.macro.Context.currentPos()
					}
				]
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
		return ret;
	}
	#end
}
