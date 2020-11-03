import kinc.g4.IndexBuffer;
import kinc.g4.VertexBuffer;
import kinc.g4.Graphics4;

class Shader {
    static var fragment_shader:kinc.g4.Shader;
    static var vertex_shader:kinc.g4.Shader;
    static var pipeline:kinc.g4.Pipeline;
    static var structure:kinc.g4.VertexStructure;
    static var vertex_buffer:kinc.g4.VertexBuffer;
    static var index_buffer:kinc.g4.IndexBuffer;

    public static function main(){
        Kinc.init("Shader",500,500,null,null);
        Kinc.setUpdateCallback(update);

        fragment_shader = kinc.g4.Shader.create(haxe.Resource.getBytes("shader.frag"),FragmentShader);
        vertex_shader = kinc.g4.Shader.create(haxe.Resource.getBytes("shader.vert"),VertexShader);

        structure = new kinc.g4.VertexStructure();
        structure.add("pos",FLOAT3);

        pipeline = new kinc.g4.Pipeline();
        pipeline.vertex_shader = vertex_shader;
        pipeline.fragment_shader = fragment_shader;
        pipeline.input_layout = [structure];
        pipeline.compile();

        vertex_buffer = new VertexBuffer(3,structure,STATIC,0);
        {
            var v = vertex_buffer.lockAll();
			var i:Int = 0;
			v[i++] = -1;
			v[i++] = -1;
			v[i++] = 0.5;

			v[i++] = 1;
			v[i++] = -1;
			v[i++] = 0.5;

			v[i++] = -1;
			v[i++] = 1;
			v[i++] = 0.5;
            vertex_buffer.unlockAll();
            
        }
        index_buffer = new IndexBuffer(3,IbFormat32BIT);
        {
            var i = index_buffer.lock();
            i[0] = 0;
            i[1] = 1;
            i[2] = 2;
            index_buffer.unlock();
        }
        Kinc.start();
    }
    public static function update(){
        Graphics4.begin(0);
        Graphics4.clear(1,0,0,0);
        Graphics4.setPipeline(pipeline);
        Graphics4.setVertexBuffers([vertex_buffer]);
        Graphics4.setIndexBuffer(index_buffer);
        Graphics4.drawIndexedVertices();
        Graphics4.end(0);
        Graphics4.swapBuffers();
    }
}