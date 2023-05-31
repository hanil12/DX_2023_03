#include "framework.h"
#include "SolarSystem.h"

SolarSystem::SolarSystem()
{
	// 과제1
	// 태양, 지구, 달
	// 태양계 구현

	// 과제2... extra
	// 위의 과제에서 Planet이라는 클래스로 구현
	// 위의 과제에서 태양의 자전주기와 지구의 공전주기가 서로 다르도록

	// _sun = make_shared<Planet>(L"Resource/Texture/sun.png");

	_sun = make_shared<Quad>(L"Resource/Texture/sun.png");
	_earth = make_shared<Quad>(L"Resource/Texture/earth.png");

	_sun->GetTransform()->SetPosition(CENTER);

	_sun->GetTransform()->SetScale(Vector2(0.3f,0.3f));
	_earth->GetTransform()->SetScale(Vector2(0.3f,0.3f));

	_earth->GetTransform()->SetParent(_sun->GetTransform());
	_earth->GetTransform()->SetPosition(Vector2(600.0f, 0.0f));
}

SolarSystem::~SolarSystem()
{
}

void SolarSystem::Update()
{
	_sun->GetTransform()->AddAngle(0.0001f);
	_earth->GetTransform()->AddAngle(0.0001f);

	_sun->Update();
	_earth->Update();
}

void SolarSystem::Render()
{
	_sun->Render();
	_earth->Render();
}
