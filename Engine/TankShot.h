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
	TankShot( Vec2<float> in_loc, const Rect<float>* in_pPlaySpace );

	void Draw( Graphics& gfx ) const;
	bool Update( const float dt );
	const Vec2<float>& GetLoc() const;
	static const Vec2<int>& GetDim();
	~TankShot();
public:
	static constexpr Vec2<int> dim = { 4,8 };
private:
	const Rect<float>* pPlaySpace = nullptr;
	Surface sprite = Surface( "Sprites\\TankShell4x8.bmp" );
	float vShot = 120.0f;
	Vec2<float> loc;
};