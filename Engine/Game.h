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
#include "Location.h"
#include "Dimention.h"
#include <random>
#include <assert.h>
#include "Sprite.h"
#include "Tank.h"
#include "House.h"
#include "Alien.h"
#include "FrameTime.h"
#include "Vec2.h"

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
	float ClampToScreen( const Location& in_loc,const Dimention& in_dim );
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
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_real_distribution<float> xDist;
	std::uniform_real_distribution<float> yDist;
	static constexpr int houseCount = 5;
	static constexpr int tankShotMax = 30;
	static constexpr int alienShotMax = 30;
	static constexpr int alienRows = 15;
	static constexpr Location tankStartLoc = { 400.0f,500.0f };
	static constexpr Vec2 houseStartLoc = { 180,460 };
	Tank* pTank = nullptr;
	Alien* pAlien = nullptr;
	House* pHouse[houseCount] = {};
	bool gameStart = false;
	bool gameOver = false;
	bool youWon = false;
	int lives = 3;
	int livesOld = 3;
	//Timing
	static constexpr float deathTime = 2.5f;
	FrameTime ft;
	float dt = 0.0f;
	float deathTimer = deathTime;
	/********************************/
};