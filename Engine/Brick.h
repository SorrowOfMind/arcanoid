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
	//take ball collision in 2 separete calls
	//first checks for collision, seconds do the collision
	bool DetectBrickBallCollision(const Ball& ball) const;
	void handleBrickBallCollision(Ball& ball);
	Vec2 GetBrickCenter() const;
};