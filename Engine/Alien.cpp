#include "Alien.h"

Alien::Alien( Graphics & gfx )
	:
	gfx( gfx ),
	rng( rd() ),
	chanceDist( 1,100 ),
	shotDist( 0,14 )
{
	//small
	Dimention i_dim = invaderSmall[0].GetDim();
	Dimention iBig_dim = invaderBig[0].GetDim();
	Location i_loc = loc;
	float align = float( iBig_dim.width / 2 - i_dim.width / 2 );
	i_loc.x += align;
	invaderSmall[0].Init( i_loc );
	for ( int i = 1; i < n_small; i++ )
	{
		i_loc.x += iBig_dim.width + alienSpacing;
		invaderSmall[i].Init( i_loc );
	}
	//mid
	i_dim = invaderMid[0].GetDim();
	align = float( iBig_dim.width / 2 - i_dim.width / 2 );
	i_loc.x = loc.x;
	i_loc.x += align;
	i_loc.y += i_dim.height + alienSpacing;
	invaderMid[0].Init( i_loc );
	for ( int i = 1; i < n_mid/2; i++ )
	{
		i_loc.x += iBig_dim.width + alienSpacing;
		invaderMid[i].Init( i_loc );
	}
	i_loc.x = loc.x;
	i_loc.x += align;
	i_loc.y += i_dim.height + alienSpacing;
	invaderMid[n_mid / 2].Init( i_loc );
	for ( int i = 1 + n_mid / 2; i < n_mid; i++ )
	{
		i_loc.x += iBig_dim.width + alienSpacing;
		invaderMid[i].Init( i_loc );
	}
	//big
	i_dim = invaderBig[0].GetDim();
	i_loc.x = loc.x;
	i_loc.y += i_dim.height + alienSpacing;
	invaderBig[0].Init( i_loc );
	for ( int i = 1; i < n_big / 2; i++ )
	{
		i_loc.x += i_dim.width + alienSpacing;
		invaderBig[i].Init( i_loc );
	}
	i_loc.x = loc.x;
	i_loc.y += i_dim.height + alienSpacing;
	invaderBig[n_big / 2].Init( i_loc );
	for ( int i = 1 + n_big / 2; i < n_big; i++ )
	{
		i_loc.x += i_dim.width + alienSpacing;
		invaderBig[i].Init( i_loc );
	}
}

void Alien::Draw()
{
	for ( int i = 0; i < n_small; i++ )
	{
		if ( invaderSmall[i].IsAlive() )
		{
			invaderSmall[i].Draw( gfx );
		}
	}
	for ( int i = 0; i < n_mid; i++ )
	{
		if ( invaderMid[i].IsAlive() )
		{
			invaderMid[i].Draw( gfx );
		}
	}
	for ( int i = 0; i < n_big; i++ )
	{
		if ( invaderBig[i].IsAlive() )
		{
			invaderBig[i].Draw( gfx );
		}
	}
	for ( int i = 0; i < shotMax; i++ )
	{
		if ( shot[i].IsAlive() )
		{
			shot[i].Draw( gfx );
		}
	}
}

void Alien::Update()
{
	//invader update
	for ( int i = 0; i < n_small; i++ )
	{
		if ( invaderSmall[i].IsAlive() )
		{
			invaderSmall[i].Update();
		}
	}
	for ( int i = 0; i < n_mid; i++ )
	{
		if ( invaderMid[i].IsAlive() )
		{
			invaderMid[i].Update();
		}
	}
	for ( int i = 0; i < n_big; i++ )
	{
		if ( invaderBig[i].IsAlive() )
		{
			invaderBig[i].Update();
		}
	}
	//Shot creation
	if ( chanceDist( rng ) <= chance )
	{
		int i = shotDist( rng );
		if ( !shot[i].IsAlive() )
		{
			//Get bottom Alien
			Location shotLoc;
			Dimention shotDim;
			if ( invaderBig[i + 15].IsAlive() )
			{
				shotLoc = invaderBig[i + 15].GetLoc();
				shotDim = invaderBig[0].GetDim();
			}
			else if ( invaderBig[i].IsAlive() )
			{
				shotLoc = invaderBig[i].GetLoc();
				shotDim = invaderBig[0].GetDim();
			}
			else if ( invaderMid[i + 15].IsAlive() )
			{
				shotLoc = invaderMid[i + 15].GetLoc();
				shotDim = invaderMid[0].GetDim();
			}
			else if ( invaderMid[i].IsAlive() )
			{
				shotLoc = invaderMid[i].GetLoc();
				shotDim = invaderMid[0].GetDim();
			}
			else if ( invaderSmall[i].IsAlive() )
			{
				shotLoc = invaderSmall[i].GetLoc();
				shotDim = invaderSmall[0].GetDim();
			}
			else
			{
				columnClean[i] = true;
			}
			if ( !columnClean[i] )
			{
				shot[i].Init( shotLoc,shotDim );
			}
		}
	}
	//update shot
	for ( int i = 0; i < shotMax; i++ )
	{
		if ( shot[i].IsAlive() )
		{
			shot[i].Update();
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
