#include "Rect.h"

Rect::Rect( int left_in,int right_in,int top_in,int bottom_in )
	:
	left( left_in ),
	right( right_in ),
	top( top_in ),
	bottom( bottom_in )
{
}

Rect::Rect( const Vec2<int>& topLeft,const Vec2<int> & bottomRight )
	:
	Rect( topLeft.x,bottomRight.x,topLeft.y,bottomRight.y )
{
}

Rect::Rect( const Vec2<int>& topLeft,int width,int height )
	:
	Rect( topLeft,topLeft + Vec2<int>( width,height ) )
{
}

Rect::Rect( const Vec2<int>& topLeft,const Dimention & dim )
	:
	Rect( topLeft,Vec2<int>( dim.width,dim.height ) )
{
}

Rect::Rect( const Vec2<float> & topLeft, const Dimention & dim )
	:
	Rect( Vec2<int>( int( topLeft.x ), int( topLeft.y ) ), dim.width, dim.height )
{
}

Rect::Rect( const Vec2<int>& topLeft,int cube )
	:
	Rect( topLeft,cube,cube )
{
}

bool Rect::IsOverlappingWith( const Rect& other ) const
{
	return right > other.left && left < other.right
		&& bottom > other.top && top < other.bottom;
}

bool Rect::IsContainedBy( const Rect & other ) const
{
	return left >= other.left && right <= other.right &&
		top >= other.top && bottom <= other.bottom;
}

bool Rect::Contains( const Vec2<int>& point ) const
{
	return point.x >= left && point.x < right && point.y >= top && point.y < bottom;
}

Rect Rect::FromCenter( const Vec2<int> & center,int halfWidth,int halfHeight )
{
	const Vec2<int> half( halfWidth,halfHeight );
	return Rect( center - half,center + half );
}

Rect Rect::GetExpanded( int offset ) const
{
	return Rect( left - offset,right + offset,top - offset,bottom + offset );
}

Vec2<int> Rect::GetCenter() const
{
	return Vec2<int>( (left + right) / 2,(top + bottom) / 2 );
}

int Rect::GetWidth() const
{
	return right - left;
}

int Rect::GetHeight() const
{
	return bottom - top;
}
