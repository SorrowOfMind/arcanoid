#pragma once
#include "Vec2.h"

class Rect
{
public:
	float left;
	float right;
	float top;
	float bottom;
public:
	Rect() = default;
	Rect(float left, float right, float top, float bottom);
	Rect(const Vec2& top_left, const Vec2& bottom_right);
	Rect(const Vec2& top_left, float width, float height);
	bool IsCollidingWithOtherRect(const Rect& other_rect) const;
	
};