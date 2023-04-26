#pragma once

#include "framework.h"

#define WIN_WIDTH 1280
#define WIN_HEIGHT 720
#define CENTER Vector2(WIN_WIDTH * 0.5f, WIN_HEIGHT * 0.5f)

#define PI 3.141592
#define GRAVITY 0.07f

#define LERP(s,e,t) s + (e - s)*t

#define RED		 RGB(255,0,0)
#define GREEN	 RGB(0,255,0)
#define GREY	 RGB(100,100,100)
#define BLUE	 RGB(0,0,255)

struct HitResult
{
	shared_ptr<class Collider> col;
	class Vector2 contact;
	bool isCollision;
};