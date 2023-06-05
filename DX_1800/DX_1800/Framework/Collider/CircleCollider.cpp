#include "framework.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider(float radius)
	: _radius(radius)
{
    CreateVertices();
    CreateData();

    _type = Type::CIRCLE;
}

CircleCollider::~CircleCollider()
{
}

void CircleCollider::Update()
{
    _transform->Update();

    _colorBuffer->SetColor(_color);
    _colorBuffer->Update_Resource();
}

void CircleCollider::Render()
{
    _transform->SetWorldBuffer(0);
    _colorBuffer->SetPS_Buffer(0);

    _vertexBuffer->SetIA_VertexBuffer();
    _vs->SetIA_InputLayOut();

    DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);

    _vs->Set_VS();
    _ps->Set_PS();

    DC->Draw(_vertices.size(), 0);
}

void CircleCollider::CreateVertices()
{
    Vertex v;

    for (int i = 0; i < 37; i++)
    {
        v.pos = { _radius * cosf(i * PI / 18.0f), _radius * sinf(i * PI / 18.0f), 0.0f };
        _vertices.push_back(v);
    }
}

void CircleCollider::CreateData()
{
    _vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(Vertex), _vertices.size());
    _colorBuffer = make_shared<ColorBuffer>();

    _vs = make_shared<VertexShader>(L"Shader/ColliderVS.hlsl");
    _ps = make_shared<PixelShader>(L"Shader/ColliderPS.hlsl");
}

bool CircleCollider::IsCollision(const Vector2& pos)
{
    float distance = GetWorldPos().Distance(pos);
    if (distance < _radius)
        return true;
    return false;
}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> col)
{
    float distance = GetWorldPos().Distance(col->GetWorldPos());
    if (distance < _radius + col->GetRadius())
        return true;
    return false;
}

bool CircleCollider::IsCollision(shared_ptr<RectCollider> col)
{
    return col->IsCollision(shared_from_this());
}
