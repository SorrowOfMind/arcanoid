#pragma once

#include "Vec2.h"
#include "Colors.h"
#include "Rect.h"
#include "Graphics.h"
#include "Ball.h"
#include "Keyboard.h"

class Paddle
{
private:
	Vec2 pos;
	float speedX;
	float halfWidth;
	float halfHeight;
	Color c;
	static constexpr float wingWidth = 20.0f;
	Color wingColor = Colors::Red;
	bool isCooldown = false;
public:
	Paddle(Vec2& pos, float speedX, float halfWidth, float halfHeight, Color c);
	void handlePaddleWallsCollision(const Rect& walls);
	bool handlePaddleBallCollision(Ball& ball);
	void Draw(Graphics& gfx);
	void Move(Keyboard& kbd, float dt);
	Rect GetRect() const;
	void ResetCooldown();
};