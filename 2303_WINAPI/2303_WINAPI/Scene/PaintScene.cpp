#include "framework.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
}

PaintScene::~PaintScene()
{
}

void PaintScene::Update()
{
	// circle콜라이더의 중심이 마우스를 따라 움직여라
}

void PaintScene::Render(HDC hdc)
{
	Ellipse(hdc, mousePos.x, mousePos.y, 700,700);
}
