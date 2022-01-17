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
		   0,  0.5, 0,
		-0.5, -0.5, 0,
		 0.5, -0.5, 0
	];
	static var indices = [0, 1, 2];

	public static function main() {
		trace(switch kinc.System.getGraphicsApi() {
			case D3D9: "D3D9";
			case D3D11: "D3D11";
			case D3D12: "D3D12";
			case OpenGL: "OpenGL";
			case Metal: "Metal";
			case Vulkan: "Vulkan";
			case Other: "Uh, idk what we're running on";
		});
		kinc.System.init("Shader", 500, 500, null, null);
		kinc.System.setUpdateCallback(update);

		var img = Image.fromFile("Deployment/parrot.png");
		texture = new kinc.g4.Texture();
		texture.initFromImage(img);

		fragment_shader = kinc.g4.Shader.create(sys.io.File.getBytes("shader.frag"), FragmentShader);
		vertex_shader = kinc.g4.Shader.create(sys.io.File.getBytes("shader.vert"), VertexShader);

		structure = new VertexStructure();
		structure.add("pos", KINC_G4_VERTEX_DATA_F32_3X);

		pipeline = new Pipeline();
		pipeline.vertex_shader = vertex_shader;
		pipeline.fragment_shader = fragment_shader;
		pipeline.input_layout[0] = structure;

		pipeline.compile();

		vertex_buffer = new VertexBuffer(3, structure, StaticUsage, 0);
		{
			var v = vertex_buffer.lock(0, 3);
			for (i in 0...vertices.length)
				v[i] = vertices[i];
			vertex_buffer.unlock(3);
		}

		index_buffer = new IndexBuffer(3, IbFormat16BIT);
		{
			var idx = index_buffer.lock();
			for (i in 0...3)
				idx[i] = indices[i];
			index_buffer.unlock();
		}
		kinc.System.start();
	}

	public static function update() {
		Graphics4.begin(0);
		Graphics4.clear(Color, 0, 0, 0);
		Graphics4.setPipeline(pipeline);
		Graphics4.setVertexBuffer(vertex_buffer);
		Graphics4.setIndexBuffer(index_buffer);
		Graphics4.drawIndexedVertices();
		Graphics4.end(0);
		Graphics4.swapBuffers();
	}
}
