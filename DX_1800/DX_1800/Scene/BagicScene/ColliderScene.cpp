#include "framework.h"
#include "ColliderScene.h"

ColliderScene::ColliderScene()
{
	_circleCollider = make_shared<CircleCollider>(50);
	_circleCollider->GetTransform()->SetPosition(CENTER);

	_rectColliderMouse = make_shared<RectCollider>(Vector2(90,150));
	_rectCollider2  = make_shared<RectCollider>(Vector2(200,120));

	_rectCollider2->GetTransform()->SetPosition(CENTER);
}

ColliderScene::~ColliderScene()
{
}

void ColliderScene::Update()
{
	_circleCollider->Update();
	_rectColliderMouse->Update();
	_rectCollider2->Update();

	if (_rectCollider2->IsOBB(_rectColliderMouse))
	{
		_rectCollider2->SetColorRed();
		_rectColliderMouse->SetColorRed();
	}
	else
	{
		_rectCollider2->SetColorGreen();
		_rectColliderMouse->SetColorGreen();
	}

	_rectColliderMouse->GetTransform()->SetPosition(_pos);
	_rectColliderMouse->GetTransform()->SetScale(_scale);
	_rectColliderMouse->GetTransform()->SetAngle(_angle);
}

void ColliderScene::Render()
{
	_circleCollider->Render();
	_rectColliderMouse->Render();
	_rectCollider2->Render();
}

void ColliderScene::PostRender()
{
	ImGui::SliderFloat2("Pos", (float*)&_pos, 0, WIN_WIDTH, "%.0f");
	ImGui::SliderFloat2("Scale", (float*)&_scale, 0, 3, "%.1f");
	ImGui::SliderFloat2("Scale", (float*)&MOUSE_POS, 0, 3, "%.1f");
	ImGui::SliderFloat("Angle", &_angle, 0, 2 * PI, "%.1f");
}
