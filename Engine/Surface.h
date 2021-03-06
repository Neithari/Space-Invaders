#pragma once

#include <fstream>
#include <cassert>
#include "Colors.h"
#include "Vec2.h"
#include "Rect.h"

class Surface
{
public:
	Surface( const std::string& filename );
	Surface( int width, int height );
	Surface( const Surface& rhs );
	~Surface();
	Surface& operator=( const Surface& rhs );
	void PutPixel( int x, int y, Color c );
	Color GetPixel( int x, int y ) const;
	int GetWidth() const;
	int GetHeight() const;
	Vec2<int> GetDim() const;
	Rect<int> GetRect() const;
private:
	Color* pPixels = nullptr;
	int width;
	int height;
};