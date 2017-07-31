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
	void Update( const float dt );
	//bool Colliding( const Alien& alien);
	bool IsAlive() const;
	const Location& GetLoc() const;
	const Dimention& GetDim() const;
	void Kill();

private:
	static constexpr Dimention dim = { 2,6 };
	static constexpr float screenWidth = 800.0f;
	static constexpr float screenHeight = 600.0f;
	float vShot = 120.0f;
	Location loc;
	bool isAlive = false;
};