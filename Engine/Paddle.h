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
	const Color wingColor = {210, 255, 210};
	const Color color = {200, 220, 200};
	static constexpr float wingWidth = 6.0f;
	static constexpr float speed = 360.0f;
	bool isCooldown = false;
	//control the paddle reboud behavior here
	static constexpr float maxExitRatio = 2.6f; //exit rate at the very edge of the paddle (x component is 2.6 times bigger than the y component)
	static constexpr float fixedZoneWidthRatio = 0.2f; //as ratio to the entire paddle width
	//these are derived from above controls
	float exitFactor;
	float fixedZoneHalfWidth;
	float fixedZoneExitX;
public:
	Paddle(Vec2& pos, float speedX, float halfWidth, float halfHeight, Color c);
	void handlePaddleWallsCollision(const Rect& walls);
	bool handlePaddleBallCollision(Ball& ball);
	void Draw(Graphics& gfx);
	void Move(Keyboard& kbd, float dt);
	Rect GetRect() const;
	void ResetCooldown();
};