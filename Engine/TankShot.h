#pragma once

#include "Graphics.h"
#include "Sprite.h"
#include "Vec2.h"
#include "Dimention.h"
#include "Rect.h"

class TankShot
{
public:
	TankShot( Vec2<float> in_loc );

	void Draw( Graphics& gfx ) const;
	bool Update( const float dt );
	const Vec2<float>& GetLoc() const;
	static const Dimention& GetDim();
private:
	static constexpr Dimention dim = { 2,6 };
	static constexpr float screenWidth = 800.0f;
	static constexpr float screenHeight = 600.0f;
	float vShot = 120.0f;
	Vec2<float> loc;
};