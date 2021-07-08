#include "Brick.h"
#include <assert.h>

Brick::Brick(const Rect& rect, Color c)
	:
	brick(rect),
	color(c)
{
}

void Brick::Draw(Graphics& gfx)
{
	if (!isDestroyed)
	{
		gfx.DrawRect(brick.GetExpanded(-padding), color);
	}
}

void Brick::handleBrickBallCollision(Ball& ball)
{
	//determine what case of collision we have
	//assumes the detectCollision is done - put some assert here to check
	//in release mode this assertion will get stripped from the code
	assert(	DetectBrickBallCollision(ball));
	
	const Vec2 ballCenter = ball.GetPositon();
	if (std::signbit(ball.GetVel().x) == std::signbit((ballCenter - brick.GetCenter()).x))
		ball.ReboundY();
	else if (ballCenter.x >= brick.left && ballCenter.x <= brick.right)
		ball.ReboundY();
	else
		ball.ReboundX();

	isDestroyed = true;
}

Vec2 Brick::GetBrickCenter() const
{
	return brick.GetCenter();
}

bool Brick::DetectBrickBallCollision(const Ball& ball) const
{
	return brick.IsCollidingWithOtherRect(ball.GetRect()) && !isDestroyed;
}

