#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider()
{
}

RectCollider::RectCollider(Vector2 center, Vector2 size)
: _center(center)
, _size(size)
{
}

void RectCollider::Update()
{
}

void RectCollider::Render(HDC hdc)
{
	float left = _center.x - _size.x * 0.5f;
	float right = _center.x + _size.x * 0.5f;
	float top = _center.y - _size.y * 0.5f;
	float bottom = _center.y + _size.y * 0.5f;

	Rectangle(hdc,left, top, right, bottom);
}

void RectCollider::SetCenter(const Vector2& center)
{
	_center = center;
}
