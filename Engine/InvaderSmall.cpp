#include "InvaderSmall.h"

void InvaderSmall::Draw( Graphics& gfx,const Location& in_loc )
{
	loc = in_loc;
	if ( isAlive )
	{
		if ( toggle )
		{
			Sprite::DrawInvaderSmall0( int( loc.x ),int( loc.y ),gfx );
			if ( toggleIndex >= toggleTime )
			{
				toggle = false;
				toggleIndex = 0;
			}
			toggleIndex++;
		}
		else
		{
			Sprite::DrawInvaderSmall1( int( loc.x ),int( loc.y ),gfx );
			if ( toggleIndex >= toggleTime )
			{
				toggle = true;
				toggleIndex = 0;
			}
			toggleIndex++;
		}
	}
}

bool InvaderSmall::IsAlive() const
{
	return isAlive;
}

Dimention InvaderSmall::GetDim() const
{
	return dim;
}

Location InvaderSmall::GetLoc() const
{
	return loc;
}

void InvaderSmall::Init( const Location& in_loc )
{
	if ( !isAlive )
	{
		loc = in_loc;
		isAlive = true;
	}
}

void InvaderSmall::Collision( const Location& in_loc,const Dimention& in_dim )
{
	if ( isAlive )
	{
		const float objright = in_loc.x + float( in_dim.width );
		const float objbottom = in_loc.y + float( in_dim.height );
		const float shotright = loc.x + float( dim.width );
		const float shotbottom = loc.y + float( dim.height );

		if ( objright >= loc.x &&
			in_loc.x <= shotright &&
			objbottom >= loc.y &&
			in_loc.y <= shotbottom )
		{
			isAlive = false;
		}
	}
}
