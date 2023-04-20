#include "framework.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
	_mouseCircle = make_shared<CircleCollider>(50, Vector2(400,400));
	_circle = make_shared<CircleCollider>(80, Vector2(400,400));
	//_rect = make_shared<RectCollider>(Vector2(400,400), Vector2(70,50));
}

PaintScene::~PaintScene()
{
}

void PaintScene::Update()
{
	Vector2 lerpPos = LERP(_mouseCircle->GetCenter(),mousePos,0.1f);

	_mouseCircle->SetCenter(lerpPos);
	//_rect->SetCenter(lerpPos);

	if (_mouseCircle->IsCollision(_circle))
	{
		_mouseCircle->SetRed();
		_circle->SetRed();
	}
	else
	{
		_mouseCircle->SetGreen();
		_circle->SetGreen();
	}
}

void PaintScene::Render(HDC hdc)
{
	_mouseCircle->Render(hdc);
	_circle->Render(hdc);
	//_rect->Render(hdc);
}
