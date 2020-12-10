import kinc.g4.Pipeline;
import kinc.g4.VertexStructure;
import kinc.g4.IndexBuffer;
import kinc.g4.VertexBuffer;
import kinc.g4.Graphics4;

class Shader {
	static var fragment_shader:kinc.g4.Shader;
	static var vertex_shader:kinc.g4.Shader;
	static var pipeline:Pipeline;
	static var structure:VertexStructure;
	static var vertex_buffer:VertexBuffer;
	static var index_buffer:IndexBuffer;

	public static function main() {
		kinc.System.init("Shader", 500, 500, null, null);
		kinc.System.setUpdateCallback(update);

		fragment_shader = kinc.g4.Shader.create(sys.io.File.getBytes("Deployment/shader.frag"), FragmentShader);
		vertex_shader = kinc.g4.Shader.create(sys.io.File.getBytes("Deployment/shader.vert"), VertexShader);

		structure = new VertexStructure();
		structure.add("pos", Float3);

		pipeline = new Pipeline();
		pipeline.vertex_shader = vertex_shader;
		pipeline.fragment_shader = fragment_shader;
		pipeline.input_layout[0] = structure;

		pipeline.compile();

		vertex_buffer = new VertexBuffer(3, structure, StaticUsage, 0);
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

		index_buffer = new IndexBuffer(3, IbFormat32BIT);
		{
			var i = index_buffer.lock();
			i[0] = 0;
			i[1] = 1;
			i[2] = 2;
			index_buffer.unlock();
		}
		kinc.System.start();
	}

	public static function update() {
		Graphics4.begin(0);
		Graphics4.clear(1, 0, 0, 0);
		Graphics4.setPipeline(pipeline);
		Graphics4.setVertexBuffer(vertex_buffer);
		Graphics4.setIndexBuffer(index_buffer);
		Graphics4.drawIndexedVertices();
		Graphics4.end(0);
		Graphics4.swapBuffers();
	}
}
