#pragma once

#include "Graphics.h"
#include "Dimention.h"
#include "Location.h"

class InvaderBig
{
public:
	void Update();
	void Draw( Graphics& gfx );
	bool IsAlive() const;
	Dimention GetDim() const;
	void Init( const Location& in_loc );
private:
	void DrawMove0( Graphics& gfx ) const;
	void DrawMove1( Graphics& gfx ) const;
	void DrawExplosion( Graphics& gfx ) const;
private:
	static constexpr Dimention dim = { 24,16 };
	Location loc;
	bool isAlive = false;
	static constexpr int toggleTime = 60;
	int toggleIndex = 0;
	bool toggle = true;
};