#pragma once

#include "Vec2.h"
#include <vector>
#include "Graphics.h"
#include "Rect.h"

class PixelArt
{
public:
	PixelArt() = default;
	PixelArt( Vec2 loc,std::vector<bool>& matrix );

	void Draw( Vec2& drawLoc,Graphics& gfx );
private:
	void DrawPixel( Rect& rect,Graphics& gfx );
private:
	static constexpr int pixelSize = 4;
	Vec2 loc;
	std::vector<bool> matrix;
	Color c = {255,255,255};
};