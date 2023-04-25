#pragma once
class Cannon
{
public:
	Cannon();
	~Cannon();

	void Update();
	void Render(HDC hdc);

	void MoveByInput();
	void Fire();
	shared_ptr<Bullet> SetBullet();

	void SetPostion(const Vector2& pos) { _pos = pos; }
	void TakeDamage() { _hp -= 1;}

	vector<shared_ptr<Bullet>>& GetBullets() { return _bullets; }

	shared_ptr<Collider> GetCol() { return _body; }

	bool IsDead() { return _hp <= 0;}

	bool _isControll = true;
private:
	shared_ptr<CircleCollider> _body;
	Vector2 _pos = CENTER;
	float _barrelLength = 100.0f;
	float _speed = 2.0f;

	shared_ptr<Line> _barrel;
	Vector2 _direction;
	float _angle = 0.0f;


	// �̸� �����س���
	// ���� �Է��� ������ ����(�����Ҵ�)���� �ʰ� �̸� �����س��� Ǯ���� �����״ٸ� �ݺ�
	// => ������Ʈ Ǯ��
	bool _spacePress = false;
	bool _spaceUp = true;
	float _power; // TODO : �����̽��� ������ �����ϴٰ� ���� ���� Bullet Speed ����
	vector<shared_ptr<Bullet>> _bullets;

	int _hp = 5;
};

