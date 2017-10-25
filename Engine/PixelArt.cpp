#include "PixelArt.h"

PixelArt::PixelArt( Vec2<int>& loc,std::string filename )
	:
	filename( filename ),
	matrix( filename ),
	dim( matrix.dim ),
	loc( loc )
{
}

void PixelArt::Draw( Graphics& gfx )
{
	Vec2<int> mLoc = loc;
	for( int y = 0; y < matrix.dim.y; y++ )
	{
		for( int x = 0; x < matrix.dim.x; x++ )
		{
			if( matrix.matrix[matrix.Index(x, y)] )
			{
				DrawPixel( Rect<int>( mLoc, pixelSize ), gfx );
			}
			mLoc.x += pixelSize;
		}
		mLoc.x = loc.x;
		mLoc.y += pixelSize;
	}
}

const Matrix& PixelArt::GetMatrix() const
{
	return matrix;
}

bool PixelArt::Collision( const Rect<int>& obj )
{
	//check if it's a hit in general
	if( GetFullRect().IsOverlappingWith( obj ) )
	{
		//check each item
		bool collided = false;
		for( int y = 0; y < dim.y; y++ )
		{
			for( int x = 0; x < dim.x; x++ )
			{
				//check if there is an element
				if( matrix.matrix[matrix.Index( x, y )] )
				{
					//check if position is colliding with the object
					if( Rect<int>( Vec2<int>( loc.x + x, loc.y + y ), pixelSize ).IsOverlappingWith( obj ) )
					{
						collided = true;
						matrix.setFalse( x, y );
					}
				}
			}
		}
		return collided;
	}
	else
	{
		return false;
	}
}

void PixelArt::DrawPixel( Rect<int>& rect,Graphics & gfx )
{
	for( int y = rect.top; y < rect.bottom; y++ )
	{
		for( int x = rect.left; x < rect.right; x++ )
		{
			gfx.PutPixel( x,y,c );
		}
	}
}

Rect<int> PixelArt::GetRect( int x, int y ) const
{
	return Rect<int>( Vec2<int>( x,y ), pixelSize );
}

Rect<int> PixelArt::GetFullRect() const
{
	int width = dim.x;
	int height = dim.y;
	return Rect<int>( loc, width, height );
}
