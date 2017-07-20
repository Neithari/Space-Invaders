#pragma once

#include "Graphics.h"

class InvaderMid
{
public:
	void Update();
	void Draw( Graphics& gfx ) const;
	void DrawMove( Graphics& gfx ) const;
	void DrawExplosion( Graphics& gfx ) const;

private:
	static constexpr int width = 20;
	static constexpr int height = 16;
	int x;
	int y;
	bool hit = false;
};