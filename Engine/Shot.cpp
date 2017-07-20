#include "Shot.h"

Shot::Shot()
{
}

Shot::Shot( const Location& in_loc )
	:
	loc( in_loc ),
	isInit( true )
{
}

void Shot::DrawAlien( Graphics& gfx )
{
	//width = 3;
	//height = 5;
	if ( isInit )
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

void Shot::DrawTank( Graphics& gfx ) const
{
	if ( isInit )
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

void Shot::Initialize( const Location& in_loc )
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

bool Shot::Colliding( const Tank& tank )
{
	Location in_loc = tank.GetLocation();
	Dimention in_dim = tank.GetDimention();
	return CollidingTank( in_loc,in_dim );
}

bool Shot::Colliding( const Alien& alien )
{
	Location in_loc = alien.GetLocation();
	Dimention in_dim = alien.GetDimention();
	return CollidingAlien( in_loc,in_dim );
}

bool Shot::CollidingAlien( const Location& objL,const Dimention& objD )
{

	const float objright = objL.x + float( objD.width );
	const float objbottom = objL.y + float( objD.height );
	const float shotright = loc.x + float( dimAlien.width );
	const float shotbottom = loc.y + float( dimAlien.height );

	return objright >= loc.x &&
		objL.x <= shotright &&
		objbottom >= loc.y &&
		objL.y <= shotbottom;
}

bool Shot::CollidingTank( const Location& objL,const Dimention& objD )
{

	const float objright = objL.x + float( objD.width );
	const float objbottom = objL.y + float( objD.height );
	const float shotright = loc.x + float( dimTank.width );
	const float shotbottom = loc.y + float( dimTank.height );

	return objright >= loc.x &&
		objL.x <= shotright &&
		objbottom >= loc.y &&
		objL.y <= shotbottom;
}