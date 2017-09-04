#pragma once

#include "Vec2.h"
#include <string>
#include "Graphics.h"
#include "Rect.h"
#include "Matrix.h"

class PixelArt
{
public:
	PixelArt() = default;
	PixelArt( Vec2& loc,std::string filename );

	void Draw( Graphics& gfx );
private:
	void DrawPixel( Rect& rect,Graphics& gfx );
private:
	static constexpr int pixelSize = 4;
	std::string filename;
	Matrix matrix;
	Vec2 dim;
	Vec2 loc;
	Color c = {255,255,255};
};