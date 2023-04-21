#include "framework.h"
#include "Line.h"

Line::~Line()
{
}

void Line::Update()
{
	for(auto pen : _pens)
		DeleteObject(pen);
}

void Line::Render(HDC hdc)
{
	SelectObject(hdc,_pens[_curPenIdex]);

	MoveToEx(hdc, _startPos.x, _startPos.y, nullptr);
	LineTo(hdc, _endPos.x, _endPos.y);
}

void Line::CreatePens()
{
	_curPenIdex = 0;
	_pens.emplace_back(CreatePen(PS_SOLID, 3, GREEN)); // 0
	_pens.emplace_back(CreatePen(PS_SOLID, 3, RED));   // 1
}
