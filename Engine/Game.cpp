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

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	rng( rd() ),
	xDist( 0.0f,800.0f ),
	yDist( 0.0f,600.0f ),
	tank( gfx,{ 400.0f,500.0f } ),
	alien( gfx )
{
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
	const float dt = ft.Mark();
	if ( gameStart && !gameOver && !youWon )
	{
		if ( tank.IsAlive() )
		{
			if ( lives == livesOld )
			{
				tank.Update( wnd.kbd,dt );
			}
		}
		alien.Update( dt );
		//Tank shot collision
		CollisionTankShot();
		//Alien shot collision
		CollisionAlienShot();
	}
	else
	{
		if ( wnd.kbd.KeyIsPressed( VK_RETURN ) )
		{
			RestartGame();
		}
	}
}

void Game::ComposeFrame()
{
	if ( !gameOver && gameStart && !youWon)
	{
		if ( lives == livesOld )
		{
			tank.Draw();
		}
		else
		{
			int t75 = 90;
			int t50 = 60;
			int t25 = 30;
			if ( deathTime == t75 ||
				deathTime == t75 - 1 ||
				deathTime == t75 - 2 ||
				deathTime == t50 ||
				deathTime == t50 - 1 ||
				deathTime == t50 - 2 ||
				deathTime == t25 ||
				deathTime == t25 - 1 ||
				deathTime == t25 - 2 )
			{
				tank.Draw();
			}
		}
		alien.Draw();
	}
	else
	{
		if ( !gameStart )
		{
			Sprite::DrawTitle( 210,250,gfx );
		}
		if ( gameOver )
		{
			Sprite::DrawGameOver( 350,250,gfx );
		}
		if ( youWon )
		{
			Sprite::DrawYouWon( 310,200,gfx );
		}
	}
}

float Game::ClampToScreen( const Location & in_loc,const Dimention & in_dim )
{
	const float left = in_loc.x;
	const float right = in_loc.x + in_dim.width;
	const float top = in_loc.y;
	const float bottom = in_loc.y + in_dim.height;

	if ( left < 0 )
	{
		return 0.0f;
	}
	if ( right >= gfx.ScreenWidth )
	{
		return gfx.ScreenWidth - float( in_dim.width + 1 );
	}
	else
	{
		return in_loc.x;
	}
	if ( top < 0 )
	{
		return 0.0f;
	}
	if ( bottom >= gfx.ScreenHeight )
	{
		return gfx.ScreenHeight - float( in_dim.height + 1 );
	}
	else
	{
		return in_loc.y;
	}
}

void Game::RestartGame()
{
	gameOver = false;
	gameStart = true;
	alien.Restart();
	tank.Restart();
	lives = 3;
	livesOld = 3;
	youWon = false;
}

void Game::CollisionTankShot()
{
	for ( int i = 0; i < alienRows; i++ )
	{
		if ( alien.Collision( tank.GetShotLoc( i ),tank.GetShotDim() ) )
		{
			tank.DeleteShot( i );
		}
	}
	if ( alien.Count() <= 0 )
	{
		youWon = true;
	}
}

void Game::CollisionAlienShot()
{
	if ( lives == livesOld )
	{
		for ( int i = 0; i < alienRows; i++ )
		{
			if ( tank.Collision( alien.GetShotLoc( i ),alien.GetShotDim() ) )
			{
				alien.DeleteShot( i );
				lives--;
				break;
			}
		}
	}
	else
	{
		if ( deathTime <= 0 )
		{
			livesOld = lives;
			deathTimer = deathTime;
		}
		else
		{
			deathTimer--;
		}
	}
	if ( lives <= 0 )
	{
		gameOver = true;
	}
}
