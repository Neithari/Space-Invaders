#include "TankShot.h"

TankShot::TankShot( Location in_loc )
	:
	loc( in_loc )
{
	loc += { 8,-3 };
}

void TankShot::Draw( Graphics & gfx ) const
{
	Sprite::DrawTankShot( int( loc.x ),int( loc.y ),gfx );
}

bool TankShot::Update( const float dt )
{
	loc.y -= vShot * dt;
	if ( loc.y < 0 )
	{
		return true;
	}
	else
	{
		return false;
	}
}

const Location & TankShot::GetLoc() const
{
	return loc;
}

const Dimention & TankShot::GetDim()
{
	return dim;
}
