#pragma once

#include "Graphics.h"
#include "Sprite.h"
#include "Dimention.h"
#include "Location.h"

class InvaderSmall
{
public:
	void Draw( Graphics& gfx,const Location& in_loc );
	bool IsAlive() const;
	Dimention GetDim() const;
	Location GetLoc() const;
	void Init( const Location& in_loc );
	void Collision( const Location& in_loc,const Dimention& in_dim );
private:
	static constexpr Dimention dim = { 16,16 };
	Location loc;
	bool isAlive = false;
	static constexpr int toggleTime = 60;
	int toggleIndex = 0;
	bool toggle = true;
};