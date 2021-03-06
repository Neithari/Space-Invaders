/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Vec2.h"
#include <random>
#include <assert.h>
#include "Surface.h"
#include "SpriteEffect.h"
#include "Tank.h"
#include "House.h"
#include "Alien.h"
#include "FrameTime.h"
#include "Vec2.h"
#include "Font.h"
#include "Sound.h"
#include <list>

class Game
{
public:
	Game( class MainWindow& wnd );
	~Game();
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	void RestartGame();
	void CollisionTankShot();
	void CollisionAlienShot();
	void TankGotHit();
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
public:
	static constexpr int houseCount = 5;
	static constexpr int tankShotMax = 9;
	static constexpr int startLives = 3;
	static constexpr int alienShotMax = Alien::columns;
	static constexpr int alienShotChance = 5;
	static constexpr int alienRows = Alien::columns;
	static constexpr Vec2<float> tankStartLoc = { 387.0f,495.0f };
	static constexpr Vec2<float> alienStartLoc = { 123.0f,125.0f };
	static constexpr Vec2<int> houseStartLoc = { 180,464 };
private:
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_real_distribution<float> xDist;
	std::uniform_real_distribution<float> yDist;
	const Rect<float> playSpace;
	Tank* pTank = nullptr;
	Alien* pAlien = nullptr;
	House* pHouse[houseCount] = {};
	bool gameStart = false;
	bool gameOver = false;
	bool youWon = false;
	int lives = startLives;
	int livesOld = startLives;
	unsigned int score = 0;
	unsigned int hiScore = 0;
	//Timing
	static constexpr float deathTime = 2.5f;
	FrameTime ft;
	float dt = 0.0f;
	float deathTimer = deathTime;
	//Sprites
	Surface spriteTitle = Surface( "Sprites\\SpaceInvaders399x44.bmp" );
	Surface spriteGameOver = Surface( "Sprites\\game_over84x64.bmp" );
	Surface spriteYouWon = Surface( "Sprites\\YouWin180x180.bmp" );
	Surface spriteBackground = Surface( "Sprites\\Background800x600.bmp" );
	Surface spriteExplosion{ "Sprites\\Explosion20x16.bmp" };
	//Text
	Font font = Font( "Sprites\\Text16x28.bmp" );
	const Vec2<int> scorePos = Vec2<int>( 120, 100 );
	const Vec2<int> hiScorePos = Vec2<int>( 450, 100 );
	const Vec2<int> livesPos = Vec2<int>( 122, 570 );
	// Sound
	Sound soundInvaderKilled;
	Sound soundExplosion;
	Sound soundInvader[4]{ L"Sounds\\fastinvader1.wav", L"Sounds\\fastinvader2.wav", L"Sounds\\fastinvader3.wav", L"Sounds\\fastinvader4.wav" };
	int playSoundInvader = 0;
	Sound soundUFO{ L"Sounds\\ufo_lowpitch.wav" };
	float soundUFOTime = 0.0f;
	// explosion drawing
	std::list<Vec2<int>> collisionLoc;
	std::vector<float> collisionTime;
	/********************************/
};