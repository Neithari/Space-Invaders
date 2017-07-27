#include "AlienShot.h"

AlienShot::AlienShot()
{
}

void AlienShot::Draw( Graphics & gfx )
{
	//width = 3;
	//height = 5;
	if ( isAlive )
	{
		int x = int( loc.x );
		int y = int( loc.y );

		if ( toggle )
		{
			//Shot1
			gfx.PutPixel( 1 + x,0 + y,1,131,111 );
			gfx.PutPixel( 2 + x,1 + y,1,163,138 );
			gfx.PutPixel( 1 + x,2 + y,1,191,162 );
			gfx.PutPixel( 0 + x,3 + y,1,221,187 );
			gfx.PutPixel( 1 + x,4 + y,0,255,216 );

			if ( toggleIndex >= toggleTime )
			{
				toggle = false;
				toggleIndex = 0;
			}
			toggleIndex++;
		}
		else
		{
			//Shot2
			gfx.PutPixel( 1 + x,0 + y,1,131,111 );
			gfx.PutPixel( 0 + x,1 + y,1,163,138 );
			gfx.PutPixel( 1 + x,2 + y,1,191,162 );
			gfx.PutPixel( 2 + x,3 + y,1,221,187 );
			gfx.PutPixel( 1 + x,4 + y,0,255,216 );

			if ( toggleIndex >= toggleTime )
			{
				toggle = true;
				toggleIndex = 0;
			}
			toggleIndex++;
		}
	}
}

void AlienShot::Init( const Location in_loc,const Dimention in_dim )
{
	if ( !isAlive )
	{
		loc = in_loc;
		loc.Add( { float(in_dim.width)/2.0f-1.0f,13 } );
		isAlive = true;
	}
}

void AlienShot::Update()
{
	if ( isAlive )
	{
		loc.y += vShot;
		if ( loc.y + dim.height >= screenHeight )
		{
			isAlive = false;
		}
	}
}

/*bool AlienShot::Colliding( const Tank & tank )
{
	if ( isAlive )
	{
		const Location targetLoc = tank.GetLocation();
		const Dimention targetDim = tank.GetDimention();
		const float objright = targetLoc.x + float( targetDim.width );
		const float objbottom = targetLoc.y + float( targetDim.height );
		const float shotright = loc.x + float( dim.width );
		const float shotbottom = loc.y + float( dim.height );

		return objright >= loc.x &&
			targetLoc.x <= shotright &&
			objbottom >= loc.y &&
			targetLoc.y <= shotbottom;
	}
	else
	{
		return false;
	}
}*/

bool AlienShot::IsAlive() const
{
	return isAlive;
}

void AlienShot::Kill()
{
	isAlive = false;
}

const Location AlienShot::GetLoc() const
{
	if ( isAlive )
	{
		return loc;
	}
	else
	{
		return { 0,0 };
	}
}

const Dimention & AlienShot::GetDim() const
{
	return dim;
}
