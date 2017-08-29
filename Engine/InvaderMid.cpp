#include "InvaderMid.h"

void InvaderMid::Draw( Graphics& gfx,const Location& in_loc )
{
	loc = in_loc;
	if ( isAlive )
	{
		if ( toggle )
		{
			Sprite::DrawInvaderMed0( int( loc.x ),int( loc.y ),gfx );
			if ( toggleIndex >= toggleTime )
			{
				toggle = false;
				toggleIndex = 0;
			}
			toggleIndex++;
		}
		else
		{
			Sprite::DrawInvaderMed1( int( loc.x ),int( loc.y ),gfx );
			if ( toggleIndex >= toggleTime )
			{
				toggle = true;
				toggleIndex = 0;
			}
			toggleIndex++;
		}
	}
}

bool InvaderMid::IsAlive() const
{
	return isAlive;
}

Dimention InvaderMid::GetDim() const
{
	return dim;
}

Location InvaderMid::GetLoc() const
{
	return loc;
}

void InvaderMid::Init( const Location& in_loc )
{
	if ( !isAlive )
	{
		loc = in_loc;
		isAlive = true;
	}
}

void InvaderMid::Collision( const Location& in_loc,const Dimention& in_dim )
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
