#include "Alien.h"

Alien::Alien( Graphics & gfx, const int shotMax, const int shotChance )
	:
	gfx( gfx ),
	shotMax( shotMax ),
	rng( rd() ),
	chanceDist( 1,100 ),
	shotDist( 0,14 ),
	shotChance( shotChance )
{
	//prepare shot
	shot.reserve( shotMax );
	for( int i = 0; i < shotMax; i++ )
	{
		shot.emplace_back();
	}
	//small
	Dimention i_dim = invaderSmall[0].GetDim();
	Dimention iBig_dim = invaderBig[0].GetDim();
	Location d_loc = loc;
	float align = float( iBig_dim.width / 2 - i_dim.width / 2 );
	d_loc.x += align;
	invaderSmall[0].Init( d_loc );
	for ( int i = 1; i < n_small; i++ )
	{
		d_loc.x += iBig_dim.width + alienSpacing;
		invaderSmall[i].Init( d_loc );
	}
	//mid
	i_dim = invaderMid[0].GetDim();
	align = float( iBig_dim.width / 2 - i_dim.width / 2 );
	d_loc.x = loc.x;
	d_loc.x += align;
	d_loc.y += i_dim.height + alienSpacing;
	invaderMid[0].Init( d_loc );
	for ( int i = 1; i < n_mid/2; i++ )
	{
		d_loc.x += iBig_dim.width + alienSpacing;
		invaderMid[i].Init( d_loc );
	}
	d_loc.x = loc.x;
	d_loc.x += align;
	d_loc.y += i_dim.height + alienSpacing;
	invaderMid[n_mid / 2].Init( d_loc );
	for ( int i = 1 + n_mid / 2; i < n_mid; i++ )
	{
		d_loc.x += iBig_dim.width + alienSpacing;
		invaderMid[i].Init( d_loc );
	}
	//big
	i_dim = invaderBig[0].GetDim();
	d_loc.x = loc.x;
	d_loc.y += i_dim.height + alienSpacing;
	invaderBig[0].Init( d_loc );
	for ( int i = 1; i < n_big / 2; i++ )
	{
		d_loc.x += i_dim.width + alienSpacing;
		invaderBig[i].Init( d_loc );
	}
	d_loc.x = loc.x;
	d_loc.y += i_dim.height + alienSpacing;
	invaderBig[n_big / 2].Init( d_loc );
	for ( int i = 1 + n_big / 2; i < n_big; i++ )
	{
		d_loc.x += i_dim.width + alienSpacing;
		invaderBig[i].Init( d_loc );
	}
	//dimention
	dim.width = invaderBig[0].GetDim().width * 15 + alienSpacing * 14;
	dim.height = invaderBig[0].GetDim().height * 2 + invaderMid[0].GetDim().height * 2 + invaderSmall[0].GetDim().height + alienSpacing * 4;
}

void Alien::Restart()
{
	loc = { 50,50 };
	//small
	Dimention i_dim = invaderSmall[0].GetDim();
	Dimention iBig_dim = invaderBig[0].GetDim();
	Location d_loc = loc;
	float align = float( iBig_dim.width / 2 - i_dim.width / 2 );
	d_loc.x += align;
	invaderSmall[0].Init( d_loc );
	for ( int i = 1; i < n_small; i++ )
	{
		d_loc.x += iBig_dim.width + alienSpacing;
		invaderSmall[i].Init( d_loc );
	}
	//mid
	i_dim = invaderMid[0].GetDim();
	align = float( iBig_dim.width / 2 - i_dim.width / 2 );
	d_loc.x = loc.x;
	d_loc.x += align;
	d_loc.y += i_dim.height + alienSpacing;
	invaderMid[0].Init( d_loc );
	for ( int i = 1; i < n_mid / 2; i++ )
	{
		d_loc.x += iBig_dim.width + alienSpacing;
		invaderMid[i].Init( d_loc );
	}
	d_loc.x = loc.x;
	d_loc.x += align;
	d_loc.y += i_dim.height + alienSpacing;
	invaderMid[n_mid / 2].Init( d_loc );
	for ( int i = 1 + n_mid / 2; i < n_mid; i++ )
	{
		d_loc.x += iBig_dim.width + alienSpacing;
		invaderMid[i].Init( d_loc );
	}
	//big
	i_dim = invaderBig[0].GetDim();
	d_loc.x = loc.x;
	d_loc.y += i_dim.height + alienSpacing;
	invaderBig[0].Init( d_loc );
	for ( int i = 1; i < n_big / 2; i++ )
	{
		d_loc.x += i_dim.width + alienSpacing;
		invaderBig[i].Init( d_loc );
	}
	d_loc.x = loc.x;
	d_loc.y += i_dim.height + alienSpacing;
	invaderBig[n_big / 2].Init( d_loc );
	for ( int i = 1 + n_big / 2; i < n_big; i++ )
	{
		d_loc.x += i_dim.width + alienSpacing;
		invaderBig[i].Init( d_loc );
	}
	//dimention
	dim.width = invaderBig[0].GetDim().width * 15 + alienSpacing * 14;
	dim.height = invaderBig[0].GetDim().height * 2 + invaderMid[0].GetDim().height * 2 + invaderSmall[0].GetDim().height + alienSpacing * 4;
	//reset count
	count_small = 15;
	count_mid = 30;
 	count_big = 30;
	//reset column
	for ( int i = 0; i < 15; i++ )
	{
		columnClean[i] = false;
	}
	//delete shots
	for ( int i = 0; i < shotMax; i++ )
	{
		shot[i].Kill();
	}
}

void Alien::Draw()
{
	//small
	Dimention i_dim = invaderSmall[0].GetDim();
	Dimention iBig_dim = invaderBig[0].GetDim();
	Location d_loc = loc;
	float align = float( iBig_dim.width / 2 - i_dim.width / 2 );
	d_loc.x += align;
	invaderSmall[0].Draw( gfx,d_loc );
	for ( int i = 1; i < n_small; i++ )
	{
		d_loc.x += iBig_dim.width + alienSpacing;
		invaderSmall[i].Draw( gfx,d_loc );
	}
	//mid
	i_dim = invaderMid[0].GetDim();
	align = float( iBig_dim.width / 2 - i_dim.width / 2 );
	d_loc.x = loc.x;
	d_loc.x += align;
	d_loc.y += i_dim.height + alienSpacing;
	invaderMid[0].Draw( gfx,d_loc );
	for ( int i = 1; i < n_mid / 2; i++ )
	{
		d_loc.x += iBig_dim.width + alienSpacing;
		invaderMid[i].Draw( gfx,d_loc );
	}
	d_loc.x = loc.x;
	d_loc.x += align;
	d_loc.y += i_dim.height + alienSpacing;
	invaderMid[n_mid / 2].Draw( gfx,d_loc );
	for ( int i = 1 + n_mid / 2; i < n_mid; i++ )
	{
		d_loc.x += iBig_dim.width + alienSpacing;
		invaderMid[i].Draw( gfx,d_loc );
	}
	//big
	i_dim = invaderBig[0].GetDim();
	d_loc.x = loc.x;
	d_loc.y += i_dim.height + alienSpacing;
	invaderBig[0].Draw( gfx,d_loc );
	for ( int i = 1; i < n_big / 2; i++ )
	{
		d_loc.x += i_dim.width + alienSpacing;
		invaderBig[i].Draw( gfx,d_loc );
	}
	d_loc.x = loc.x;
	d_loc.y += i_dim.height + alienSpacing;
	invaderBig[n_big / 2].Draw( gfx,d_loc );
	for ( int i = 1 + n_big / 2; i < n_big; i++ )
	{
		d_loc.x += i_dim.width + alienSpacing;
		invaderBig[i].Draw( gfx,d_loc );
	}
	//Shot
	for ( int i = 0; i < shotMax; i++ )
	{
		if ( shot[i].IsAlive() )
		{
			shot[i].Draw( gfx );
		}
	}
}

void Alien::Update( const float dt )
{
	//Move invader
	if ( moveTime >= moveSpeed )
	{
		Location new_loc = loc;
		new_loc += delta_loc;
		if ( OutsideBorder( new_loc,dim ) )
		{
			delta_loc.x = -delta_loc.x;
			delta_loc.y = alienSpacing;
			loc += delta_loc;
			delta_loc.y = 0;
		}
		else
		{
			loc += delta_loc;
		}
		moveTime = 0.0f;
	}
	else
	{
		moveTime += dt;
	}
	//Shot creation
	int tempChance = chanceDist( rng );
	if ( tempChance <= shotChance )
	{
		int loc = shotDist( rng );
		//find a free shot
		for( int i = 0; i < shotMax; i++ )
		{
			if( !shot[i].IsAlive() )
			{
				//Get bottom Alien
				Location shotLoc;
				Dimention shotDim;
				if( invaderBig[loc + 15].IsAlive() )
				{
					shotLoc = invaderBig[loc + 15].GetLoc();
					shotDim = invaderBig[0].GetDim();
				}
				else if( invaderBig[loc].IsAlive() )
				{
					shotLoc = invaderBig[loc].GetLoc();
					shotDim = invaderBig[0].GetDim();
				}
				else if( invaderMid[loc + 15].IsAlive() )
				{
					shotLoc = invaderMid[loc + 15].GetLoc();
					shotDim = invaderMid[0].GetDim();
				}
				else if( invaderMid[loc].IsAlive() )
				{
					shotLoc = invaderMid[loc].GetLoc();
					shotDim = invaderMid[0].GetDim();
				}
				else if( invaderSmall[loc].IsAlive() )
				{
					shotLoc = invaderSmall[loc].GetLoc();
					shotDim = invaderSmall[0].GetDim();
				}
				else
				{
					columnClean[loc] = true;
				}
				if( !columnClean[loc] )
				{
					shot[i].Init( shotLoc, shotDim );
				}
				break;
			}
		}
	}
	//update shot
	for ( int i = 0; i < shotMax; i++ )
	{
		if ( shot[i].IsAlive() )
		{
			shot[i].Update( dt );
		}
	}
}

bool Alien::Collision( const Location& in_loc,const Dimention& in_dim )
{
	for ( int i = 0; i < n_small; i++ )
	{
		if ( invaderSmall[i].IsAlive() )
		{
			invaderSmall[i].Collision( in_loc,in_dim );
			if ( !invaderSmall[i].IsAlive() )
			{
				count_small--;
				return true;
			}
		}
	}
	for ( int i = 0; i < n_mid; i++ )
	{
		if ( invaderMid[i].IsAlive() )
		{
			invaderMid[i].Collision( in_loc,in_dim );
			if ( !invaderMid[i].IsAlive() )
			{
				count_mid--;
				return true;
			}
		}
	}
	for ( int i = 0; i < n_big; i++ )
	{
		if ( invaderBig[i].IsAlive() )
		{
			invaderBig[i].Collision( in_loc,in_dim );
			if ( !invaderBig[i].IsAlive() )
			{
				count_big--;
				return true;
			}
		}
	}
	return false;
}

const Location Alien::GetShotLoc( const int i ) const
{
	return shot[i].GetLoc();
}

const Dimention & Alien::GetShotDim() const
{
	return shot[0].GetDim();
}

void Alien::DeleteShot( const int i )
{
	shot[i].Kill();
}

int Alien::Count()
{
	return count_small + count_mid + count_big;
}

bool Alien::OutsideBorder( const Location & in_loc,const Dimention & in_dim )
{
	const float left = in_loc.x;
	const float right = in_loc.x + in_dim.width;
	const float top = in_loc.y;
	const float bottom = in_loc.y + in_dim.height;

	return left < 0 ||
		right >= gfx.ScreenWidth ||
		top < 0 ||
		bottom >= gfx.ScreenHeight;
}
