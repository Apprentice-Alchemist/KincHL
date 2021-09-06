import kinc.g4.VertexStructure;
import kinc.g4.Pipeline;
import kinc.Image;
import kinc.compute.Compute;
import kinc.compute.ComputeShader;
import kinc.math.Matrix3;
import kinc.g4.ConstantLocation;
import kinc.g4.TextureUnit;
import kinc.g4.IndexBuffer;
import kinc.g4.VertexBuffer;
import kinc.g4.Graphics4;

class Compute {
	static var pipeline:Pipeline;
	static var structure:VertexStructure;
	static var vertex_buffer:VertexBuffer;
	static var index_buffer:IndexBuffer;
	static var texunit:TextureUnit;
	static var offset:ConstantLocation;
	static var texture:kinc.g4.Texture;
	static var computeShader:ComputeShader;
	static var computeUnit:ComputeTextureUnit;
	static var computeLocation:ComputeConstantLocation;

	public static function main() {
		kinc.System.init("Texture", 500, 500);
		kinc.System.setUpdateCallback(update);

		texture = new kinc.g4.Texture();
		texture.init(256, 256, FORMAT_RGBA128);

		var fragment_shader = kinc.g4.Shader.create(sys.io.File.getBytes("texture.frag"), FragmentShader);
		var vertex_shader = kinc.g4.Shader.create(sys.io.File.getBytes("texture.vert"), VertexShader);
		computeShader = new ComputeShader(sys.io.File.getBytes("shader.comp"));
		computeUnit = computeShader.getTextureUnit("destTex");
		computeLocation = computeShader.getConstantLocation("roll");
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
		Graphics4.clear(1, 0, 0, 0);

		kinc.compute.Compute.setShader(computeShader);
		kinc.compute.Compute.setTexture(computeUnit, texture, WRITE);
		kinc.compute.Compute.setFloats(computeLocation, [0]);
		kinc.compute.Compute.compute(Std.int(texture.tex_width / 16), Std.int(texture.tex_height / 16), 1);

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
