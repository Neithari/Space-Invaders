#include "TankShot.h"

TankShot::TankShot()
{
}

void TankShot::Draw( Graphics & gfx ) const
{
	if ( isAlive )
	{
		int x = int( loc.x );
		int y = int( loc.y );
		//width = 2;
		//height = 6;

		gfx.PutPixel( 0 + x,0 + y,254,0,0 );
		gfx.PutPixel( 1 + x,0 + y,254,0,0 );
		gfx.PutPixel( 0 + x,1 + y,186,4,4 );
		gfx.PutPixel( 1 + x,1 + y,186,4,4 );
		gfx.PutPixel( 0 + x,2 + y,137,2,2 );
		gfx.PutPixel( 1 + x,2 + y,137,2,2 );
		gfx.PutPixel( 0 + x,3 + y,104,1,1 );
		gfx.PutPixel( 1 + x,3 + y,104,1,1 );
		gfx.PutPixel( 0 + x,4 + y,79,1,1 );
		gfx.PutPixel( 1 + x,4 + y,79,1,1 );
		gfx.PutPixel( 0 + x,5 + y,46,0,0 );
		gfx.PutPixel( 1 + x,5 + y,46,0,0 );
	}
}

void TankShot::Init( const Location & in_loc )
{
	if ( !isAlive )
	{
		loc = in_loc;
		loc.Add( { 8,-3 } );
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
