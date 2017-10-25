#pragma once

#include "Vec2.h"
#include <string>
#include "Graphics.h"
#include "Rect.h"
#include "Matrix.h"

class PixelArt
{
public:
	PixelArt( Vec2<int>& loc, std::string filename );

	void Draw( Graphics& gfx );
	const Matrix& GetMatrix() const;
	bool Collision( const Rect<int>& obj);
private:
	void DrawPixel( Rect<int>& rect, Graphics& gfx );
	Rect<int> GetRect( int x, int y ) const;
	Rect<int> GetFullRect() const;
private:
	static constexpr int pixelSize = 1;
	std::string filename;
	Matrix matrix;
	Vec2<int> dim;
	Vec2<int> loc;
	Color c = { 255,255,255 };
};