#include "TankShot.h"

TankShot::TankShot()
{
}

void TankShot::Draw( Graphics & gfx ) const
{
	if ( isAlive )
	{
		Sprite::DrawTankShot( int( loc.x ),int( loc.y ),gfx );
	}
}

void TankShot::Init( const Location & in_loc )
{
	if ( !isAlive )
	{
		loc = in_loc;
		loc += { 8,-3 };
		isAlive = true;
	}
}

void TankShot::Update( const float dt )
{
	if ( isAlive )
	{
		loc.y -= vShot * dt;
		if ( loc.y < 0 )
		{
			isAlive = false;
		}
	}
}

bool TankShot::IsAlive() const
{
	return isAlive;
}

const Location & TankShot::GetLoc() const
{
	return loc;
}

const Dimention & TankShot::GetDim() const
{
	return dim;
}

void TankShot::Kill()
{
	isAlive = false;
}
