#pragma once

#include "Graphics.h"
#include "Surface.h"
#include "SpriteEffect.h"
#include "Vec2.h"

class AlienShot
{
public:
	AlienShot();
	void Draw( Graphics& gfx );
	void Init( const Vec2<float> in_loc,const Vec2<int> alienDim );
	void Update( const float dt );
	//bool Colliding( const Tank& tank);
	bool IsAlive() const;
	void Kill();
	const Vec2<float> GetLoc() const;
	const Vec2<int>& GetDim() const;

private:
	static constexpr Vec2<int> dim = { 6,12 };
	const Rect<int> clip = { 0,Graphics::ScreenWidth,0, 510 };
	static constexpr int toggleTime = 15;
	Surface sprite = Surface( "Sprites\\AlienShot6x12.bmp" );
	int toggleIndex = 0;
	float vShot = 120.0f;
	Vec2<float> loc;
	bool isAlive = false;
	bool toggle = true;
	Rect<int> spriteRect;
	Rect<int> spriteRectMove;
};