#include "framework.h"
#include "DunMonster.h"

DunMonster::DunMonster()
{
	_col = make_shared<RectCollider>(Vector2(250,150));
	_quad = make_shared<Quad>(L"Resource/Texture/Winter.png", Vector2(245,145));
	_quad->GetTransform()->SetParent(_col->GetTransform());
}

DunMonster::~DunMonster()
{
}

void DunMonster::Update()
{
	if(IsActive() == false)
		return;

	_col->Update();
	_quad->Update();
}

void DunMonster::Render()
{
	if (IsActive() == false)
		return;

	_col->Render();
	_quad->Render();
}
