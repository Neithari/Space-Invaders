#pragma once

#include "Graphics.h"
#include "Surface.h"
#include "SpriteEffect.h"
#include "Vec2.h"

class UFO
{
public:
	UFO( const Rect<int>& in_playSpace );
	bool Collision( const Rect<float>& other );
	bool Update( const float dt );
	void Draw( Graphics& gfx );
	const Vec2<float>& GetLoc() const;
public:
	static constexpr Vec2<int> dim{ 30, 14 };
private:
	Vec2<float> loc;
	float speed = 2.0f;
	float moveTime = 0.0f;
	Surface spriteUFO{ "Sprites\\UFO30x14.bmp" };
	const Rect<int> playSpace;
};