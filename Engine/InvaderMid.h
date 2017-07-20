#pragma once

#include "Graphics.h"
#include "Dimention.h"
#include "Location.h"

class InvaderMid
{
public:
	void Update();
	void Draw( Graphics& gfx ) const;
	void DrawMove( Graphics& gfx ) const;
	void DrawExplosion( Graphics& gfx ) const;

private:
	static constexpr Dimention dim = { 20,16 };
	Location loc;
	bool hit = false;
};