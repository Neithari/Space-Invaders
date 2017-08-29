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
			Sprite::DrawAlienShot1( x,y,gfx );

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
			Sprite::DrawAlienShot2( x,y,gfx );

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
		loc += { float( in_dim.width ) / 2.0f - 1.0f,13 };
		isAlive = true;
	}
}

void AlienShot::Update( const float dt )
{
	if ( isAlive )
	{
		loc.y += vShot * dt;
		if ( loc.y + dim.height >= screenHeight )
		{
			isAlive = false;
		}
	}
}

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
