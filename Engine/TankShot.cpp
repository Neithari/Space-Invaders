#include "TankShot.h"

TankShot::TankShot( Vec2<float> in_loc, const Rect<float>* in_pPlaySpace )
	:
	loc( in_loc ),
	pPlaySpace( in_pPlaySpace )
{
	loc += { 8,-3 };
}

void TankShot::Draw( Graphics & gfx ) const
{
	gfx.DrawSprite( (int)loc.x, (int)loc.y, sprite, SpriteEffect::Chroma{ Colors::Magenta } );
}

bool TankShot::Update( const float dt )
{
	loc.y -= vShot * dt;
	return loc.y < pPlaySpace->top;
}

const Vec2<float> & TankShot::GetLoc() const
{
	return loc;
}

const Vec2<int>& TankShot::GetDim()
{
	return dim;
}

TankShot::~TankShot()
{
	pPlaySpace = nullptr;
}
