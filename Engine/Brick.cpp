#include "Brick.h"

Brick::Brick(const Rect& rect, Color c)
	:
	brick(rect),
	color(c)
{
}

void Brick::Draw(Graphics& gfx)
{
	gfx.DrawRect(brick, color);
}
