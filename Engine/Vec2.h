#pragma once

#include <cmath>

template<typename T>
class Vec2
{
public:
	Vec2() = default;
	Vec2( T x_in,T y_in )
		:
		x( x_in ),
		y( y_in )
	{}
	template<typename C>
	explicit Vec2( const Vec2<C>& cvec )
		:
		x( (T)cvec.x ),
		y( (T)cvec.y )
	{}

	bool operator==( const Vec2 & rhs ) const
	{
		return x == rhs.x && y == rhs.y;
	}

	Vec2 operator+( const Vec2& rhs ) const
	{
		return Vec2( x + rhs.x, y + rhs.y );
	}

	Vec2& operator+=( const Vec2& rhs )
	{
		return *this = *this + rhs;
	}

	Vec2 operator*( T rhs ) const
	{
		return Vec2( x * rhs, y * rhs );
	}

	Vec2& operator*=( T rhs )
	{
		return *this = *this * rhs;
	}

	Vec2 operator-( const Vec2& rhs ) const
	{
		return Vec2( x - rhs.x, y - rhs.y );
	}

	Vec2& operator-=( const Vec2& rhs )
	{
		return *this = *this - rhs;
	}

	Vec2 operator/( T rhs ) const
	{
		return Vec2( x / rhs, y / rhs );
	}

	Vec2& operator/=( T rhs )
	{
		return *this = *this / rhs;
	}

	T GetLength() const
	{
		return (T)std::sqrt( GetLengthSq() );
	}

	T GetLengthSq() const
	{
		return x * x + y * y;
	}
public:
	T x;
	T y;
};