#include "House.h"

House::House( const Location& in_loc )
	:
	loc( in_loc )
{
}

Dimention House::GetDimention() const
{
	return dim;
}

Location House::GetLocation() const
{
	return loc;
}

void House::Draw( Graphics & gfx )
{
	//width = 40;
	//height = 30;
	int x = int( loc.x );
	int y = int( loc.y );
	Sprite::DrawHouse( x,y,gfx );
}