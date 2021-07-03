#include "Rect.h"

Rect::Rect(float left, float right, float top, float bottom)
	:
	left(left),
	right(right),
	top(top),
	bottom(bottom)
{
}

Rect::Rect(Vec2& top_left, Vec2& bottom_right)
{
	Rect(top_left.x, bottom_right.x, top_left.y, bottom_right.y);
}

Rect::Rect(Vec2& top_left, float width, float height)
{
	Vec2 bottom_right = Vec2(top_left.x + width, top_left.y + height);
	Rect(top_left, bottom_right);
}

bool Rect::IsCollidingWithOtherRect(const Rect& other_rect) const
{
	const float other_left = other_rect.left;
	const float other_right = other_rect.right;
	const float other_top = other_rect.top;
	const float other_bottom = other_rect.bottom;

	return (left <= other_right 
			&& bottom >= other_top 
			&& right >= other_left 
			&& top <= other_bottom);
}
