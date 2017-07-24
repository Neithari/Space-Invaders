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

void TankShot::Update()
{
	if ( isAlive )
	{
		loc.y -= vShot;
		if ( loc.y < 0 )
		{
			isAlive = false;
		}
	}
}

bool TankShot::Colliding( const Alien & alien )
{
	if ( isAlive )
	{
		/*const Location targetLoc = alien.GetLocation();
		const Dimention targetDim = alien.GetDimention();
		const float objright = targetLoc.x + float( targetDim.width );
		const float objbottom = targetLoc.y + float( targetDim.height );
		const float shotright = loc.x + float( dim.width );
		const float shotbottom = loc.y + float( dim.height );

		return objright >= loc.x &&
			targetLoc.x <= shotright &&
			objbottom >= loc.y &&
			targetLoc.y <= shotbottom;*/
		return false;
	}
	else
	{
		return false;
	}
}

bool TankShot::IsAlive() const
{
	return isAlive;
}
