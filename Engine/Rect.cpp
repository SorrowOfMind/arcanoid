#include "Rect.h"

Rect::Rect(float left, float top, float right, float bottom)
	:
	left(left),
	top(top),
	right(right),
	bottom(bottom)
{
}

Rect::Rect(const Vec2& top_left, const Vec2& bottom_right)
	:
	Rect(top_left.x, top_left.y, bottom_right.x, bottom_right.y)
{
}

Rect::Rect(const Vec2& top_left, float width, float height)
	:
	Rect(top_left, top_left + Vec2(width, height))

{
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

Rect Rect::FromCenter(const Vec2& center, float halfWidth, float halfHeight)
{
	const Vec2 half(halfWidth, halfHeight);
	return Rect(center - half, center + half);
}

Rect Rect::GetExpanded(float offset)
{
	return Rect(left - offset, top - offset, right + offset, bottom + offset);
}
