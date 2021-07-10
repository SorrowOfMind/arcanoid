#pragma once
#include "Vec2.h"

class Rect
{
public:
	float left;
	float top;
	float right;
	float bottom;
public:
	Rect() = default;
	Rect(float left, float top, float right, float bottom);
	Rect(const Vec2& top_left, const Vec2& bottom_right);
	Rect(const Vec2& top_left, float width, float height);
	bool IsCollidingWithOtherRect(const Rect& other_rect) const;
	static Rect FromCenter(const Vec2& center, float halfWidth, float halfHeight);
	Rect GetExpanded(float offset);
	Vec2 GetCenter() const;
	bool IsContainedBy(const Rect& other) const;
};