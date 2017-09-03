#include "PixelArt.h"

PixelArt::PixelArt( Vec2 loc,std::vector<bool>& matrix )
	:
	loc( loc ),
	matrix( matrix )
{
}

void PixelArt::Draw( Vec2& drawLoc,Graphics& gfx )
{
	Rect rect( drawLoc,pixelSize );
	DrawPixel( rect,gfx );
}

void PixelArt::DrawPixel( Rect& rect,Graphics & gfx )
{
	for ( int y = rect.top; y < rect.bottom; y++ )
	{
		for ( int x = rect.left; x < rect.right; x++ )
		{
			gfx.PutPixel( x,y,c );
		}
	}
}
