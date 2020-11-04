import kinc.math.Matrix3;
import kinc.g4.ConstantLocation;
import kinc.g4.TextureUnit;
import kinc.g4.IndexBuffer;
import kinc.g4.VertexBuffer;
import kinc.g4.Graphics4;

class Texture {
	static var fragment_shader:kinc.g4.Shader;
	static var vertex_shader:kinc.g4.Shader;
	static var pipeline:kinc.g4.Pipeline;
	static var structure:kinc.g4.VertexStructure;
	static var vertex_buffer:kinc.g4.VertexBuffer;
	static var index_buffer:kinc.g4.IndexBuffer;
    static var texunit:TextureUnit;
	static var offset:ConstantLocation;
	static var texture:kinc.g4.Texture;
	static var matrix = Matrix3.alloc();
	public static function main() {
		for (x in 0...3) {
			matrix.set(x, x, 1);
		}
		Kinc.init("Texture", 500, 500, null, null);
		Kinc.setUpdateCallback(update);
        var img = kinc.Image.fromFile("Deployment/parrot.png");
        texture = new kinc.g4.Texture();
        texture.initFromImage(img);
		img.destroy();
		fragment_shader = kinc.g4.Shader.create(haxe.Resource.getBytes("texture.frag"), FragmentShader);
		vertex_shader = kinc.g4.Shader.create(haxe.Resource.getBytes("texture.vert"), VertexShader);

        structure = new kinc.g4.VertexStructure();
        structure.size = 0;
		structure.add("pos", FLOAT3);
        structure.add("tex",FLOAT2);

		pipeline = new kinc.g4.Pipeline();
		pipeline.vertex_shader = vertex_shader;
		pipeline.fragment_shader = fragment_shader;
        pipeline.input_layout = [structure];
		pipeline.compile();

        texunit = pipeline.getTextureUnit("texsampler");
		offset = pipeline.getConstantLocation("mvp");
		
		vertex_buffer = new VertexBuffer(4, structure, STATIC, 0);
		{
			var v = vertex_buffer.lockAll();
			v[0] = -1.0 /*f*/;
			v[1] = -1.0 /*f*/;
			v[2] = 0.5 /*f*/;
			v[3] = 0.0 /*f*/;
			v[4] = 1.0 /*f*/;
			v[5] = 1.0 /*f*/;
			v[6] = -1.0 /*f*/;
			v[7] = 0.5 /*f*/;
			v[8] = 1.0 /*f*/;
			v[9] = 1.0 /*f*/;
			v[10] = -1.0 /*f*/;
			v[11] = 1.0 /*f*/;
			v[12] = 0.5 /*f*/;
			v[13] = 0.0 /*f*/;
			v[14] = 0.0 /*f*/;
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
		Kinc.start();
	}

	public static function update() {
		Graphics4.begin(0);
		Graphics4.clear(1, 0, 0, 0);
		Graphics4.setPipeline(pipeline);
		
		var alpha = Kinc.time();
		var ca = Math.cos(alpha);
		var sa = Math.sin(alpha);
		matrix.set(0, 0, ca);
		matrix.set(0, 1, -sa);
		matrix.set(1, 0, sa);
		matrix.set(1, 1, ca);
        Graphics4.setMatrix3(offset,matrix);
		Graphics4.setVertexBuffer(vertex_buffer);
		Graphics4.setIndexBuffer(index_buffer);
        Graphics4.setTexture(texunit,texture);
		Graphics4.drawIndexedVertices();
		Graphics4.end(0);
		Graphics4.swapBuffers();
	}
}