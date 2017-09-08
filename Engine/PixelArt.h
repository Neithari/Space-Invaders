#pragma once

#include "Vec2.h"
#include <string>
#include "Graphics.h"
#include "Rect.h"
#include "Matrix.h"

class PixelArt
{
public:
	PixelArt( Vec2& loc, std::string filename );

	void Draw( Graphics& gfx );
	const Matrix& GetMatrix() const;
	bool Collision( const Rect& obj);
private:
	void DrawPixel( Rect& rect, Graphics& gfx );
	Rect GetRect( int x, int y ) const;
	Rect GetFullRect() const;
private:
	static constexpr int pixelSize = 1;
	std::string filename;
	Matrix matrix;
	Vec2 dim;
	Vec2 loc;
	Color c = { 255,255,255 };
};