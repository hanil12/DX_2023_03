#include "framework.h"
#include "SpriteScene.h"

SpriteScene::SpriteScene()
{
	_sprite = make_shared<Sprite>(L"Resource/Texture/zelda.png", Vector2(10,8), Vector2(200,200));
	_transform = make_shared<Transform>();
	_transform->SetPosition(CENTER);

	_sprite->SetCurFrame(Vector2(0,1));
}

SpriteScene::~SpriteScene()
{
}

void SpriteScene::Update()
{
	_transform->Update();
	_sprite->Update();
}

void SpriteScene::Render()
{
	_transform->SetWorldBuffer(0);
	_sprite->Render();
}

void SpriteScene::PostRender()
{
	ImGui::SliderFloat2("CurFrame", (float*)&_curFrame.x, 0, 10, "%.0f");

	_sprite->SetCurFrame(_curFrame);
}
