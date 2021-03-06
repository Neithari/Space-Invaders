#include "Tank.h"

Tank::Tank( Graphics& gfx ,const Vec2<float>& in_loc, const Rect<float>* in_pPlaySpace, const int in_maxShotCount )
	:
	gfx( gfx ),
	startLoc( in_loc ),
	loc( startLoc ),
	pPlaySpace( in_pPlaySpace ),
	maxShotCount( in_maxShotCount ),
	soundShot( L"Sounds\\shoot.wav" )
{
}

void Tank::Restart()
{
	loc = startLoc;
	shot.swap( std::vector<TankShot>() );
}

const Vec2<int>& Tank::GetDimention() const
{
	return dim;
}

const Vec2<float>& Tank::GetLocation() const
{
	return loc;
}

void Tank::Draw()
{
	gfx.DrawSprite( (int)loc.x, (int)loc.y, sprite, SpriteEffect::Chroma{ Colors::Magenta } );
	for( int i = 0; i < shot.size(); i++ )
	{
		shot[i].Draw( gfx );
	}
}

void Tank::DrawHit()
{
	gfx.DrawSprite( (int)loc.x, (int)loc.y, sprite, SpriteEffect::Substitution{ Colors::Magenta, Colors::Red } );
}

float Tank::ClampToPlaySpace()
{
	const float left = loc.x;
	const float right = loc.x + dim.x;
	const float top = loc.y;
	const float bottom = loc.y + dim.y;

	if( left < pPlaySpace->left )
	{
		return pPlaySpace->left;
	}
	if( right >= pPlaySpace->right )
	{
		return pPlaySpace->right - float( dim.x + 1 );
	}
	else
	{
		return loc.x;
	}
	if( top < pPlaySpace->top )
	{
		return pPlaySpace->top;
	}
	if( bottom >= pPlaySpace->bottom )
	{
		return pPlaySpace->bottom - float( dim.y + 1 );
	}
	else
	{
		return loc.y;
	}
}

void Tank::Update( const Keyboard& kbd,const float dt )
{
	for( int i = 0; i < shot.size(); i++ )
	{
		if( shot[i].Update( dt ) )
		{
			DeleteShot( i );
		}
	}
	if( kbd.KeyIsPressed( VK_RIGHT ) )
	{
		loc.x += speed * dt;
		loc.x = ClampToPlaySpace();
	}
	if( kbd.KeyIsPressed( VK_LEFT ) )
	{
		loc.x -= speed * dt;
		loc.x = ClampToPlaySpace();
	}
	if( kbd.KeyIsPressed( VK_SPACE ) )
	{
		if( !rapidShotPrevent && GetShotCount() < maxShotCount )
		{
			rapidShotPrevent = true;
			CreateShot( loc );
			soundShot.Play( 1.0f, 0.5f );
		}
	}
	else
	{
		rapidShotPrevent = false;
	}
}

bool Tank::Collision( const Vec2<float>& in_loc,const Vec2<int>& in_dim ) const
{
	return Collision( Rect<float>( in_loc, in_dim.x, in_dim.y ) );
}

bool Tank::Collision( const Rect<float>& obj ) const
{
	if( isAlive )
	{
		return GetTankRect().IsOverlappingWith( obj );
	}
	return false;
}

const Vec2<float> Tank::GetShotLoc( const int i ) const
{
	if( i < shot.size() )
	{
		return shot[i].GetLoc();
	}
	else
	{
		return { 0,0 };
	}
}

const Vec2<int>& Tank::GetShotDim() const
{
	return TankShot::GetDim();
}

const Rect<float> Tank::GetShotRect( const int i ) const
{
	Vec2<int> shotDim = GetShotDim();
	return Rect<float>( GetShotLoc( i ), shotDim.x, shotDim.y );
}

const Rect<float> Tank::GetTankRect() const
{
	return Rect<float>( loc, dim.x, dim.y );
}

const int Tank::GetShotCount() const
{
	return int( shot.size() );
}

void Tank::CreateShot( const Vec2<float>& origin )
{
	shot.emplace_back( origin, pPlaySpace );
}

void Tank::DeleteShot( const int i )
{
	shot.erase( shot.begin() + i );
}

Tank::~Tank()
{
	pPlaySpace = nullptr;
}
