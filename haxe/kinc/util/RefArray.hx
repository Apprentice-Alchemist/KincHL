package kinc.util;

abstract RefArray<T,@:const L>(hl.Ref<T>) {
	@:arrayAccess inline function get(i:Int)
		return this.offset(i).get();

	@:arrayAccess inline function set(i:Int, v:T) {
		this.offset(i).set(v);
		return v;
    }
}
