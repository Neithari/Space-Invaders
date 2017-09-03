#include "Vec2.h"
#include <cmath>

bool Vec2::operator==( const Vec2 & rhs ) const
{
	return x == rhs.x && y == rhs.y;
}

Vec2 Vec2::operator+( const Vec2& rhs ) const
{
	return Vec2( x + rhs.x,y + rhs.y );
}

Vec2& Vec2::operator+=( const Vec2& rhs )
{
	return *this = *this + rhs;
}

Vec2 Vec2::operator*( int rhs ) const
{
	return Vec2( x * rhs,y * rhs );
}

Vec2& Vec2::operator*=( int rhs )
{
	return *this = *this * rhs;
}

Vec2 Vec2::operator-( const Vec2& rhs ) const
{
	return Vec2( x - rhs.x,y - rhs.y );
}

Vec2& Vec2::operator-=( const Vec2& rhs )
{
	return *this = *this - rhs;
}

Vec2 Vec2::operator/( int rhs ) const
{
	return Vec2( x / rhs,y / rhs );
}

Vec2& Vec2::operator/=( int rhs )
{
	return *this = *this / rhs;
}

float Vec2::GetLength() const
{
	return std::sqrt( float( GetLengthSq() ) );
}

int Vec2::GetLengthSq() const
{
	return x * x + y * y;
}