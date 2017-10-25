#include "InvaderMid.h"

void InvaderMid::Draw( Graphics& gfx,const Vec2<float>& in_loc )
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

Vec2<int> InvaderMid::GetDim() const
{
	return dim;
}

Vec2<float> InvaderMid::GetLoc() const
{
	return loc;
}

void InvaderMid::Init( const Vec2<float>& in_loc )
{
	if ( !isAlive )
	{
		loc = in_loc;
		isAlive = true;
	}
}

void InvaderMid::Collision( const Vec2<float>& in_loc,const Vec2<int>& in_dim )
{
	if ( isAlive )
	{
		const float objright = in_loc.x + float( in_dim.x );
		const float objbottom = in_loc.y + float( in_dim.y );
		const float shotright = loc.x + float( dim.x );
		const float shotbottom = loc.y + float( dim.y );

		if ( objright >= loc.x &&
			in_loc.x <= shotright &&
			objbottom >= loc.y &&
			in_loc.y <= shotbottom )
		{
			isAlive = false;
		}
	}
}
