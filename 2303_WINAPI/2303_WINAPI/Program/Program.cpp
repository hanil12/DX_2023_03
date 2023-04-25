#include "framework.h"

#include "Scene/PaintScene.h"
#include "Scene/LineScene.h"
#include "Scene/LineCollisionScene.h"
#include "Scene/CannonScene.h"

#include "Program.h"

HDC Program::_backBuffer = nullptr; 
Program::Program()
{
	HDC hdc = GetDC(hWnd);

	_backBuffer = CreateCompatibleDC(hdc);
	_hBit = CreateCompatibleBitmap(hdc, WIN_WIDTH, WIN_HEIGHT);
	SelectObject(_backBuffer, _hBit);

	// �� �ٲٱ�
	_scene = make_shared<CannonScene>();
}

Program::~Program()
{
	DeleteObject(_backBuffer);
	DeleteObject(_hBit);
}

void Program::Update()
{
	_scene->Update();
}

void Program::Render(HDC hdc)
{
	PatBlt(_backBuffer, 0,0,WIN_WIDTH, WIN_HEIGHT, BLACKNESS);

	_scene->Render(_backBuffer);

	BitBlt(
		hdc,
		0,0,WIN_WIDTH, WIN_HEIGHT,
		_backBuffer, 0, 0,
		SRCCOPY
	);
}
