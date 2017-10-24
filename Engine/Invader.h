#pragma once

#include "Graphics.h"
#include "Surface.h"
#include "SpriteEffect.h"
#include "Vec2.h"

class Invader
{
public:
	enum class InvaderType
	{
		InvaderSmall,
		InvaderMid,
		InvaderBig
	};
public:
	Invader( const Vec2<float>& in_loc, InvaderType type );
	void Draw( Graphics& gfx, const Vec2<float>& in_loc );
	bool IsAlive() const;
	Vec2<int> GetDim() const;
	Vec2<float> GetLoc() const;
	void Collision( const Vec2<float>& in_loc, const Vec2<int>& in_dim );
private:
	Vec2<int> dim;
	Vec2<float> loc;
	bool isAlive = true;
	static constexpr int toggleTime = 60;
	int toggleIndex = 0;
	bool toggle = true;
	Surface sprite = Surface( "Sprites\\Aliens26x18.bmp" );
	InvaderType iType;
	Rect<int> spriteRect;
	Rect<int> spriteRectMove;
};