#include "framework.h"
#include "SolarSystem.h"

SolarSystem::SolarSystem()
{
	// ����1
	// �¾�, ����, ��
	// �¾�� ����

	// ����2... extra
	// ���� �������� Planet�̶�� Ŭ������ ����
	// ���� �������� �¾��� �����ֱ�� ������ �����ֱⰡ ���� �ٸ�����

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
