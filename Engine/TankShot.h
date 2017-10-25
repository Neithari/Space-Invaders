#pragma once

#include "Graphics.h"
#include "SpriteEffect.h"
#include "Surface.h"
#include "Vec2.h"
#include "Vec2.h"
#include "Rect.h"

class TankShot
{
public:
	TankShot( Vec2<float> in_loc );

	void Draw( Graphics& gfx ) const;
	bool Update( const float dt );
	const Vec2<float>& GetLoc() const;
	static const Vec2<int>& GetDim();
private:
	static constexpr Vec2<int> dim = { 4,8 };
	Surface sprite = Surface( "Sprites\\TankShell4x8.bmp" );
	float vShot = 120.0f;
	Vec2<float> loc;
};