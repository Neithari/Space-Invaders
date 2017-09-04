#include "PixelArt.h"

PixelArt::PixelArt( Vec2& loc,std::string filename )
	:
	filename( filename ),
	matrix( filename ),
	dim( matrix.dim ),
	loc( loc )
{
}

void PixelArt::Draw( Graphics& gfx )
{
	Vec2 mLoc = loc;
	for ( int y = 0; y < matrix.dim.y; y++ )
	{
		for ( int x = 0; x < matrix.dim.x; x++ )
		{
			if ( matrix.matrix[y*matrix.dim.x + x] )
			{
				Rect rect( mLoc,pixelSize );
				DrawPixel( rect,gfx );
			}
			mLoc.x += pixelSize;
		}
		mLoc.x = loc.x;
		mLoc.y += pixelSize;
	}
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
