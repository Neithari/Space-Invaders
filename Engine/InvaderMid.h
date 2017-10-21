#pragma once

#include "Graphics.h"
#include "Sprite.h"
#include "Dimention.h"
#include "Vec2.h"

class InvaderMid
{
public:
	void Draw( Graphics& gfx,const Vec2<float>& in_loc );
	bool IsAlive() const;
	Dimention GetDim() const;
	Vec2<float> GetLoc() const;
	void Init( const Vec2<float>& in_loc );
	void Collision( const Vec2<float>& in_loc,const Dimention& in_dim );
private:
	static constexpr Dimention dim = { 20,16 };
	Vec2<float> loc;
	bool isAlive = false;
	static constexpr int toggleTime = 60;
	int toggleIndex = 0;
	bool toggle = true;
};