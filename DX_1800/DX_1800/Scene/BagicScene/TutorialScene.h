#pragma once
class TutorialScene : public Scene
{
public:
	TutorialScene();
	virtual ~TutorialScene();

	virtual void Update() override;
	virtual void Render() override;

private:
	shared_ptr<Quad> _quad;

	float _x = 0.0f;
	float _y = 0.0f;

	shared_ptr<MatrixBuffer> _world;
	shared_ptr<MatrixBuffer> _view;
	shared_ptr<MatrixBuffer> _proj;
};

