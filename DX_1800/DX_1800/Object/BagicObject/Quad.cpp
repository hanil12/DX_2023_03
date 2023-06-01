#include "framework.h"
#include "Quad.h"

Quad::Quad(wstring path)
{
    _srv = make_shared<SRV>(path);

	CreateVertices();
	CreateData(path);

    _transform = make_shared<Transform>();
}

void Quad::Update()
{
    _transform->Update();
}

void Quad::Render()
{
    _transform->SetWorldBuffer(0);

    _vertexBuffer->SetIA_VertexBuffer();
    _indexBuffer->SetIA_IndexBuffer();
    _vs->SetIA_InputLayOut();
    DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    _srv->SetSRV(0);
    SAMPLER->SetSampler();

    _vs->Set_VS();
    _ps->Set_PS();

    DC->DrawIndexed(_indices.size(),0,0);
}

void Quad::CreateVertices()
{
    Vertex v;

    Vector2 halfSize = _srv->GetImageSize() * 0.5f;

    v.pos = { -halfSize.x, halfSize.y, 0.0f }; // ���� ��
    v.color = { 1.0f, 0.0f, 0.0f, 1.0f };
    v.uv = { 0.0f, 0.0f };
    _vertices.push_back(v);

    v.pos = { halfSize.x, halfSize.y, 0.0f }; // ������ ��
    v.color = { 0.0f, 1.0f, 0.0f, 1.0f };
    v.uv = { 1.0f, 0.0f };
    _vertices.push_back(v);

    v.pos = { halfSize.x, -halfSize.y, 0.0f }; // ������ �Ʒ�
    v.color = { 0.0f, 0.0f, 1.0f, 1.0f };
    v.uv = { 1.0, 1.0f };
    _vertices.push_back(v);

    v.pos = { -halfSize.x, -halfSize.y, 0.0f }; // ���� �Ʒ�
    v.color = { 0.0f, 0.0f, 0.0f, 1.0f };
    v.uv = { 0.0f, 1.0f };
    _vertices.push_back(v);

    _indices.push_back(0);
    _indices.push_back(1);
    _indices.push_back(2);

    _indices.push_back(0);
    _indices.push_back(2);
    _indices.push_back(3);
}

void Quad::CreateData(wstring path)
{
	_vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex), _vertices.size());
    _indexBuffer = make_shared<IndexBuffer>(_indices.data(), _indices.size());
	_vs = make_shared<VertexShader>(L"Shader/TextureVS.hlsl");
	_ps = make_shared<PixelShader>(L"Shader/TexturePS.hlsl");
}
