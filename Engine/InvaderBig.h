#pragma once

#include "Graphics.h"
#include "Dimention.h"
#include "Location.h"

class InvaderBig
{
public:
	void Update();
	void Draw( Graphics& gfx ) const;
	void DrawMove( Graphics& gfx ) const;
	void DrawExplosion( Graphics& gfx ) const;
private:
	static constexpr Dimention dim = { 24,16 };
	Location loc;
	bool hit = false;
};