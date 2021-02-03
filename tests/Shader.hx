import kinc.g4.TextureUnit;
import kinc.g4.RenderTarget;
import kinc.g4.Pipeline;
import kinc.g4.VertexStructure;
import kinc.g4.IndexBuffer;
import kinc.g4.VertexBuffer;
import kinc.g4.Graphics4;
import kinc.Image;

class Shader {
	static var fragment_shader:kinc.g4.Shader;
	static var vertex_shader:kinc.g4.Shader;
	static var pipeline:Pipeline;
	static var structure:VertexStructure;
	static var vertex_buffer:VertexBuffer;
	static var index_buffer:IndexBuffer;
	static var texture:kinc.g4.Texture;
	static var vertices = [
		-0.5,  0.5, 0, 0, 0,
		 0.5,  0.5, 0, 1, 0,
		 0.5, -0.5, 0, 1, 1,
		-0.5, -0.5, 0, 0, 1
	];
	static var indices = [0, 1, 2, 2, 3, 0];
	static var tex_unit:TextureUnit;
	static var renderTarget:RenderTarget;

	public static function main() {
		kinc.System.init("Shader", 500, 500, null, null);
		kinc.System.setUpdateCallback(update);

		var img = Image.fromFile("Deployment/parrot.png");
		texture = new kinc.g4.Texture();
		texture.initFromImage(img);

		fragment_shader = kinc.g4.Shader.create(sys.io.File.getBytes("Deployment/shader.frag"), FragmentShader);
		vertex_shader = kinc.g4.Shader.create(sys.io.File.getBytes("Deployment/shader.vert"), VertexShader);

		structure = new VertexStructure();
		structure.add("pos", Float3);
		structure.add("uv", Float2);

		pipeline = new Pipeline();
		pipeline.vertex_shader = vertex_shader;
		pipeline.fragment_shader = fragment_shader;
		pipeline.input_layout[0] = structure;

		pipeline.compile();
		tex_unit = pipeline.getTextureUnit("tex");

		vertex_buffer = new VertexBuffer(Std.int(vertices.length / 5), structure, StaticUsage, 0);
		{
			var v = vertex_buffer.lockAll();
			for (i in 0...vertices.length)
				v[i] = vertices[i];
			vertex_buffer.unlockAll();
		}

		index_buffer = new IndexBuffer(indices.length, IbFormat32BIT);
		{
			var idx = index_buffer.lock();
			for (i in 0...indices.length)
				idx[i] = indices[i];
			index_buffer.unlock();
		}
		renderTarget = RenderTarget.create(250, 250, 24, false, Format32Bit, 8, 0);
		kinc.System.start();
	}

	public static function update() {
		Graphics4.begin(0);
		Graphics4.setRenderTargets([renderTarget]);
		Graphics4.clear(1, 0, 0, 0);
		Graphics4.setPipeline(pipeline);
		Graphics4.setVertexBuffer(vertex_buffer);
		Graphics4.setIndexBuffer(index_buffer);
		Graphics4.setTexture(tex_unit, texture);
		Graphics4.drawIndexedVertices();
		Graphics4.end(0);

		Graphics4.begin(0);
		Graphics4.restoreRenderTarget();
		Graphics4.clear(1, 0, 0, 0);
		Graphics4.setPipeline(pipeline);
		Graphics4.setVertexBuffer(vertex_buffer);
		Graphics4.setIndexBuffer(index_buffer);
		renderTarget.useColorAsTexture(tex_unit);
		Graphics4.drawIndexedVertices();
		Graphics4.end(0);
		Graphics4.swapBuffers();
	}
}
