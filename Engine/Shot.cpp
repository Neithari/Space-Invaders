#include "Shot.h"

Shot::Shot()
{
}

Shot::Shot( const Location & in_loc )
	:
	loc( in_loc ),
	isInit( true )
{
}

void Shot::DrawAlien( Graphics & gfx )
{
	//width = 3;
	//height = 5;
	if ( isInit )
	{
		if ( toggle )
		{
			//Shot1
			gfx.PutPixel( 1 + loc.x,0 + loc.y,1,131,111 );
			gfx.PutPixel( 2 + loc.x,1 + loc.y,1,163,138 );
			gfx.PutPixel( 1 + loc.x,2 + loc.y,1,191,162 );
			gfx.PutPixel( 0 + loc.x,3 + loc.y,1,221,187 );
			gfx.PutPixel( 1 + loc.x,4 + loc.y,0,255,216 );

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
			gfx.PutPixel( 1 + loc.x,0 + loc.y,1,131,111 );
			gfx.PutPixel( 0 + loc.x,1 + loc.y,1,163,138 );
			gfx.PutPixel( 1 + loc.x,2 + loc.y,1,191,162 );
			gfx.PutPixel( 2 + loc.x,3 + loc.y,1,221,187 );
			gfx.PutPixel( 1 + loc.x,4 + loc.y,0,255,216 );

			if ( toggleIndex >= toggleTime )
			{
				toggle = true;
				toggleIndex = 0;
			}
			toggleIndex++;
		}
	}
}

void Shot::DrawTank( Graphics & gfx ) const
{
	if ( isInit )
	{
		//width = 2;
		//height = 6;

		gfx.PutPixel( 0 + loc.x,0 + loc.y,254,0,0 );
		gfx.PutPixel( 1 + loc.x,0 + loc.y,254,0,0 );
		gfx.PutPixel( 0 + loc.x,1 + loc.y,186,4,4 );
		gfx.PutPixel( 1 + loc.x,1 + loc.y,186,4,4 );
		gfx.PutPixel( 0 + loc.x,2 + loc.y,137,2,2 );
		gfx.PutPixel( 1 + loc.x,2 + loc.y,137,2,2 );
		gfx.PutPixel( 0 + loc.x,3 + loc.y,104,1,1 );
		gfx.PutPixel( 1 + loc.x,3 + loc.y,104,1,1 );
		gfx.PutPixel( 0 + loc.x,4 + loc.y,79,1,1 );
		gfx.PutPixel( 1 + loc.x,4 + loc.y,79,1,1 );
		gfx.PutPixel( 0 + loc.x,5 + loc.y,46,0,0 );
		gfx.PutPixel( 1 + loc.x,5 + loc.y,46,0,0 );
	}
}

void Shot::Initialize( const Location & in_loc )
{
	if ( !isInit )
	{
		loc = in_loc;
	}
	isInit = true;
}

void Shot::Update()
{
}

bool Shot::Colliding( const Location & objL,const Dimention & objD )
{
	const int objright = objL.x + objD.width;
	const int objbottom = objL.y + objD.height;
	const int shotright = loc.x + dim.width;
	const int shotbottom = loc.y + dim.height;

	return objright >= loc.x &&
		objL.x <= shotright &&
		objbottom >= loc.y &&
		objL.y <= shotbottom;
}
