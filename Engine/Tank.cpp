#include "Tank.h"

Tank::Tank( Graphics& gfx )
	:
	gfx( gfx )
{
}

Tank::Tank( Graphics& gfx ,const Location& in_loc )
	:
	gfx( gfx ),
	loc( in_loc )
{
}

void Tank::Restart()
{
	loc = { 400.0f,500.0f };
	shot.swap( std::vector<TankShot>() );
}

const Dimention& Tank::GetDimention() const
{
	return dim;
}

const Location& Tank::GetLocation() const
{
	return loc;
}

void Tank::Draw()
{
	Sprite::DrawTank( int( loc.x ),int( loc.y ),gfx );
	for ( int i = 0; i < shot.size(); i++ )
	{
		shot[i].Draw( gfx );
	}
}

float Tank::ClampToScreen()
{
	const float left = loc.x;
	const float right = loc.x + dim.width;
	const float top = loc.y;
	const float bottom = loc.y + dim.height;

	if ( left < 0 )
	{
		return 0.0f;
	}
	if ( right >= gfx.ScreenWidth )
	{
		return gfx.ScreenWidth - float( dim.width + 1 );
	}
	else
	{
		return loc.x;
	}
	if ( top < 0 )
	{
		return 0.0f;
	}
	if ( bottom >= gfx.ScreenHeight )
	{
		return gfx.ScreenHeight - float( dim.height + 1 );
	}
	else
	{
		return loc.y;
	}
}

void Tank::Update( const Keyboard& kbd,const float dt )
{
	for ( int i = 0; i < shot.size(); i++ )
	{
		if ( shot[i].Update( dt ) )
		{
			DeleteShot( i );
		}
	}
	if ( kbd.KeyIsPressed( VK_RIGHT ) )
	{
		loc.x += speed * dt;
		loc.x = ClampToScreen();
	}
	if ( kbd.KeyIsPressed( VK_LEFT ) )
	{
		loc.x -= speed * dt;
		loc.x = ClampToScreen();
	}
	if ( kbd.KeyIsPressed( VK_SPACE ) )
	{
		if ( !rapidShotPrevent )
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

bool Tank::Collision( const Location & in_loc,const Dimention & in_dim )
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
			return true;
		}
	}
	return false;
}

const Location Tank::GetShotLoc( const int i ) const
{
	if ( i < shot.size() )
	{
		return shot[i].GetLoc();
	}
	else
	{
		return {0,0};
	}
}

const Dimention Tank::GetShotDim() const
{
	return TankShot::GetDim();
}

void Tank::CreateShot( const Location& origin )
{
	shot.push_back( origin );
}

void Tank::DeleteShot( const int i )
{
	shot.erase( shot.begin() + i );
}

bool Tank::IsAlive()
{
	return isAlive;
}

void Tank::Kill()
{
	isAlive = false;
}
