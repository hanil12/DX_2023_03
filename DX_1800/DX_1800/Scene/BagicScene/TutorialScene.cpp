#include "framework.h"
#include "TutorialScene.h"

TutorialScene::TutorialScene()
{
	_quad = make_shared<Quad>(L"Resource/Texture/Winter.png");

	_world = make_shared<MatrixBuffer>();
	_view = make_shared<MatrixBuffer>();
	_proj = make_shared<MatrixBuffer>();

	_world->Update_Resource();
	_view->Update_Resource();

	XMMATRIX temp = XMMatrixOrthographicOffCenterLH(0,WIN_WIDTH,0,WIN_HEIGHT, 0.0f, 1.0f);

	_proj->SetData(temp);
	_proj->Update_Resource();
}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::Update()
{
	_x += 0.01f;

	// XMMatrixScaling()
	// XMMatrixRotationZ()


	XMMATRIX translate = XMMatrixTranslation(_x, _y, 0);

	_world->SetData(translate);
	_world->Update_Resource();

	_quad->Update();
}

void TutorialScene::Render()
{
	_world->SetVS_Buffer(0);
	_view->SetVS_Buffer(1);
	_proj->SetVS_Buffer(2);

	_quad->Render();
}