#include "Alien.h"

Alien::Alien( Graphics & gfx )
	:
	gfx( gfx )
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
}

void Alien::Update()
{
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
}

void Alien::Collision( const Location& in_loc,const Dimention& in_dim )
{
	for ( int i = 0; i < n_small; i++ )
	{
		if ( invaderSmall[i].IsAlive() )
		{
			invaderSmall[i].Collision( in_loc,in_dim );
		}
	}
	for ( int i = 0; i < n_mid; i++ )
	{
		if ( invaderMid[i].IsAlive() )
		{
			invaderMid[i].Collision( in_loc,in_dim );
		}
	}
	for ( int i = 0; i < n_big; i++ )
	{
		if ( invaderBig[i].IsAlive() )
		{
			invaderBig[i].Collision( in_loc,in_dim );
		}
	}
}
