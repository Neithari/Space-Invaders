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
	//reserve space
	invaderSmall.reserve( n_small );
	invaderMid.reserve( n_mid );
	invaderBig.reserve( n_big );
	//prepare shot
	shot.reserve( shotMax );
	for( int i = 0; i < shotMax; i++ )
	{
		shot.emplace_back();
	}
	//small
	Vec2<int> i_dim = Invader::dimSmall;
	Vec2<int> iBig_dim = Invader::dimBig;
	Vec2<float> d_loc = loc;
	float align = float( iBig_dim.x / 2 - i_dim.x / 2 );
	d_loc.x += align;
	invaderSmall.emplace_back( d_loc, Invader::InvaderType::InvaderSmall );
	for ( int i = 1; i < n_small; i++ )
	{
		d_loc.x += iBig_dim.x + alienSpacing;
		invaderSmall.emplace_back( d_loc, Invader::InvaderType::InvaderSmall );
	}
	//mid
	i_dim = Invader::dimMid;
	d_loc.x = loc.x;
	d_loc.y += i_dim.y + alienSpacing;
	invaderMid.emplace_back( d_loc, Invader::InvaderType::InvaderMid );
	for ( int i = 1; i < n_mid/2; i++ )
	{
		d_loc.x += iBig_dim.x + alienSpacing;
		invaderMid.emplace_back( d_loc, Invader::InvaderType::InvaderMid );
	}
	d_loc.x = loc.x;
	d_loc.y += i_dim.y + alienSpacing;
	invaderMid.emplace_back( d_loc, Invader::InvaderType::InvaderMid );
	for ( int i = 1 + n_mid / 2; i < n_mid; i++ )
	{
		d_loc.x += iBig_dim.x + alienSpacing;
		invaderMid.emplace_back( d_loc, Invader::InvaderType::InvaderMid );
	}
	//big
	i_dim = Invader::dimBig;
	d_loc.x = loc.x;
	d_loc.y += i_dim.y + alienSpacing;
	invaderBig.emplace_back( d_loc, Invader::InvaderType::InvaderBig );
	for ( int i = 1; i < n_big / 2; i++ )
	{
		d_loc.x += i_dim.x + alienSpacing;
		invaderBig.emplace_back( d_loc, Invader::InvaderType::InvaderBig );
	}
	d_loc.x = loc.x;
	d_loc.y += i_dim.y + alienSpacing;
	invaderBig.emplace_back( d_loc, Invader::InvaderType::InvaderBig );
	for ( int i = 1 + n_big / 2; i < n_big; i++ )
	{
		d_loc.x += i_dim.x + alienSpacing;
		invaderBig.emplace_back( d_loc, Invader::InvaderType::InvaderBig );
	}
	//dimention
	dim.x = Invader::dimBig.x * 15 + alienSpacing * 14;
	dim.y = Invader::dimBig.y * 2 + Invader::dimMid.y * 2 + Invader::dimSmall.y + alienSpacing * 4;
}

void Alien::Draw()
{
	//small
	Vec2<int> i_dim = Invader::dimSmall;
	Vec2<int> iBig_dim = Invader::dimBig;
	Vec2<float> d_loc = loc;
	invaderSmall[0].Draw( gfx,d_loc );
	for ( int i = 1; i < n_small; i++ )
	{
		d_loc.x += iBig_dim.x + alienSpacing;
		invaderSmall[i].Draw( gfx,d_loc );
	}
	//mid
	i_dim = Invader::dimMid;
	d_loc.x = loc.x;
	d_loc.y += i_dim.y + alienSpacing;
	invaderMid[0].Draw( gfx,d_loc );
	for ( int i = 1; i < n_mid / 2; i++ )
	{
		d_loc.x += iBig_dim.x + alienSpacing;
		invaderMid[i].Draw( gfx,d_loc );
	}
	d_loc.x = loc.x;
	d_loc.y += i_dim.y + alienSpacing;
	invaderMid[n_mid / 2].Draw( gfx,d_loc );
	for ( int i = 1 + n_mid / 2; i < n_mid; i++ )
	{
		d_loc.x += iBig_dim.x + alienSpacing;
		invaderMid[i].Draw( gfx,d_loc );
	}
	//big
	i_dim = Invader::dimBig;
	d_loc.x = loc.x;
	d_loc.y += i_dim.y + alienSpacing;
	invaderBig[0].Draw( gfx,d_loc );
	for ( int i = 1; i < n_big / 2; i++ )
	{
		d_loc.x += i_dim.x + alienSpacing;
		invaderBig[i].Draw( gfx,d_loc );
	}
	d_loc.x = loc.x;
	d_loc.y += i_dim.y + alienSpacing;
	invaderBig[n_big / 2].Draw( gfx,d_loc );
	for ( int i = 1 + n_big / 2; i < n_big; i++ )
	{
		d_loc.x += i_dim.x + alienSpacing;
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
		Vec2<float> new_loc = loc;
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
	int roll = chanceDist( rng );
	if ( roll <= shotChance )
	{
		int loc = shotDist( rng );
		//find a free shot
		for( int i = 0; i < shotMax; i++ )
		{
			if( !shot[i].IsAlive() )
			{
				//Get bottom Alien
				Vec2<float> shotLoc;
				Vec2<int> shotDim;
				if( invaderBig[loc + 15].IsAlive() )
				{
					shotLoc = invaderBig[loc + 15].GetLoc();
					shotDim = Invader::dimBig;
				}
				else if( invaderBig[loc].IsAlive() )
				{
					shotLoc = invaderBig[loc].GetLoc();
					shotDim = Invader::dimBig;
				}
				else if( invaderMid[loc + 15].IsAlive() )
				{
					shotLoc = invaderMid[loc + 15].GetLoc();
					shotDim = Invader::dimMid;
				}
				else if( invaderMid[loc].IsAlive() )
				{
					shotLoc = invaderMid[loc].GetLoc();
					shotDim = Invader::dimMid;
				}
				else if( invaderSmall[loc].IsAlive() )
				{
					shotLoc = invaderSmall[loc].GetLoc();
					shotDim = Invader::dimSmall;
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

bool Alien::Collision( const Vec2<float>& in_loc,const Vec2<int>& in_dim )
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

const Vec2<float> Alien::GetShotLoc( const int i ) const
{
	return shot[i].GetLoc();
}

const Vec2<int>& Alien::GetShotDim() const
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

bool Alien::OutsideBorder( const Vec2<float> & in_loc,const Vec2<int>& in_dim )
{
	const float left = in_loc.x;
	const float right = in_loc.x + in_dim.x;
	const float top = in_loc.y;
	const float bottom = in_loc.y + in_dim.y;

	return left < 0 ||
		right >= gfx.ScreenWidth ||
		top < 0 ||
		bottom >= gfx.ScreenHeight;
}
