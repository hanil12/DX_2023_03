#pragma once
class Sprite : public Quad
{
protected:
	// TODO: �и��ϱ�
	Sprite(wstring path); // -> Frame ���� �� ������������ ��
	Sprite(wstring path, Vector2 size); // -> Action�� �̿��Ͽ� Ŭ������ ������ ��
	virtual ~Sprite();

public:
	virtual void Update() override;
	virtual void Render() override;

	virtual void CreateVertices() override;
	virtual void CreateData(wstring path) override;

protected:
	shared_ptr<ActionBuffer> _actionBuffer;
};

