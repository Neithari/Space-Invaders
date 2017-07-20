#pragma once

#include "Graphics.h"

class InvaderSmall
{
public:
	void Update();
	void Draw( Graphics& gfx ) const;
	void DrawMove( Graphics& gfx ) const;
	void DrawExplosion( Graphics& gfx ) const;

private:
	static constexpr int width = 16;
	static constexpr int height = 16;
	int x = 0;
	int y = 0;
	bool hit = false;
};