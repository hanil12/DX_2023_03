#include "framework.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
	_circle = make_shared<CircleCollider>(50, Vector2(400,400));
}

PaintScene::~PaintScene()
{
}

void PaintScene::Update()
{
	// circle�ݶ��̴��� �߽��� ���콺�� ���� ��������
	// ��������
	Vector2 lerpPos = LERP(_circle->GetCenter(),mousePos,0.1f);

	_circle->SetCenter(lerpPos);
}

void PaintScene::Render(HDC hdc)
{
	_circle->Render(hdc);
}
