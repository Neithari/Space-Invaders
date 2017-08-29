#include "Dimention.h"

bool Dimention::operator==( const Dimention & rhs ) const
{
	return width == rhs.width && height == rhs.height;
}