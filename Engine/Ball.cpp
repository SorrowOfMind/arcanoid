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

void Ball::ReboundX()
{
	vel.x = -vel.x;
}

void Ball::ReboundY()
{
	vel.y = -vel.y;
}

bool Ball::handleBallWallCollision(const Rect& walls)
{
	bool hasCollided = false;
	Rect ballRect = GetRect();
	if (ballRect.left <= walls.left)
	{
		pos.x = walls.left + radius; //adjust the position
		ReboundX();	//turn velocity
		hasCollided = true;
	}
	else if (ballRect.right >= walls.right)
	{
		pos.x -= ballRect.right - walls.right;
		ReboundX();
		hasCollided = true;
	}
	else if (ballRect.top <= walls.top)
	{
		pos.y += walls.top - ballRect.top;
		ReboundY();
		hasCollided = true;
	}
	else if (ballRect.bottom >= walls.bottom)
	{
		pos.y -= (ballRect.bottom - walls.bottom);
		ReboundY();
		hasCollided = true;
	}

	return hasCollided;
}

Rect Ball::GetRect() const
{
	return Rect::FromCenter(pos, radius, radius);
}
