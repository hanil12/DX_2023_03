#pragma once

#include "framework.h"

#define PI 3.141592

#define LERP(s,e,t) s + (e - s)*t

#define RED		 RGB(255,0,0)
#define GREEN	 RGB(0,255,0)

struct HitResult
{
	shared_ptr<class Collider> col;
	class Vector2 contact;
	bool isCollision;
};