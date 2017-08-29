#include "Dimention.h"

bool Dimention::operator==( const Dimention & rhs ) const
{
	return width == rhs.width && height == rhs.height;
}

Dimention Dimention::operator+( const Dimention& rhs ) const
{
	return Dimention( width + rhs.width,height + rhs.height );
}

Dimention& Dimention::operator+=( const Dimention& rhs )
{
	return *this = *this + rhs;
}

Dimention Dimention::operator*( int rhs ) const
{
	return Dimention( width * rhs,height * rhs );
}

Dimention& Dimention::operator*=( int rhs )
{
	return *this = *this * rhs;
}

Dimention Dimention::operator-( const Dimention& rhs ) const
{
	return Dimention( width - rhs.width,height - rhs.height );
}

Dimention& Dimention::operator-=( const Dimention& rhs )
{
	return *this = *this - rhs;
}

Dimention Dimention::operator/( int rhs ) const
{
	return Dimention( width / rhs,height / rhs );
}

Dimention& Dimention::operator/=( int rhs )
{
	return *this = *this / rhs;
}