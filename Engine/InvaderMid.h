#pragma once

#include "Graphics.h"
#include "Dimention.h"
#include "Location.h"

class InvaderMid
{
public:
	void Update();
	void Draw( Graphics& gfx );
	bool IsAlive() const;
	Dimention GetDim() const;
	Location GetLoc() const;
	void Init( const Location& in_loc );
	void Collision( const Location& in_loc,const Dimention& in_dim );
	void DrawExplosion( Graphics& gfx ) const;
private:
	void DrawMove0( Graphics& gfx ) const;
	void DrawMove1( Graphics& gfx ) const;
private:
	static constexpr Dimention dim = { 20,16 };
	Location loc;
	bool isAlive = false;
	static constexpr int toggleTime = 60;
	int toggleIndex = 0;
	bool toggle = true;
};