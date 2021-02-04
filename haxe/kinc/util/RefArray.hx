package kinc.util;

abstract RefArray<T>(hl.Ref<T>) {
	public var length(get, never):Int;

	private inline function get_length():Int {
		var l = 0;
		var t = this;
		while (true) {
			t = t.offset(8);
			if (t.get() == null)
				break;
			l++;
		}
		return l;
	}

	@:arrayAccess inline function get(i:Int)
		return this.offset(8 * i).get();

	@:arrayAccess inline function set(i:Int, v:T) {
		this.offset(8 * i).set(v);
		return v;
    }
    
    @:to inline function toArray(){
        return [for(i in 0...get_length()) get(i)];
    }

    @:to function toString(){
        return toArray().toString();
    }
}
