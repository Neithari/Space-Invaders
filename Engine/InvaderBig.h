#pragma once

#include "Graphics.h"
#include "Sprite.h"
#include "Vec2.h"

class InvaderBig
{
public:
	void Draw( Graphics& gfx,const Vec2<float>& in_loc );
	bool IsAlive() const;
	Vec2<int> GetDim() const;
	Vec2<float> GetLoc() const;
	void Init( const Vec2<float>& in_loc );
	void Collision( const Vec2<float>& in_loc,const Vec2<int>& in_dim );
private:
	static constexpr Vec2<int> dim = { 24,16 };
	Vec2<float> loc;
	bool isAlive = false;
	static constexpr int toggleTime = 60;
	int toggleIndex = 0;
	bool toggle = true;
};