#pragma once
#include "Vec2.h"
#include "Rect.h"
#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"

class Brick
{
private:
	Rect brick;
	Color color;
	bool isDestroyed = false;
	static constexpr float padding = 1.0f;
public:
	Brick() = default;
	Brick(const Rect& rect, Color c);
	void Draw(Graphics& gfx);
	bool handleBrickBallCollision(Ball& ball);
};