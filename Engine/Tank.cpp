#include "Tank.h"

Tank::Tank()
{
}

Tank::Tank( const Location& in_loc )
	:
	loc( in_loc )
{
}

const Dimention& Tank::GetDimention() const
{
	return dim;
}

const Location& Tank::GetLocation() const
{
	return loc;
}

void Tank::Draw( Graphics& gfx )
{
	DrawTank( gfx );
	for ( int i = 0; i < shotMax; i++ )
	{
		if ( shot[i].IsAlive() )
		{
			shot[i].Draw( gfx );
		}
	}
}

void Tank::DrawTank( Graphics& gfx )
{
	//width = 20;
	//height = 18;
	int x = int( loc.x );
	int y = int( loc.y );

	gfx.PutPixel( 8 + x,0 + y,67,62,62 );
	gfx.PutPixel( 9 + x,0 + y,67,62,62 );
	gfx.PutPixel( 7 + x,1 + y,75,68,68 );
	gfx.PutPixel( 8 + x,1 + y,151,143,143 );
	gfx.PutPixel( 9 + x,1 + y,151,143,143 );
	gfx.PutPixel( 10 + x,1 + y,75,68,68 );
	gfx.PutPixel( 7 + x,2 + y,67,62,62 );
	gfx.PutPixel( 8 + x,2 + y,151,143,143 );
	gfx.PutPixel( 9 + x,2 + y,151,143,143 );
	gfx.PutPixel( 10 + x,2 + y,67,62,62 );
	gfx.PutPixel( 7 + x,3 + y,67,62,62 );
	gfx.PutPixel( 8 + x,3 + y,151,143,143 );
	gfx.PutPixel( 9 + x,3 + y,151,143,143 );
	gfx.PutPixel( 10 + x,3 + y,67,62,62 );
	gfx.PutPixel( 5 + x,4 + y,67,62,62 );
	gfx.PutPixel( 6 + x,4 + y,67,62,62 );
	gfx.PutPixel( 7 + x,4 + y,75,68,68 );
	gfx.PutPixel( 8 + x,4 + y,151,143,143 );
	gfx.PutPixel( 9 + x,4 + y,151,143,143 );
	gfx.PutPixel( 10 + x,4 + y,75,68,68 );
	gfx.PutPixel( 11 + x,4 + y,67,62,62 );
	gfx.PutPixel( 12 + x,4 + y,67,62,62 );
	gfx.PutPixel( 13 + x,4 + y,75,68,68 );
	gfx.PutPixel( 14 + x,4 + y,67,62,62 );
	gfx.PutPixel( 4 + x,5 + y,75,68,68 );
	gfx.PutPixel( 5 + x,5 + y,255,0,0 );
	gfx.PutPixel( 6 + x,5 + y,255,0,0 );
	gfx.PutPixel( 7 + x,5 + y,255,0,0 );
	gfx.PutPixel( 8 + x,5 + y,255,0,0 );
	gfx.PutPixel( 9 + x,5 + y,255,0,0 );
	gfx.PutPixel( 10 + x,5 + y,255,0,0 );
	gfx.PutPixel( 11 + x,5 + y,255,0,0 );
	gfx.PutPixel( 12 + x,5 + y,255,0,0 );
	gfx.PutPixel( 13 + x,5 + y,255,0,0 );
	gfx.PutPixel( 14 + x,5 + y,255,0,0 );
	gfx.PutPixel( 15 + x,5 + y,67,62,62 );
	gfx.PutPixel( 4 + x,6 + y,67,62,62 );
	gfx.PutPixel( 5 + x,6 + y,255,0,0 );
	gfx.PutPixel( 6 + x,6 + y,185,1,1 );
	gfx.PutPixel( 7 + x,6 + y,185,1,1 );
	gfx.PutPixel( 8 + x,6 + y,185,1,1 );
	gfx.PutPixel( 9 + x,6 + y,185,1,1 );
	gfx.PutPixel( 10 + x,6 + y,185,1,1 );
	gfx.PutPixel( 11 + x,6 + y,255,255,255 );
	gfx.PutPixel( 12 + x,6 + y,255,255,255 );
	gfx.PutPixel( 13 + x,6 + y,185,1,1 );
	gfx.PutPixel( 14 + x,6 + y,255,0,0 );
	gfx.PutPixel( 15 + x,6 + y,75,68,68 );
	gfx.PutPixel( 18 + x,6 + y,67,62,62 );
	gfx.PutPixel( 19 + x,6 + y,67,62,62 );
	gfx.PutPixel( 4 + x,7 + y,67,62,62 );
	gfx.PutPixel( 5 + x,7 + y,255,0,0 );
	gfx.PutPixel( 6 + x,7 + y,255,0,0 );
	gfx.PutPixel( 7 + x,7 + y,255,0,0 );
	gfx.PutPixel( 8 + x,7 + y,255,0,0 );
	gfx.PutPixel( 9 + x,7 + y,255,0,0 );
	gfx.PutPixel( 10 + x,7 + y,255,0,0 );
	gfx.PutPixel( 11 + x,7 + y,255,0,0 );
	gfx.PutPixel( 12 + x,7 + y,255,0,0 );
	gfx.PutPixel( 13 + x,7 + y,255,0,0 );
	gfx.PutPixel( 14 + x,7 + y,255,0,0 );
	gfx.PutPixel( 15 + x,7 + y,67,62,62 );
	gfx.PutPixel( 18 + x,7 + y,67,62,62 );
	gfx.PutPixel( 19 + x,7 + y,67,62,62 );
	gfx.PutPixel( 1 + x,8 + y,75,68,68 );
	gfx.PutPixel( 2 + x,8 + y,67,62,62 );
	gfx.PutPixel( 3 + x,8 + y,67,62,62 );
	gfx.PutPixel( 4 + x,8 + y,75,68,68 );
	gfx.PutPixel( 5 + x,8 + y,67,62,62 );
	gfx.PutPixel( 6 + x,8 + y,75,68,68 );
	gfx.PutPixel( 7 + x,8 + y,67,62,62 );
	gfx.PutPixel( 8 + x,8 + y,75,68,68 );
	gfx.PutPixel( 9 + x,8 + y,67,62,62 );
	gfx.PutPixel( 10 + x,8 + y,67,62,62 );
	gfx.PutPixel( 11 + x,8 + y,75,68,68 );
	gfx.PutPixel( 12 + x,8 + y,67,62,62 );
	gfx.PutPixel( 13 + x,8 + y,67,62,62 );
	gfx.PutPixel( 14 + x,8 + y,67,62,62 );
	gfx.PutPixel( 15 + x,8 + y,67,62,62 );
	gfx.PutPixel( 16 + x,8 + y,75,68,68 );
	gfx.PutPixel( 17 + x,8 + y,67,62,62 );
	gfx.PutPixel( 18 + x,8 + y,75,68,68 );
	gfx.PutPixel( 19 + x,8 + y,67,62,62 );
	gfx.PutPixel( 0 + x,9 + y,67,62,62 );
	gfx.PutPixel( 1 + x,9 + y,255,0,0 );
	gfx.PutPixel( 2 + x,9 + y,255,0,0 );
	gfx.PutPixel( 3 + x,9 + y,255,0,0 );
	gfx.PutPixel( 4 + x,9 + y,255,0,0 );
	gfx.PutPixel( 5 + x,9 + y,255,0,0 );
	gfx.PutPixel( 6 + x,9 + y,255,0,0 );
	gfx.PutPixel( 7 + x,9 + y,255,0,0 );
	gfx.PutPixel( 8 + x,9 + y,255,0,0 );
	gfx.PutPixel( 9 + x,9 + y,255,0,0 );
	gfx.PutPixel( 10 + x,9 + y,255,0,0 );
	gfx.PutPixel( 11 + x,9 + y,255,0,0 );
	gfx.PutPixel( 12 + x,9 + y,255,0,0 );
	gfx.PutPixel( 13 + x,9 + y,255,0,0 );
	gfx.PutPixel( 14 + x,9 + y,223,7,7 );
	gfx.PutPixel( 15 + x,9 + y,223,7,7 );
	gfx.PutPixel( 16 + x,9 + y,223,7,7 );
	gfx.PutPixel( 17 + x,9 + y,223,7,7 );
	gfx.PutPixel( 18 + x,9 + y,255,0,0 );
	gfx.PutPixel( 19 + x,9 + y,67,62,62 );
	gfx.PutPixel( 0 + x,10 + y,67,62,62 );
	gfx.PutPixel( 1 + x,10 + y,255,0,0 );
	gfx.PutPixel( 2 + x,10 + y,185,1,1 );
	gfx.PutPixel( 3 + x,10 + y,185,1,1 );
	gfx.PutPixel( 4 + x,10 + y,185,1,1 );
	gfx.PutPixel( 5 + x,10 + y,185,1,1 );
	gfx.PutPixel( 6 + x,10 + y,185,1,1 );
	gfx.PutPixel( 7 + x,10 + y,185,1,1 );
	gfx.PutPixel( 8 + x,10 + y,185,1,1 );
	gfx.PutPixel( 9 + x,10 + y,185,1,1 );
	gfx.PutPixel( 10 + x,10 + y,185,1,1 );
	gfx.PutPixel( 11 + x,10 + y,185,1,1 );
	gfx.PutPixel( 12 + x,10 + y,185,1,1 );
	gfx.PutPixel( 13 + x,10 + y,185,1,1 );
	gfx.PutPixel( 14 + x,10 + y,185,1,1 );
	gfx.PutPixel( 15 + x,10 + y,110,99,99 );
	gfx.PutPixel( 16 + x,10 + y,110,99,99 );
	gfx.PutPixel( 17 + x,10 + y,185,1,1 );
	gfx.PutPixel( 18 + x,10 + y,255,0,0 );
	gfx.PutPixel( 19 + x,10 + y,75,68,68 );
	gfx.PutPixel( 0 + x,11 + y,75,68,68 );
	gfx.PutPixel( 1 + x,11 + y,255,0,0 );
	gfx.PutPixel( 2 + x,11 + y,255,0,0 );
	gfx.PutPixel( 3 + x,11 + y,255,0,0 );
	gfx.PutPixel( 4 + x,11 + y,255,0,0 );
	gfx.PutPixel( 5 + x,11 + y,255,0,0 );
	gfx.PutPixel( 6 + x,11 + y,255,0,0 );
	gfx.PutPixel( 7 + x,11 + y,255,0,0 );
	gfx.PutPixel( 8 + x,11 + y,255,0,0 );
	gfx.PutPixel( 9 + x,11 + y,255,0,0 );
	gfx.PutPixel( 10 + x,11 + y,255,0,0 );
	gfx.PutPixel( 11 + x,11 + y,255,0,0 );
	gfx.PutPixel( 12 + x,11 + y,255,0,0 );
	gfx.PutPixel( 13 + x,11 + y,255,0,0 );
	gfx.PutPixel( 14 + x,11 + y,223,7,7 );
	gfx.PutPixel( 15 + x,11 + y,223,7,7 );
	gfx.PutPixel( 16 + x,11 + y,223,7,7 );
	gfx.PutPixel( 17 + x,11 + y,223,7,7 );
	gfx.PutPixel( 18 + x,11 + y,255,0,0 );
	gfx.PutPixel( 19 + x,11 + y,67,62,62 );
	gfx.PutPixel( 0 + x,12 + y,67,62,62 );
	gfx.PutPixel( 1 + x,12 + y,67,62,62 );
	gfx.PutPixel( 2 + x,12 + y,75,68,68 );
	gfx.PutPixel( 3 + x,12 + y,67,62,62 );
	gfx.PutPixel( 4 + x,12 + y,67,62,62 );
	gfx.PutPixel( 5 + x,12 + y,75,68,68 );
	gfx.PutPixel( 6 + x,12 + y,67,62,62 );
	gfx.PutPixel( 7 + x,12 + y,67,62,62 );
	gfx.PutPixel( 8 + x,12 + y,75,68,68 );
	gfx.PutPixel( 9 + x,12 + y,67,62,62 );
	gfx.PutPixel( 10 + x,12 + y,67,62,62 );
	gfx.PutPixel( 11 + x,12 + y,75,68,68 );
	gfx.PutPixel( 12 + x,12 + y,67,62,62 );
	gfx.PutPixel( 13 + x,12 + y,67,62,62 );
	gfx.PutPixel( 14 + x,12 + y,67,62,62 );
	gfx.PutPixel( 15 + x,12 + y,67,62,62 );
	gfx.PutPixel( 16 + x,12 + y,67,62,62 );
	gfx.PutPixel( 17 + x,12 + y,67,62,62 );
	gfx.PutPixel( 18 + x,12 + y,67,62,62 );
	gfx.PutPixel( 19 + x,12 + y,67,62,62 );
	gfx.PutPixel( 1 + x,13 + y,159,80,17 );
	gfx.PutPixel( 2 + x,13 + y,169,60,7 );
	gfx.PutPixel( 3 + x,13 + y,159,80,17 );
	gfx.PutPixel( 4 + x,13 + y,179,82,3 );
	gfx.PutPixel( 5 + x,13 + y,169,60,7 );
	gfx.PutPixel( 6 + x,13 + y,159,80,17 );
	gfx.PutPixel( 7 + x,13 + y,179,82,3 );
	gfx.PutPixel( 8 + x,13 + y,169,60,7 );
	gfx.PutPixel( 9 + x,13 + y,159,80,17 );
	gfx.PutPixel( 10 + x,13 + y,179,82,3 );
	gfx.PutPixel( 11 + x,13 + y,169,60,7 );
	gfx.PutPixel( 12 + x,13 + y,159,80,17 );
	gfx.PutPixel( 13 + x,13 + y,179,82,3 );
	gfx.PutPixel( 14 + x,13 + y,169,60,7 );
	gfx.PutPixel( 15 + x,13 + y,159,80,17 );
	gfx.PutPixel( 16 + x,13 + y,179,82,3 );
	gfx.PutPixel( 17 + x,13 + y,169,60,7 );
	gfx.PutPixel( 18 + x,13 + y,159,80,17 );
	gfx.PutPixel( 1 + x,14 + y,169,60,7 );
	gfx.PutPixel( 2 + x,14 + y,151,143,143 );
	gfx.PutPixel( 3 + x,14 + y,151,143,143 );
	gfx.PutPixel( 4 + x,14 + y,151,143,143 );
	gfx.PutPixel( 5 + x,14 + y,151,143,143 );
	gfx.PutPixel( 6 + x,14 + y,151,143,143 );
	gfx.PutPixel( 7 + x,14 + y,151,143,143 );
	gfx.PutPixel( 8 + x,14 + y,151,143,143 );
	gfx.PutPixel( 9 + x,14 + y,151,143,143 );
	gfx.PutPixel( 10 + x,14 + y,151,143,143 );
	gfx.PutPixel( 11 + x,14 + y,151,143,143 );
	gfx.PutPixel( 12 + x,14 + y,151,143,143 );
	gfx.PutPixel( 13 + x,14 + y,151,143,143 );
	gfx.PutPixel( 14 + x,14 + y,151,143,143 );
	gfx.PutPixel( 15 + x,14 + y,151,143,143 );
	gfx.PutPixel( 16 + x,14 + y,151,143,143 );
	gfx.PutPixel( 17 + x,14 + y,179,82,3 );
	gfx.PutPixel( 1 + x,15 + y,179,82,3 );
	gfx.PutPixel( 2 + x,15 + y,159,80,17 );
	gfx.PutPixel( 3 + x,15 + y,151,143,143 );
	gfx.PutPixel( 4 + x,15 + y,151,143,143 );
	gfx.PutPixel( 5 + x,15 + y,75,68,68 );
	gfx.PutPixel( 6 + x,15 + y,151,143,143 );
	gfx.PutPixel( 7 + x,15 + y,151,143,143 );
	gfx.PutPixel( 8 + x,15 + y,75,68,68 );
	gfx.PutPixel( 9 + x,15 + y,151,143,143 );
	gfx.PutPixel( 10 + x,15 + y,151,143,143 );
	gfx.PutPixel( 11 + x,15 + y,75,68,68 );
	gfx.PutPixel( 12 + x,15 + y,151,143,143 );
	gfx.PutPixel( 13 + x,15 + y,151,143,143 );
	gfx.PutPixel( 14 + x,15 + y,75,68,68 );
	gfx.PutPixel( 15 + x,15 + y,151,143,143 );
	gfx.PutPixel( 16 + x,15 + y,159,80,17 );
	gfx.PutPixel( 17 + x,15 + y,169,60,7 );
	gfx.PutPixel( 2 + x,16 + y,169,60,7 );
	gfx.PutPixel( 3 + x,16 + y,179,82,3 );
	gfx.PutPixel( 4 + x,16 + y,151,143,143 );
	gfx.PutPixel( 5 + x,16 + y,151,143,143 );
	gfx.PutPixel( 6 + x,16 + y,151,143,143 );
	gfx.PutPixel( 7 + x,16 + y,151,143,143 );
	gfx.PutPixel( 8 + x,16 + y,151,143,143 );
	gfx.PutPixel( 9 + x,16 + y,151,143,143 );
	gfx.PutPixel( 10 + x,16 + y,151,143,143 );
	gfx.PutPixel( 11 + x,16 + y,151,143,143 );
	gfx.PutPixel( 12 + x,16 + y,151,143,143 );
	gfx.PutPixel( 13 + x,16 + y,151,143,143 );
	gfx.PutPixel( 14 + x,16 + y,151,143,143 );
	gfx.PutPixel( 15 + x,16 + y,169,60,7 );
	gfx.PutPixel( 16 + x,16 + y,179,82,3 );
	gfx.PutPixel( 3 + x,17 + y,159,80,17 );
	gfx.PutPixel( 4 + x,17 + y,169,60,7 );
	gfx.PutPixel( 5 + x,17 + y,179,82,3 );
	gfx.PutPixel( 6 + x,17 + y,159,80,17 );
	gfx.PutPixel( 7 + x,17 + y,169,60,7 );
	gfx.PutPixel( 8 + x,17 + y,179,82,3 );
	gfx.PutPixel( 9 + x,17 + y,159,80,17 );
	gfx.PutPixel( 10 + x,17 + y,169,60,7 );
	gfx.PutPixel( 11 + x,17 + y,179,82,3 );
	gfx.PutPixel( 12 + x,17 + y,159,80,17 );
	gfx.PutPixel( 13 + x,17 + y,169,60,7 );
	gfx.PutPixel( 14 + x,17 + y,179,82,3 );
	gfx.PutPixel( 15 + x,17 + y,159,80,17 );
}

void Tank::Update( const Keyboard& kbd )
{
	for ( int i = 0; i < shotMax; i++ )
	{
		if ( shot[i].IsAlive() )
		{
			shot[i].Update();
		}
	}
	if ( kbd.KeyIsPressed( VK_RIGHT ) )
	{
		loc.x += speed;
	}
	if ( kbd.KeyIsPressed( VK_LEFT ) )
	{
		loc.x -= speed;
	}
	if ( kbd.KeyIsPressed( VK_SPACE ) )
	{
		if ( !rapidShotPrevent )
		{
			rapidShotPrevent = true;
 			for ( int i = 0; i < shotMax; i++ )
			{
				if ( !shot[i].IsAlive() )
				{
					shot[i].Init( loc );
					break;
				}
			}
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
	if ( i < shotMax &&
		shot[i].IsAlive() )
	{
		return shot[i].GetLoc();
	}
	else
	{
		return {0,0};
	}
}

const Dimention & Tank::GetShotDim() const
{
	return shot[0].GetDim();
}

void Tank::DeleteShot( const int i )
{
	shot[i].Kill();
}

bool Tank::IsAlive()
{
	return isAlive;
}

void Tank::Kill()
{
	isAlive = false;
}
