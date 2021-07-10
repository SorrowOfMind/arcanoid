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

int Ball::handleBallWallCollision(const Rect& walls)
{
	int collisionResult = 0;;
	Rect ballRect = GetRect();
	if (ballRect.left <= walls.left)
	{
		pos.x = walls.left + radius; //adjust the position
		ReboundX();	//turn velocity
		collisionResult = 1;
	}
	else if (ballRect.right >= walls.right)
	{
		pos.x -= ballRect.right - walls.right;
		ReboundX();
		collisionResult = 1;
	}
	else if (ballRect.top <= walls.top)
	{
		pos.y += walls.top - ballRect.top;
		ReboundY();
		collisionResult = 1;
	}
	else if (ballRect.bottom >= walls.bottom)
	{
	/*	pos.y -= (ballRect.bottom - walls.bottom);
		ReboundY();
		hasCollided = true;*/
		collisionResult = 2;
	}
	return collisionResult;
}

Rect Ball::GetRect() const
{
	return Rect::FromCenter(pos, radius, radius);
}

Vec2 Ball::GetVel() const
{
	return vel;
}

Vec2 Ball::GetPositon() const
{

	return pos;
}
