#pragma once
#include "Vec2.h"
#include "Rect.h"
#include "Colors.h"
#include "Graphics.h"

class Brick
{
private:
	Rect brick;
	Color color;
	bool isDestroyed = false;
public:
	Brick() = default;
	Brick(const Rect& rect, Color c);
	void Draw(Graphics& gfx);

};