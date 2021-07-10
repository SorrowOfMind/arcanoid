/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	ball(Vec2(300.0f, 300.0f), Vec2(-1.0f, -1.0f)),
	paddle(Vec2(380.0f, 480.0f), 170.0f, 55.0f, 12.0f, Colors::White),
	walls(10.0f, 10.0f, (float)gfx.ScreenWidth - 10.0f, (float)gfx.ScreenHeight - 10.0f),
	soundPad(L"Sounds\\arkpad.wav"),
	soundBrick(L"Sounds\\arkbrick.wav"),
	soundGameOver(L"Sounds\\fart1.wav")
{
	const Color brickColors[4] = { Colors::Red, Colors::Green, Colors::Magenta, Colors::Yellow };

	const Vec2 topleft(25.0f, 60.0f);

	int brickCounter = 0;
	for (int i = 0; i < brickRow; i++)
	{
		for (int j = 0; j < brickCol; j++)
		{
			const Color c = brickColors[i];
			Vec2 brickTopLeft = topleft + Vec2(j * brickW, i * brickH);
			bricks[brickCounter] = Brick(Rect(brickTopLeft, brickW, brickH), c);
			brickCounter++;
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();
	//slice 1 framw into more steps - helpful with more precise collisions
	//instead of one elapsed time of 16ms we are consumin 2.5ms at a time and updateing until theres no time left
	float elapsedTime = ft.Mark();
	while (elapsedTime > 0.0f) //while there is elapsedTime remaining
	{
		const float dt = std::min(0.0025f, elapsedTime); //sets dt to no more than  2.5ms
		UpdateModel(dt);
		elapsedTime -= dt;
	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(float dt)
{
	//move it to Game::Go
	//float dt = ft.Mark();

	if (!isGameOver)
	{
		if (paddle.handlePaddleBallCollision(ball))
			soundPad.Play();

		paddle.handlePaddleWallsCollision(walls);

		bool colHappened = false;
		float curColDist;
		int curColIdx;

		for (int i = 0; i < brickTotal; i++)
		{
			if (bricks[i].DetectBrickBallCollision(ball))
			{
				const float newColDist = (ball.GetPositon() - bricks[i].GetBrickCenter()).GetLengthSq(); //we just compare lengths - no matter the square or not
				if (colHappened)
				{
					if (newColDist < curColDist)
					{
						curColDist = newColDist;
						curColIdx = i;
					}
				}
				else
				{
					curColDist = newColDist;
					curColIdx = i;
					colHappened = true;
				}

			}
		}
		if (colHappened)
		{
			paddle.ResetCooldown();
			bricks[curColIdx].handleBrickBallCollision(ball);
			soundBrick.Play();
		}

		const int ballColRes = ball.handleBallWallCollision(walls);
		if (ballColRes == 1)
		{
			paddle.ResetCooldown();
			soundPad.Play();
		}
		else if (ballColRes == 2)
		{
			soundGameOver.Play();
			isGameOver = true;
		}

		paddle.Move(wnd.kbd, dt);
		ball.Move(dt);
	}
	
}

void Game::ComposeFrame()
{
	if (!isGameOver)
	{
		gfx.DrawBorder(walls, Colors::LightGray);
		ball.Draw(gfx);
		paddle.Draw(gfx);

		for (Brick& b : bricks)
		{
			b.Draw(gfx);
		}
	}
	else
		SpriteCodex::DrawGameOver(350, 250, gfx);
	


}
