#pragma once

#include "Graphics.h"
#include "Dimention.h"
#include "Location.h"

class InvaderMid
{
public:
	void Update();
	void Draw( Graphics& gfx );
	void DrawMove0( Graphics& gfx ) const;
	void DrawMove1( Graphics& gfx ) const;
	void DrawExplosion( Graphics& gfx ) const;
	bool IsAlive() const;
private:
	static constexpr Dimention dim = { 20,16 };
	Location loc;
	bool isAlive = true;
	static constexpr int toggleTime = 60;
	int toggleIndex = 0;
	bool toggle = true;
};