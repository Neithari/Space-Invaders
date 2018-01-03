#include "AlienShot.h"

AlienShot::AlienShot()
{
	spriteRect = Rect<int>( 0, 6, 0, 12 );
	spriteRectMove = Rect<int>( 6, 12, 0, 12 );
}

void AlienShot::Draw( Graphics & gfx )
{
	//width = 3;
	//height = 5;
	if ( isAlive )
	{
		if ( toggle )
		{
			//Shot1
			gfx.DrawSprite( int( loc.x ), int( loc.y ), spriteRect, clip, sprite, SpriteEffect::Chroma{ Colors::Magenta } );

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
			gfx.DrawSprite( int( loc.x ), int( loc.y ), spriteRectMove, sprite, SpriteEffect::Chroma{ Colors::Magenta } );

			if ( toggleIndex >= toggleTime )
			{
				toggle = true;
				toggleIndex = 0;
			}
			toggleIndex++;
		}
	}
}

void AlienShot::Init( const Vec2<float> in_loc,const Vec2<int> alienDim )
{
	if ( !isAlive )
	{
		loc = in_loc;
		loc += { float( alienDim.x ) / 2.0f - 1.0f,13 };
		isAlive = true;
	}
}

void AlienShot::Update( const float dt )
{
	if ( isAlive )
	{
		loc.y += vShot * dt;
		if ( loc.y + dim.y >= (float)clip.bottom )
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

const Vec2<float> AlienShot::GetLoc() const
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

const Vec2<int>& AlienShot::GetDim() const
{
	return dim;
}
