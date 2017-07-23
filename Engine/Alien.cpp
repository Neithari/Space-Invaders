#include "Alien.h"

Alien::Alien( Graphics & gfx )
	:
	gfx( gfx )
{
	//small
	Dimention i_dim = invaderSmall[0].GetDim();
	Location i_loc = loc;
	invaderSmall[0].Init( i_loc );
	for ( int i = 1; i < n_small; i++ )
	{
		i_loc.x += i_dim.width + alienSpacing;
		invaderSmall[i].Init( i_loc );
	}
	//mid
	i_dim = invaderMid[0].GetDim();
	i_loc.x = loc.x;
	i_loc.y += i_dim.height + alienSpacing;
	invaderMid[0].Init( i_loc );
	for ( int i = 1; i < n_mid/2; i++ )
	{
		i_loc.x += i_dim.width + alienSpacing;
		invaderMid[i].Init( i_loc );
	}
	i_loc.x = loc.x;
	i_loc.y += i_dim.height + alienSpacing;
	for ( int i = n_mid / 2; i < n_mid; i++ )
	{
		i_loc.x += i_dim.width + alienSpacing;
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
	for ( int i = n_big / 2; i < n_big; i++ )
	{
		i_loc.x += i_dim.width + alienSpacing;
		invaderBig[i].Init( i_loc );
	}
}

Location Alien::GetLocation() const
{
	return loc;
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
