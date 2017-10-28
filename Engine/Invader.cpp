#include "Invader.h"

Invader::Invader( const Vec2<float>& in_loc, InvaderType type )
	:
	loc( in_loc ),
	isAlive( true ),
	iType( type )
{
	int y = 0;
	switch( iType )
	{
	case InvaderType::InvaderSmall:
		dim = dimSmall;
		y = 36;
		break;
	case InvaderType::InvaderMid:
		dim = dimMid;
		y = 18;
		break;
	case InvaderType::InvaderBig:
		dim = dimBig;
		y = 0;
		break;
	}
	spriteRect = Rect<int>( 0, 26, y, y + 18 );
	spriteRectMove = Rect<int>( 26, 52, y, y + 18 );
}

void Invader::Draw( Graphics& gfx, const Vec2<float>& in_loc )
{
	loc = in_loc;
	if( isAlive )
	{
		if( toggle )
		{
			gfx.DrawSprite( int( loc.x ), int( loc.y ), spriteRect, sprite, SpriteEffect::Chroma{ Colors::Magenta } );
			if( toggleIndex >= toggleTime )
			{
				toggle = false;
				toggleIndex = 0;
			}
			toggleIndex++;
		}
		else
		{
			gfx.DrawSprite( int( loc.x ), int( loc.y ), spriteRectMove, sprite, SpriteEffect::Chroma{ Colors::Magenta } );
			if( toggleIndex >= toggleTime )
			{
				toggle = true;
				toggleIndex = 0;
			}
			toggleIndex++;
		}
	}
}

bool Invader::IsAlive() const
{
	return isAlive;
}

Vec2<int> Invader::GetDim() const
{
	return dim;
}

Vec2<float> Invader::GetLoc() const
{
	return loc;
}

Rect<float> Invader::GetRect() const
{
	return Rect<float>( loc, dim.x , dim.y );
}

bool Invader::Collision( const Vec2<float>& in_loc, const Vec2<int>& in_dim )
{
	return Collision( Rect<float>( in_loc, in_dim.x, in_dim.y ) );
}

bool Invader::Collision( const Rect<float>& other )
{
	if( isAlive )
	{
		if( GetRect().IsOverlappingWith( other ) )
		{
			isAlive = false;
			return true;
		}
	}
	return false;
}
