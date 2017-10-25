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

void Invader::Collision( const Vec2<float>& in_loc, const Vec2<int>& in_dim )
{
	if( isAlive )
	{
		const float objright = in_loc.x + float( in_dim.x );
		const float objbottom = in_loc.y + float( in_dim.y );
		const float shotright = loc.x + float( dim.x );
		const float shotbottom = loc.y + float( dim.y );

		if( objright >= loc.x &&
			in_loc.x <= shotright &&
			objbottom >= loc.y &&
			in_loc.y <= shotbottom )
		{
			isAlive = false;
		}
	}
}
