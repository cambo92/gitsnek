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
	brd(gfx),
	snake({ 5, 5 }, gameOver),
	food(),
	rng(std::random_device()())
{
	gameOver = false;
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (!gameOver)
	{
		snake.update(wnd.kbd);
		if (age % (int)updateFreq == 0)
		{
			snake.moveBy();
			if (snake.isCollidingSelf())
			{
				gameOver = true;
			}
			if (snake.isColliding(food))
			{
				snake.grow();
				food.jump();
				updateFreq *= 0.9f;
			}
		}

		age++;
	}
	else
	{
		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			gameOver = false;
			updateFreq = 15;
			snake.reset();
		}
	}
}

void Game::ComposeFrame()
{
	std::uniform_int_distribution<int> colourDist(0, 255);
	for (int y = 0; y < brd.getGridHeight(); y++)
	{
		for (int x = 0; x < brd.getGridWidth(); x++)
		{
			Location loc = { x, y };
			//Color c(colourDist(rng), colourDist(rng), colourDist(rng));
			//brd.drawCell(loc, c);
		}
	}
	snake.draw(brd);
	food.draw(brd);

	brd.drawBorder();
}
