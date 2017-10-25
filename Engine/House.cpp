#include "House.h"

House::House(const Vec2<int>& in_loc)
	:
	loc( in_loc ),
	house( loc,filename )
{
}

void House::Draw( Graphics& gfx )
{
	house.Draw( gfx );
}

bool House::IsColliding( const Rect<int>& obj )
{
	return house.Collision( obj );
}
