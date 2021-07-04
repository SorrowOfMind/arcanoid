#include "Brick.h"

Brick::Brick(const Rect& rect, Color c)
	:
	brick(rect),
	color(c)
{
}

void Brick::Draw(Graphics& gfx)
{
	if (!isDestroyed)
		gfx.DrawRect(brick, color);
}

bool Brick::handleBrickBallCollision(Ball& ball)
{
	const Rect ballRect = ball.GetRect();
	bool hasCollided = false;
	if (brick.IsCollidingWithOtherRect(ballRect) && !isDestroyed)
	{
		isDestroyed = true;
		ball.ReboundY();
		hasCollided = true;
	}

	return hasCollided;
}
