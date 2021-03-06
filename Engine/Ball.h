#pragma once

#include "Vec2.h"
#include "SpriteCodex.h"
#include "Graphics.h"
#include "FrameTimer.h"

class Ball
{
private:
	static constexpr float radius = 7.0f;
	Vec2 pos;
	Vec2 vel;

private:
	

public:
	Ball(const Vec2& pos, const Vec2& vel);
	void Draw(Graphics& gfx) const;
	void Move(float dt);
	void ReboundX();
	void ReboundY();
	bool handleBallWallCollision(const Rect& walls);
	Rect GetRect() const;
	Vec2 GetVel() const;
	Vec2 GetPositon() const; //get the center of the ball - helper for the side collision
};