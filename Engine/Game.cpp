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
	playSpace( alienStartLoc.x, gfx.ScreenWidth - alienStartLoc.x - 7, alienStartLoc.y, tankStartLoc.y ),
	pTank( new Tank( gfx, tankStartLoc, &playSpace, tankShotMax ) ),
	pAlien( new Alien( gfx, alienShotMax, alienShotChance, &playSpace ) ),
	soundInvaderKilled( L"Sounds\\invaderkilled.wav" ),
	soundExplosion( L"Sounds\\explosion.wav" )
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
			// Alien sound
			if( pAlien->GetMoveTime() <= pAlien->GetMoveSpeed() )
			{
				// play Invader Sound
				soundInvader[playSoundInvader].Play( 1.0f, 0.5f );
				// increment the index to play the 4 different sounds
				playSoundInvader++;
				if( playSoundInvader == 4 )
				{
					playSoundInvader = 0;
				}
			}
			// UFO sound
			if( soundUFOTime >= 2.0f && pAlien->IsUFOAlive() )
			{
				// play UFO Sound
				soundUFO.Play( 1.0f, 0.5f );
				soundUFOTime = 0.0f;
			}
			soundUFOTime += dt;
			// delete collisionLoc after set time
			if( !collisionTime.empty() )
			{
				for( int i = 0; i < collisionTime.size(); i++ )
				{
					collisionTime[i] += dt;
					if( collisionTime[i] >= 0.1f && !collisionLoc.empty() )
					{
						collisionLoc.pop_front();
						collisionTime.erase( collisionTime.begin() + i );
					}
				}
			}
			// Tank shot collision
			CollisionTankShot();
			// if tankshot killed a UFO stop the sound
			if( !pAlien->IsUFOAlive() )
			{
				soundUFO.StopAll();
			}
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
		// explosion draw
		if( !collisionLoc.empty() )
		{
			for( auto cLoc : collisionLoc )
			{
				gfx.DrawSprite( cLoc.x, cLoc.y, spriteExplosion, SpriteEffect::Chroma{ Colors::White } );
			}
		}
		// score text
		std::string scoreText = "Score:";
		if( score < 10 )
		{
			scoreText += "000";
		}
		else if( score < 100 )
		{
			scoreText += "00";
		}
		else if( score < 1000 )
		{
			scoreText += "0";
		}
		scoreText += std::to_string( score );
		font.DrawText( scoreText, scorePos, Colors::White, gfx );
		// highscore text
		std::string hiScoreText = "Highscore:";
		if( hiScore < 10 )
		{
			hiScoreText += "000";
		}
		else if( hiScore < 100 )
		{
			hiScoreText += "00";
		}
		else if( hiScore < 1000 )
		{
			hiScoreText += "0";
		}
		hiScoreText += std::to_string( hiScore );
		font.DrawText( hiScoreText, hiScorePos, Colors::White, gfx );
		// lives text
		std::string livesText = "Lives:" + std::to_string( lives );
		font.DrawText( livesText, livesPos, Colors::Red, gfx );
		
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
	collisionLoc.clear();
	collisionTime.clear();
	playSoundInvader = 0;
	delete pAlien;
	pAlien = new Alien( gfx, alienShotMax, alienShotChance, &playSpace );
	delete pTank;
	pTank = new Tank( gfx, tankStartLoc, &playSpace, tankShotMax );
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
				soundInvaderKilled.Play( 1.0f, 0.5f );
				pTank->DeleteShot( s );
				collisionLoc.emplace_back( pAlien->GetCollisionLoc() );
				collisionTime.emplace_back( 0.0f );
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
			soundExplosion.Play( 1.0f, 0.5f );
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
