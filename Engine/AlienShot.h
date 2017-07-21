#pragma once

#include "Graphics.h"
#include "Location.h"
#include "Dimention.h"
#include "Tank.h"

class AlienShot
{
public:
	AlienShot();
	void Draw( Graphics& gfx );
	void Initialize( const Location in_loc );
	void Update();
	bool Colliding( const Tank& tank);

private:
	static constexpr Dimention dim = { 3,5 };
	static constexpr float screenWidth = 800.0f;
	static constexpr float screenHeight = 600.0f;
	static constexpr int toggleTime = 15;
	int toggleIndex = 0;
	float vShot = 2.0f;
	Location loc;
	bool isAlive = false;
	bool toggle = true;
};