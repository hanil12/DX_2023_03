#pragma once
class RectCollider
{
public:
	RectCollider();
	RectCollider(Vector2 center, Vector2 size);

	void Update();
	void Render(HDC hdc);

	void SetCenter(const Vector2& center);
	Vector2 GetCenter() { return _center;}

private:
	Vector2 _center = {0,0};
	Vector2 _size = {0,0};
};

