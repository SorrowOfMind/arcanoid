#include "Ball.h"

Ball::Ball(const Vec2& pos, const Vec2& vel)
	:
	pos(pos),
	vel(vel)
{
}

void Ball::Draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall(pos, gfx);
}

void Ball::Move(float dt)
{
	pos += vel * dt;
}
