#pragma once
#include <string.h>
#include "Graphics.h"
#include "Surface.h"
#include "Vec2.h"
#include "Rect.h"

class Font
{
public:
	Font( const std::string& filename, Color chroma = Colors::White );

	void DrawText( const std::string text, const Vec2<int>& pos, const Color& color, Graphics& gfx ) const;
private:
	Rect<int> MapGlyphRect( char c ) const;
private:
	//holds the font sheet bitmap
	Surface surface;
	//dimensions of a glyph in the font sheet
	int glyphWidth;
	int glyphHeight;
	//number of rows/columns in the font sheet
	static constexpr int nColumns = 32;
	static constexpr int nRows = 3;
	//font sheet chroma color
	Color chroma;
	//start and end drawable characters
	static constexpr char firstChar = ' ';
	static constexpr char lastChar = '~';
};