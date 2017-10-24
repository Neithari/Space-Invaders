#include "Tank.h"

Tank::Tank( Graphics& gfx )
	:
	gfx( gfx ),
	startLoc( 387.0f, 500.0f ),
	loc( startLoc )
{
}

Tank::Tank( Graphics& gfx ,const Vec2<float>& in_loc )
	:
	gfx( gfx ),
	startLoc( in_loc ),
	loc( startLoc )
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

float Tank::ClampToScreen()
{
	const float left = loc.x;
	const float right = loc.x + dim.x;
	const float top = loc.y;
	const float bottom = loc.y + dim.y;

	if( left < 0 )
	{
		return 0.0f;
	}
	if( right >= gfx.ScreenWidth )
	{
		return gfx.ScreenWidth - float( dim.x + 1 );
	}
	else
	{
		return loc.x;
	}
	if( top < 0 )
	{
		return 0.0f;
	}
	if( bottom >= gfx.ScreenHeight )
	{
		return gfx.ScreenHeight - float( dim.y + 1 );
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
		loc.x = ClampToScreen();
	}
	if( kbd.KeyIsPressed( VK_LEFT ) )
	{
		loc.x -= speed * dt;
		loc.x = ClampToScreen();
	}
	if( kbd.KeyIsPressed( VK_SPACE ) )
	{
		if( !rapidShotPrevent )
		{
			rapidShotPrevent = true;
			CreateShot( loc );
		}
	}
	else
	{
		rapidShotPrevent = false;
	}
}

bool Tank::Collision( const Vec2<float> & in_loc,const Vec2<int>& in_dim ) const
{
	if( isAlive )
	{
		const float objright = in_loc.x + float( in_dim.x );
		const float objbottom = in_loc.y + float( in_dim.y );
		const float shotright = loc.x + float( dim.x );
		const float shotbottom = loc.y + float( dim.y );

		return ( objright >= loc.x &&
			in_loc.x <= shotright &&
			objbottom >= loc.y &&
			in_loc.y <= shotbottom );
	}
	return false;
}

bool Tank::Collision( const Rect<int>& obj ) const
{
	if( isAlive )
	{
		return Rect<int>( (Vec2<int>)loc, dim.x, dim.y ).IsOverlappingWith( obj );
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

const Rect<int> Tank::GetShotRect( const int i ) const
{
	return Rect<int>( (Vec2<int>)GetShotLoc( i ), GetShotDim() );
}

const Rect<int> Tank::GetTankRect() const
{
	return Rect<int>( (Vec2<int>)loc, dim );
}

const int Tank::GetShotCount() const
{
	return int( shot.size() );
}

void Tank::CreateShot( const Vec2<float>& origin )
{
	shot.emplace_back( origin );
}

void Tank::DeleteShot( const int i )
{
	shot.erase( shot.begin() + i );
}
