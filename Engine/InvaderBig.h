#pragma once

#include "Graphics.h"

class InvaderBig
{
public:
	void Update();
	void Draw( Graphics& gfx ) const;
	void DrawMove( Graphics& gfx ) const;
	void DrawExplosion( Graphics& gfx ) const;

	static constexpr int width = 24;
	static constexpr int height = 16;
	int x;
	int y;
	bool hit = false;
};