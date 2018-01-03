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
	xDist( 0.0f, 800.0f ),
	yDist( 0.0f, 600.0f ),
	pTank( new Tank( gfx, tankStartLoc ) ),
	// there is a bug with the in_playspace not upating correctly after change of a parameter in game.cpp or game.h
	// bug occurse even with a couple diffrent code locations. It's maybe a compiler didn't initialize the variable
	// yet problem not sure.
	// only occuring in release. Everything is fine in develop.
	pAlien( new Alien( gfx, alienShotMax, alienShotChance, &alienSpace ) )
{
	Vec2<int> loc = houseStartLoc;
	for( int i = 0; i < houseCount; i++ )
	{
		pHouse[i] = new House( loc );
		loc.x += 100;
	}
}

Game::~Game()
{
	delete pAlien;
	pAlien = nullptr;
	delete pTank;
	pTank = nullptr;
	for( int i = 0; i < houseCount; i++ )
	{
		delete pHouse[i];
		pHouse[i] = nullptr;
	}
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
	dt = ft.Mark();
	if( gameStart && !gameOver && !youWon )
	{
		//check if tank got hit
		if( lives == livesOld )
			{
				pTank->Update( wnd.kbd,dt );
				gameOver = !pAlien->Update( dt );
				//Tank shot collision
				CollisionTankShot();
				//Alien shot collision
				CollisionAlienShot();
				//Alien collision with house
				if( pAlien->GetRect().bottom >= houseStartLoc.y )
				{
					std::vector<Rect<float>> alienBottomRects = pAlien->GetAliensForRow( pAlien->GetBottomRow() );
					std::vector<Rect<float>> alienBottom2Rects = pAlien->GetAliensForRow( pAlien->GetBottomRow() - 1 );
					for( int h = 0; h < houseCount; h++ )
					{
						for( auto alienRect : alienBottomRects )
						{
							pHouse[h]->IsColliding( alienRect );
						}
						// check for 2. bottom row
						for( auto alienRect : alienBottom2Rects )
						{
							pHouse[h]->IsColliding( alienRect );
						}
					}
				}
				//check for win
				if( pAlien->Count() <= 0 )
				{
					youWon = true;
				}
				//check for loss
				if( lives <= 0 )
				{
					gameOver = true;
				}
			}
		else //if tank got hit update death time
		{
			if( deathTimer <= 0.0f )
			{
				livesOld = lives;
				deathTimer = deathTime;
			}
			else
			{
				deathTimer -= dt;
			}
		}
	}
	else
	{
		if( wnd.kbd.KeyIsPressed( VK_RETURN ) )
		{
			RestartGame();
		}
	}
	// check for hiScore
	if( score > hiScore )
	{
		hiScore = score;
	}
}

void Game::ComposeFrame()
{
	// background
	gfx.DrawSprite( 0, 0, spriteBackground, SpriteEffect::Chroma{ Colors::Magenta } );
	// highscore text
	std::string hiScoreText = "Highscore: " + std::to_string( hiScore );
	font.DrawText( hiScoreText, hiScorePos, Colors::White, gfx );
	if( !gameOver && gameStart && !youWon)
	{
		if( lives == livesOld )
		{
			pTank->Draw();
		}
		else
		{
			TankGotHit();
		}
		for( int i = 0; i < houseCount; i++ )
		{
			pHouse[i]->Draw( gfx );
		}
		pAlien->Draw();
		// score text
		std::string scoreText = "Score: " + std::to_string( score );
		font.DrawText( scoreText, scorePos, Colors::White, gfx );
		// lives text
		std::string livesText = "Lives: " + std::to_string( lives );
		font.DrawText( livesText, livesPos, Colors::White, gfx );
		
	}
	else
	{
		if( !gameStart )
		{
			gfx.DrawSprite( 210, 250, spriteTitle, SpriteEffect::Chroma{ Colors::Magenta } );
		}
		if( gameOver )
		{
			gfx.DrawSprite( 350, 250, spriteGameOver, SpriteEffect::Chroma{ Colors::Black } );
		}
		if( youWon )
		{
			gfx.DrawSprite( 310, 200, spriteYouWon, SpriteEffect::Chroma{ Colors::Magenta } );
		}
	}
}

void Game::RestartGame()
{
	gameOver = false;
	gameStart = true;
	score = 0;
	delete pAlien;
	pAlien = new Alien( gfx, alienShotMax, alienShotChance, &alienSpace );
	delete pTank;
	pTank = new Tank( gfx, tankStartLoc );
	Vec2<int> loc = houseStartLoc;
	for( int i = 0; i < houseCount; i++ )
	{
		delete pHouse[i];
		pHouse[i] = new House( loc );
		loc.x += 100;
	}
	lives = startLives;
	livesOld = startLives;
	youWon = false;
}

void Game::CollisionTankShot()
{
	for( int s = 0; s < pTank->GetShotCount(); s++ )
	{
		bool isCollided = false;
		Rect<float> tankShot = pTank->GetShotRect( s );

		for( int h = 0; h < houseCount; h++ )
		{
			if( pHouse[h]->IsColliding( tankShot ) )
			{
				isCollided = true;
				pTank->DeleteShot( s );
				break;
			}
		}
		for( int i = 0; i < alienShotMax && !isCollided; i++ )
		{
			if( pAlien->IsShotAlive( i ) )
			{
				if( tankShot.IsOverlappingWith( pAlien->GetShotRect( i ) ) )
				{
					isCollided = true;
					pTank->DeleteShot( s );
					pAlien->DeleteShot( i );
					break;
				}
			}
		}
		for( int a = 0; a < alienRows && !isCollided; a++ )
		{
			if( pAlien->Collision( tankShot, score ) )
			{
				pTank->DeleteShot( s );
				break;
			}
		}
	}
}

void Game::CollisionAlienShot()
{
	for( int i = 0; i < alienShotMax; i++ )
	{
		bool isCollided = false;
		const Rect<float> alienShot = pAlien->GetShotRect( i );

		for( int h = 0; h < houseCount; h++ )
		{
			if( pHouse[h]->IsColliding( alienShot ) )
			{
				isCollided = true;
				pAlien->DeleteShot( i );
				break;
			}
		}
		if( pTank->Collision( alienShot ) && !isCollided )
		{
			pAlien->DeleteShot( i );
			lives--;
			break;
		}
	}
}

void Game::TankGotHit()
{
	if( (deathTimer < deathTime * 0.75f && deathTimer > deathTime * 0.68f ) ||
		(deathTimer < deathTime * 0.5f && deathTimer > deathTime * 0.43f ) ||
		(deathTimer < deathTime * 0.25f && deathTimer > deathTime * 0.18f ) )
	{
		pTank->Draw();
	}
	else
	{
		pTank->DrawHit();
	}
}
