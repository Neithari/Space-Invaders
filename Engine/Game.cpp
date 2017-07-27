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
	tank( { 400.0f,500.0f } ),
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
	if ( gameStart )
	{
		if ( !gameOver )
		{
			if ( tank.IsAlive() )
			{
				if ( lives == livesOld )
				{
					tank.Update( wnd.kbd );
				}
			}
			alien.Update();
			//Tank shot collision
			for ( int i = 0; i < 15; i++ )
			{
				if ( alien.Collision( tank.GetShotLoc( i ),tank.GetShotDim() ) )
				{
					tank.DeleteShot( i );
				}
			}
			//Alien shot collision
			if ( lives == livesOld )
			{
				for ( int i = 0; i < 15; i++ )
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
					deathTime = 120;
				}
				else
				{
					deathTime--;
				}
			}
			if ( lives <= 0 )
			{
				gameOver = true;
			}
		}
	}
	else
	{
		if ( wnd.kbd.KeyIsPressed( VK_RETURN ) )
		{
			gameStart = true;
		}
	}
}

void Game::ComposeFrame()
{
	if ( !gameOver && gameStart)
	{
		if ( lives == livesOld )
		{
			tank.Draw( gfx );
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
				tank.Draw( gfx );
			}
		}
		alien.Draw();
	}
	else
	{
		if ( !gameStart )
		{
			sprite.DrawTitle( gfx,{ 210,250 } );
		}
		if ( gameOver )
		{
			sprite.DrawGameOver( gfx,{ 350,250 } );
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
