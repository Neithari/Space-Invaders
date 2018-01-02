#include "Font.h"
#include <cassert>
#include "SpriteEffect.h"

Font::Font( const std::string & filename, Color chroma )
	:
	surface( filename ),
	// calculate glyph dimentions from bitmap dimentions
	glyphWidth( surface.GetWidth() / nColumns ),
	glyphHeight( surface.GetHeight() / nRows ),
	chroma( chroma )
{
	// verify that bitmap had valid dimensions
	assert( glyphWidth * nColumns == surface.GetWidth() );
	assert( glyphHeight * nRows == surface.GetHeight() );
}

void Font::DrawText( const std::string text, const Vec2<int>& pos, const Color& color, Graphics & gfx ) const
{
	// curPos is the pos that we are drawing to on the screen
	auto curPos = pos;
	for( auto c : text )
	{
		// on newline character, reset x pos and set curPos to the next line
		if( c == '\n' )
		{
			// carriage return
			curPos.x = pos.x;
			// line feed
			curPos.y += glyphHeight;
			//we don't want to advance the character position
			continue;
		}
		// only draw characters that are on the font sheet
		// firstChar + 1 because might as well skip ' '
		else if( c >= firstChar + 1 && c <= lastChar )
		{
			// use substitution to be able to change font color
			gfx.DrawSprite( curPos.x, curPos.y, MapGlyphRect( c ), surface, SpriteEffect::Substitution{ Colors::White, color } );
		}
		// advance screen pos for next character
		curPos.x += glyphWidth;
	}
}

Rect<int> Font::MapGlyphRect( char c ) const
{
	assert( c >= firstChar && c <= lastChar );
	// font sheet glyph start at ' ', calculate index into sheet
	const int glyphIndex = c - ' ';
	// map 1D glyphIndex to 2D coordinates
	const int yGlyph = glyphIndex / nColumns;
	const int xGlyph = glyphIndex % nColumns;
	// convert the sheet grid coords to pixel coords in sheet
	return Rect<int>(
		{ xGlyph * glyphWidth, yGlyph * glyphHeight },
		glyphWidth, glyphHeight );
}
