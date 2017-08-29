#include "Location.h"

Location::Location( float x_in,float y_in )
	:
	x( x_in ),
	y( y_in )
{
}

bool Location::operator==( const Location & rhs ) const
{
	return x == rhs.x && y == rhs.y;
}

Location Location::operator+( const Location& rhs ) const
{
	return Location( x + rhs.x,y + rhs.y );
}

Location& Location::operator+=( const Location& rhs )
{
	return *this = *this + rhs;
}

Location Location::operator*( float rhs ) const
{
	return Location( x * rhs,y * rhs );
}

Location& Location::operator*=( float rhs )
{
	return *this = *this * rhs;
}

Location Location::operator-( const Location& rhs ) const
{
	return Location( x - rhs.x,y - rhs.y );
}

Location& Location::operator-=( const Location& rhs )
{
	return *this = *this - rhs;
}

Location Location::operator/( float rhs ) const
{
	return Location( x / rhs,y / rhs );
}

Location& Location::operator/=( float rhs )
{
	return *this = *this / rhs;
}