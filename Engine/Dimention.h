#pragma once

class Dimention
{
public:
	Dimention() = default;
	constexpr Dimention( int width_in,int height_in )
		:
		width( width_in ),
		height( height_in )
	{};

	bool operator==( const Dimention& rhs ) const;
	Dimention operator+( const Dimention& rhs ) const;
	Dimention& operator+=( const Dimention& rhs );
	Dimention operator*( int rhs ) const;
	Dimention& operator*=( int rhs );
	Dimention operator-( const Dimention& rhs ) const;
	Dimention& operator-=( const Dimention& rhs );
	Dimention operator/( int rhs ) const;
	Dimention& operator/=( int rhs );
public:
	int width;
	int height;
};