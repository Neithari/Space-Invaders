#pragma once

#include "Vec2.h"
#include "Dimention.h"
#include "Vec2.h"

class Rect
{
public:
	Rect() = default;
	Rect( int left_in,int right_in,int top_in,int bottom_in );
	Rect( const Vec2<int>& topLeft,const Vec2<int>& bottomRight );
	Rect( const Vec2<int>& topLeft,int width,int height );
	Rect( const Vec2<int>& topLeft,const Dimention& dim );
	Rect( const Vec2<float>& topLeft, const Dimention& dim );
	Rect( const Vec2<int>& topLeft,int cube );

	bool IsOverlappingWith( const Rect& other ) const;
	bool IsContainedBy( const Rect& other ) const;
	bool Contains( const Vec2<int>& point ) const;
	static Rect FromCenter( const Vec2<int>& center,int halfWidth,int halfHeight );
	Rect GetExpanded( int offset ) const;
	Vec2<int> GetCenter() const;
	int GetWidth() const;
	int GetHeight() const;
public:
	int left;
	int right;
	int top;
	int bottom;
};