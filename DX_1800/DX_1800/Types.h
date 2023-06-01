#pragma once

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720

#define CENTER Vector2(WIN_WIDTH * 0.5f, WIN_HEIGHT * 0.5f)

#define DEVICE	Device::GetInstance()->GetDevice()
#define DC		Device::GetInstance()->GetDC()

#define ALPHA		StateManager::GetInstance()->GetAlpha()
#define ADDITIVE	StateManager::GetInstance()->GetAdditive()
#define BLEND		StateManager::GetInstance()->GetBlend()
#define SAMPLER		StateManager::GetInstance()->GetSampler()

#define KEY_UP(k)			InputManager::GetInstance()->UP(k)
#define KEY_DOWN(k)			InputManager::GetInstance()->Down(k)
#define KEY_PRESS(k)		InputManager::GetInstance()->Press(k)
#define MOUSE_POS			InputManager::GetInstance()->GetMousePos()