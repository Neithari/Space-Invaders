#include "UFO.h"

#include "Game.h"
#include <assert.h>

UFO::UFO( const Rect<int>& in_playSpace )
	:
	loc( Graphics::ScreenWidth - Game::alienStartLoc.x - 7, Game::alienStartLoc.y ),
	playSpace( in_playSpace )
{
}

bool UFO::Collision( const Rect<float>& other )
{
	return Rect<float>( loc, dim.x, dim.y ).IsOverlappingWith( other );
}

bool UFO::Update( const float dt )
{
	moveTime += dt;
	if( moveTime >= 0.01f )
	{
		loc.x -= speed;
		moveTime = 0.0f;
	}
	return loc.x + dim.x < playSpace.left;
}

void UFO::Draw( Graphics & gfx  )
{
	gfx.DrawSprite( int( loc.x ), int( loc.y ), spriteUFO.GetRect(), playSpace, spriteUFO, SpriteEffect::Chroma{ Colors::Magenta } );
}

const Vec2<float>& UFO::GetLoc() const
{
	return loc;
}
