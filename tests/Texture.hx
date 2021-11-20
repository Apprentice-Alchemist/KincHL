import kinc.g4.VertexStructure;
import kinc.g4.Pipeline;
import kinc.Image;
import kinc.math.Matrix3;
import kinc.g4.ConstantLocation;
import kinc.g4.TextureUnit;
import kinc.g4.IndexBuffer;
import kinc.g4.VertexBuffer;
import kinc.g4.Graphics4;

class Texture {
	static var pipeline:Pipeline;
	static var structure:VertexStructure;
	static var vertex_buffer:VertexBuffer;
	static var index_buffer:IndexBuffer;
	static var texunit:TextureUnit;
	static var offset:ConstantLocation;
	static var texture:kinc.g4.Texture;

	public static function main() {
		kinc.System.init("Texture", 500, 500);
		kinc.System.setUpdateCallback(update);

		#if (format && test_format)
		var img = new kinc.Image();
		var data = new format.png.Reader(new BytesInput(Resource.getBytes("parrot.png"))).read();
		var bytes = format.png.Tools.extract32(data);
		@:privateAccess img.init(bytes.getData(), 250, 250, FORMAT_BGRA32);
		#else
		var img = Image.fromFile("Deployment/parrot.png");
		#end
		texture = new kinc.g4.Texture();
		texture.initFromImage(img);
		img = null;

		var fragment_shader = kinc.g4.Shader.create(sys.io.File.getBytes("texture.frag"), FragmentShader);
		var vertex_shader = kinc.g4.Shader.create(sys.io.File.getBytes("texture.vert"), VertexShader);

		structure = new kinc.g4.VertexStructure();
		structure.add("pos", Float3);
		structure.add("tex", Float2);

		pipeline = new kinc.g4.Pipeline();
		pipeline.vertex_shader = vertex_shader;
		pipeline.fragment_shader = fragment_shader;
		pipeline.input_layout[0] = structure;
		pipeline.compile();

		texunit = pipeline.getTextureUnit("texsampler");
		offset = pipeline.getConstantLocation("mvp");

		vertex_buffer = new VertexBuffer(4, structure, StaticUsage, 0);
		{
			var v = vertex_buffer.lockAll();
			v[0] = -1.0;
			v[1] = -1.0;
			v[2] = 0.5;
			v[3] = 0.0;
			v[4] = 1.0;
			v[5] = 1.0;
			v[6] = -1.0;
			v[7] = 0.5;
			v[8] = 1.0;
			v[9] = 1.0;
			v[10] = -1.0;
			v[11] = 1.0;
			v[12] = 0.5;
			v[13] = 0.0;
			v[14] = 0.0;
			vertex_buffer.unlockAll();
		}
		index_buffer = new IndexBuffer(4, IbFormat32BIT);
		{
			var i = index_buffer.lock();
			i[0] = 0;
			i[1] = 1;
			i[2] = 2;
			i[3] = 3;
			index_buffer.unlock();
		}
		kinc.System.start();
	}

	public static function update() {
		Graphics4.begin(0);
		Graphics4.clear(Color, 0, 0, 0);
		Graphics4.setPipeline(pipeline);
		var matrix = Matrix3.rotationZ(kinc.System.time());
		Graphics4.setMatrix3(offset, matrix);
		Graphics4.setVertexBuffer(vertex_buffer);
		Graphics4.setIndexBuffer(index_buffer);
		Graphics4.setTexture(texunit, texture);
		Graphics4.drawIndexedVertices();
		Graphics4.end(0);
		Graphics4.swapBuffers();
	}
}
