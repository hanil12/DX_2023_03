#pragma once
class Quad
{
public:
	Quad(wstring path);
	Quad(wstring path, Vector2 size);
	~Quad();

	void Update();
	void Render();

	void CreateVertices();
	void CreateData(wstring path);

	shared_ptr<Transform> GetTransform() { return _transform; }

private:
	vector<Vertex_Texture> _vertices;
	vector<UINT> _indices;

	shared_ptr<VertexBuffer> _vertexBuffer;
	shared_ptr<IndexBuffer> _indexBuffer;
	shared_ptr<VertexShader> _vs;
	shared_ptr<PixelShader> _ps;

	shared_ptr<SRV> _srv;

	// ������Ʈ ����
	shared_ptr<Transform> _transform;

	Vector2 _size;
};

