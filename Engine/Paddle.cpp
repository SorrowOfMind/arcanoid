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

bool Paddle::handlePaddleBallCollision(Ball& ball)
{
	if (!isCooldown)
	{
		const Rect paddle = GetRect();
		if (paddle.IsCollidingWithOtherRect(ball.GetRect()))
		{
			const Vec2 ballCenter = ball.GetPositon();
			if (std::signbit(ball.GetVel().x) == std::signbit((ballCenter - pos).x) || ballCenter.x >= paddle.left && ballCenter.x <= paddle.right)
			{
				Vec2 dir;
				const float xDifference = ballCenter.x - pos.x; //to the right +, to the left -
				const float fixedXComponent = fixedZoneHalfWidth * exitFactor;

				if (std::abs(xDifference) < fixedZoneHalfWidth)
				{
					if (xDifference < 0.0f)
						dir = Vec2(-fixedZoneExitX, -1.0f);
					else
						dir = Vec2(fixedZoneExitX, -1.0f);
				}
				else
				{
					//calculate the vector for the direction
					const Vec2 dir(xDifference * exitFactor, -1.0f);
					ball.SetDirection(dir);
				}
			}
			else
				ball.ReboundX();

			isCooldown = true;
			return true;
		}
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

void Paddle::ResetCooldown()
{
	isCooldown = false;
}
