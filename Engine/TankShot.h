#pragma once

#include "Graphics.h"
#include "Sprite.h"
#include "Location.h"
#include "Dimention.h"
#include "Rect.h"

class TankShot
{
public:
	TankShot( Location in_loc );

	void Draw( Graphics& gfx ) const;
	bool Update( const float dt );
	const Location& GetLoc() const;
	static const Dimention& GetDim();
private:
	static constexpr Dimention dim = { 2,6 };
	static constexpr float screenWidth = 800.0f;
	static constexpr float screenHeight = 600.0f;
	float vShot = 120.0f;
	Location loc;
};