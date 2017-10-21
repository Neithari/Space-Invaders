#pragma once

#include "Graphics.h"
#include "Sprite.h"
#include "Vec2.h"
#include "Dimention.h"

class AlienShot
{
public:
	AlienShot();
	void Draw( Graphics& gfx );
	void Init( const Vec2<float> in_loc,const Dimention in_dim );
	void Update( const float dt );
	//bool Colliding( const Tank& tank);
	bool IsAlive() const;
	void Kill();
	const Vec2<float> GetLoc() const;
	const Dimention& GetDim() const;

private:
	static constexpr Dimention dim = { 3,5 };
	static constexpr float screenWidth = 800.0f;
	static constexpr float screenHeight = 600.0f;
	static constexpr int toggleTime = 15;
	int toggleIndex = 0;
	float vShot = 120.0f;
	Vec2<float> loc;
	bool isAlive = false;
	bool toggle = true;
};