import kinc.g4.IndexBuffer;
import kinc.g4.VertexBuffer;
import kinc.g4.Shader;
import kinc.g4.VertexStructure;
import kinc.g4.Pipeline;
import kinc.Callbacks;
import kinc.g4.Graphics4;

class Main {
	static var structure:VertexStructure;
	static var pipeline:Pipeline;
	static var vertex_shader:Shader;
	static var fragment_shader:Shader;
	static var vertex_buffer:VertexBuffer;
	static var index_buffer:IndexBuffer;

	public static function main() {
		Kinc.init("Title", 300, 300, null, null);

		vertex_shader = new Shader();
		vertex_shader.initFromFile("Deployment/shader.vert", VERTEX);
		fragment_shader = new Shader();
        fragment_shader.initFromFile("Deployment/shader.frag", FRAGMENT);
        
		structure = new kinc.g4.VertexStructure();
		structure.add("pos", FLOAT3);
        
		pipeline = new Pipeline();
		pipeline.vertex_shader = vertex_shader;
		pipeline.fragment_shader = fragment_shader;
		pipeline.input_layout = [structure];
		pipeline.compile();

		vertex_buffer = VertexBuffer.make(3, structure, STATIC, 0);
		{
			var v = vertex_buffer.lock_all();
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
			vertex_buffer.unlock_all();
		}
		index_buffer = IndexBuffer.make(3, _32BIT);
		{
			var i = index_buffer.lock();
			i[0] = 0;
			i[1] = 1;
			i[2] = 2;
			index_buffer.unlock();
		}

		Callbacks.set_update_callback(function() {
			Graphics4.begin(0);
			Graphics4.clear(1, 0x000000, 2, 4);

			Graphics4.setPipeline(pipeline);
			Graphics4.setVertexBuffer(vertex_buffer);
			Graphics4.setIndexBuffer(index_buffer);
			Graphics4.drawIndexedVertices();

			Graphics4.end(0);
			Graphics4.swapBuffers();
		});
		Kinc.start();
	}
}
