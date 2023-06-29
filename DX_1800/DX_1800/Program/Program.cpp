#include "framework.h"
#include "Program.h"

#include "../Scene/BagicScene/TutorialScene.h"
#include "../Scene/BagicScene/SolarSystem.h"
#include "../Scene/BagicScene/DunGreedScene.h"
#include "../Scene/BagicScene/ColliderScene.h"
#include "../Scene/BagicScene/SpriteScene.h"
#include "../Scene/BagicScene/ZeldaScene.h"
#include "../Scene/BagicScene/CupHeadScene.h"

Program::Program()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	_curScene = make_shared<DunGreedScene>();

	Timer::GetInstance()->LockFPS(60);
}

Program::~Program()
{
}

void Program::Update()
{
	Timer::GetInstance()->Update();
	InputManager::GetInstance()->Update();
	CAMERA->Update();
	_curScene->Update();

	EFFECT->Update();
	SOUND->Update();
}

void Program::Render()
{
	Device::GetInstance()->Clear();

	CAMERA->SetViewBuffer();
	CAMERA->SetProjectionBuffer();

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	ALPHA->SetState();
	_curScene->Render();
	EFFECT->Render();

	ImGui::Text("FPS : %d", FPS);
	ImGui::Text("DeltaTime : %1f", DELTA_TIME);
	ImGui::Text("RunTime : %1f", RUN_TIME);
	CAMERA->PostRender();

	CAMERA->SetUIViewBuffer();
	_curScene->PostRender();
	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	Device::GetInstance()->Present();
}
