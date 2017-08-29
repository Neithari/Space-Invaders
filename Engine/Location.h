#pragma once

class Location
{
public:
	Location() = default;
	Location( float x_in,float y_in );

	bool operator==( const Location& rhs ) const;
	Location operator+( const Location& rhs ) const;
	Location& operator+=( const Location& rhs );
	Location operator*( float rhs ) const;
	Location& operator*=( float rhs );
	Location operator-( const Location& rhs ) const;
	Location& operator-=( const Location& rhs );
	Location operator/( float rhs ) const;
	Location& operator/=( float rhs );
public:
	float x;
	float y;
};