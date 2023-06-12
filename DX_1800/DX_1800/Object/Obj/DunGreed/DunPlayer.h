#pragma once
class DunPlayer
{
public:
	DunPlayer();
	~DunPlayer();

	void Update();
	void Render();

	void InPut();

	void SetPosition(Vector2 pos) { _quad->GetTransform()->SetPosition(pos); }
	void AddVector2(Vector2 pos) { _quad->GetTransform()->AddVector2(pos); }

	vector<shared_ptr<class DunBullet>>& GetBullets() { return _bullets; }

private:
	shared_ptr<Quad> _quad;
	shared_ptr<Transform> _bowSlot;

	shared_ptr<Quad> _bowQuad;

	vector<shared_ptr<class DunBullet>> _bullets;
};

