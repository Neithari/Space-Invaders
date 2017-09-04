#include "House.h"

House::House(const Vec2& in_loc)
	:
	loc( in_loc ),
	house( loc,filename )
{
}

void House::Draw( Graphics& gfx )
{
	house.Draw( gfx );
}

bool House::Collision( Rect& rect )
{
	house.GetRect();

	return ( objright >= loc.x &&
			in_loc.x <= shotright &&
			objbottom >= loc.y &&
			in_loc.y <= shotbottom );
}
