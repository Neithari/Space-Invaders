#pragma once

#include "Graphics.h"
#include "Location.h"
#include "Dimention.h"

class TankShot
{
public:
	TankShot();
	void Draw( Graphics& gfx ) const;
	void Init( const Location& in_loc );
	void Update();
	//bool Colliding( const Alien& alien);
	bool IsAlive() const;

private:
	static constexpr Dimention dim = { 2,6 };
	static constexpr float screenWidth = 800.0f;
	static constexpr float screenHeight = 600.0f;
	float vShot = 2.0f;
	Location loc;
	bool isAlive = false;
};