#pragma once
class CircleCollider
{
public:
	// Ÿ�Ժ�ȯ������

	void Update();
	void Render(HDC);

private:
	// �������?
	float _radius;
	Vector2 _center;
};

