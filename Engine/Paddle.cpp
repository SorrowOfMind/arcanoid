#include "Paddle.h"

Paddle::Paddle(Vec2& pos, float speedX, float halfWidth, float halfHeight, Color c)
	:
	pos(pos),
	speedX(speedX),
	halfWidth(halfWidth),
	halfHeight(halfHeight),
	c(c)
{
}

void Paddle::handlePaddleWallsCollision(const Rect& walls)
{
	const Rect paddleRect = GetRect();
	if (paddleRect.left <= walls.left)
		pos.x += walls.left - paddleRect.left;
	else if (paddleRect.right >= walls.right)
		pos.x -= paddleRect.right - walls.right;
}

bool Paddle::handlePaddleBallCollision(Ball& ball) const
{
	if (GetRect().IsCollidingWithOtherRect(ball.GetRect()) && ball.GetVel().y > 0)
	{
		ball.ReboundY();
		return true;
	}
	return false;
}

void Paddle::Draw(Graphics& gfx)
{
	Rect padRect = GetRect();
	gfx.DrawRect(padRect, wingColor);
	padRect.left += wingWidth;
	padRect.right -= wingWidth;
	gfx.DrawRect(padRect, c);
}

void Paddle::Move(Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_LEFT))
		pos.x -= speedX * dt;
	if (kbd.KeyIsPressed(VK_RIGHT))
		pos.x += speedX * dt;
}

Rect Paddle::GetRect() const
{
	return Rect::FromCenter(pos, halfWidth, halfHeight);
}
