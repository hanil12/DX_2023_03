#include "framework.h"
#include "ColliderScene.h"

ColliderScene::ColliderScene()
{
	_rectCollider = make_shared<CircleCollider>(50);
	_rectCollider->GetTransform()->SetPosition(CENTER);
}

ColliderScene::~ColliderScene()
{
}

void ColliderScene::Update()
{
	_rectCollider->Update();
}

void ColliderScene::Render()
{
	_rectCollider->Render();
}
