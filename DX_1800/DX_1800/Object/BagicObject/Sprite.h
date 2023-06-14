#pragma once
class Sprite : public Quad
{
public:
	// TODO: �и��ϱ�
	Sprite(wstring path, Vector2 maxFrame); // -> Frame ���� �� ������������ ��
	Sprite(wstring path, Vector2 maxFrame, Vector2 size); // -> Action�� �̿��Ͽ� Ŭ������ ������ ��
	virtual ~Sprite();

	virtual void Update() override;
	virtual void Render() override;

	virtual void CreateVertices() override;
	virtual void CreateData(wstring path) override;

	void SetCurClip(Vector2 frame);
	void SetCurClip(Action::Clip clip);

private:
	shared_ptr<ActionBuffer> _actionBuffer;

	Vector2 _maxFrame;
};

