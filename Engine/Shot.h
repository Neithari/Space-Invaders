#pragma once

#include "Graphics.h"
#include "Location.h"
#include "Dimention.h"
#include "Tank.h"
#include "Alien.h"

class Shot
{
public:
	Shot();
	Shot( const Location in_loc );
	void DrawTank( Graphics& gfx ) const;
	void DrawAlien( Graphics& gfx );
	void Initialize( const Location in_loc );
	void Update();
//	bool Colliding( const Tank& tank);
	bool Colliding( const Alien& alien );
	bool CollidingAlien( const Location& objL,const Dimention& objD );
	bool CollidingTank( const Location& objL,const Dimention& objD );
	float ClampToScreen();

private:
	static constexpr Dimention dimAlien = { 3,5 };
	static constexpr Dimention dimTank = { 2,6 };
	static constexpr float screenWidth = 800.0f;
	static constexpr float screenHeight = 600.0f;
	static constexpr int toggleTime = 15;
	int toggleIndex = 0;
	float vShot = 2.0f;
	Location loc;
	bool isInit = false;
	bool toggle = true;
	bool isColliding = false;
};