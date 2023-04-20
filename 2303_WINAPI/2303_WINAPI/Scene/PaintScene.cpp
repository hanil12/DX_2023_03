#include "framework.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
	_circle = make_shared<CircleCollider>(50, Vector2(400,400));
	//_rect = make_shared<RectCollider>(Vector2(400,400), Vector2(70,50));
}

PaintScene::~PaintScene()
{
}

void PaintScene::Update()
{
	Vector2 lerpPos = LERP(_circle->GetCenter(),mousePos,0.1f);

	_circle->SetCenter(lerpPos);
	//_rect->SetCenter(lerpPos);

	if (_circle->IsCollision(mousePos))
	{
		_circle->SetRed();
	}
	else
	{
		_circle->SetGreen();
	}
}

void PaintScene::Render(HDC hdc)
{
	_circle->Render(hdc);
	//_rect->Render(hdc);
}
