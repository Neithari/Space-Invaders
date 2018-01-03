#include "Alien.h"

Alien::Alien( Graphics& gfx, const int shotMax, const int shotChance, const Rect<float>* in_pPlaySpace )
	:
	gfx( gfx ),
	shotMax( shotMax ),
	rng( rd() ),
	chanceDist( 1,100 ),
	shotDist( 0,columns - 1 ),
	shotChance( shotChance ),
	// there is a bug with the in_playspace not upating correctly after change of a parameter in game.cpp or game.h
	// bug occurse even with a couple diffrent code locations. It's maybe a compiler didn't initialize the variable
	// yet problem not sure
	// only occuring in release. Everything is fine in develop.
	pPlaySpace( in_pPlaySpace )
{
	//set start loc
	loc.x = (float)pPlaySpace->left;
	loc.y = (float)pPlaySpace->top;
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
	dim.x = Invader::dimBig.x * columns + alienSpacing * ( columns - 1 );
	dim.y = Invader::dimBig.y * 2 + Invader::dimMid.y * 2 + Invader::dimSmall.y + alienSpacing * 4;
	area = Rect<float>( loc, dim.x, dim.y );
	//update invaderAlive
	UpdateInvaderAlive();
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

bool Alien::Update( const float dt )
{
	//Move invader
	if ( moveTime <= moveSpeed )
	{
		//check if new location is inside playSpace and set the move direction accordingly
		Rect<float> alienField = area;
		alienField.left += delta_loc.x;
		alienField.top += delta_loc.y;
		if ( !alienField.IsContainedBy( *pPlaySpace ) )
		{
			delta_loc.x = -delta_loc.x;
			delta_loc.y = alienSpacing;
			loc += delta_loc;
			delta_loc.y = 0;
			//check if bottom row reached earth
			SetArea();
			if( area.bottom > pPlaySpace->bottom )
			{
				return false;
			}
		}
		else
		{
			loc += delta_loc;
			SetArea();
		}
		moveTime = 1.0f;
	}
	else
	{
		moveTime -= dt;
	}
	//Shot creation
	int roll = chanceDist( rng );
	if ( roll <= shotChance )
	{
		int col = shotDist( rng );
		//find a free shot
		for( int i = 0; i < shotMax; i++ )
		{
			if( !shot[i].IsAlive() )
			{
				//Get bottom Alien
				Vec2<float> shotLoc;
				Vec2<int> shotDim;
				if( invaderBig[col + columns].IsAlive() )
				{
					shotLoc = invaderBig[col + columns].GetLoc();
					shotDim = Invader::dimBig;
				}
				else if( invaderBig[col].IsAlive() )
				{
					shotLoc = invaderBig[col].GetLoc();
					shotDim = Invader::dimBig;
				}
				else if( invaderMid[col + columns].IsAlive() )
				{
					shotLoc = invaderMid[col + columns].GetLoc();
					shotDim = Invader::dimMid;
				}
				else if( invaderMid[col].IsAlive() )
				{
					shotLoc = invaderMid[col].GetLoc();
					shotDim = Invader::dimMid;
				}
				else if( invaderSmall[col].IsAlive() )
				{
					shotLoc = invaderSmall[col].GetLoc();
					shotDim = Invader::dimSmall;
				}
				else
				{
					columnClean[col] = true;
				}
				if( !columnClean[col] )
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
	//check if speed need to increase
	IncreaseSpeed();
	return true;
}

bool Alien::Collision( const Vec2<float>& in_loc,const Vec2<int>& in_dim, unsigned int& score )
{
	return Collision( Rect<float>( in_loc, in_dim.x, in_dim.y ), score );
}

bool Alien::Collision( const Rect<float>& other, unsigned int& score )
{
	for( int i = 0; i < n_big; i++ )
	{
		if( invaderBig[i].IsAlive() )
		{
			if( invaderBig[i].Collision( other ) )
			{
				count_big--;
				score += 10;
				return true;
			}
		}
	}
	for( int i = 0; i < n_mid; i++ )
	{
		if( invaderMid[i].IsAlive() )
		{
			if( invaderMid[i].Collision( other ) )
			{
				count_mid--;
				score += 20;
				return true;
			}
		}
	}
	for( int i = 0; i < n_small; i++ )
	{
		if( invaderSmall[i].IsAlive() )
		{
			if( invaderSmall[i].Collision( other ) )
			{
				count_small--;
				score += 30;
				return true;
			}
		}
	}
	
	return false;
}

Vec2<float> Alien::GetShotLoc( const int i ) const
{
	return shot[i].GetLoc();
}

const Vec2<int>& Alien::GetShotDim() const
{
	return shot[0].GetDim();
}

Rect<float> Alien::GetShotRect( const int i ) const
{
	return Rect<float>( shot[i].GetLoc(), (float)shot[i].GetDim().x, (float)shot[i].GetDim().y );
}

bool Alien::IsShotAlive( const int i ) const
{
	return shot[i].IsAlive();
}

void Alien::DeleteShot( const int i )
{
	shot[i].Kill();
}

int Alien::Count() const
{
	return count_small + count_mid + count_big;
}

const Rect<float>& Alien::GetRect() const
{
	return area;
}

Rect<float> Alien::GetRectForRow( const int row ) const
{
	float left = loc.x;
	float right = loc.x + dim.x;
	float top = loc.y;
	float bottom = loc.y + dim.y;
	//get top
	for( int y = 0; y < row - 1; y++ )
	{
		top += Invader::dimBig.y + alienSpacing;
	}
	//get bottom
	bottom = top + Invader::dimBig.y;
	//get left
	bool colClean = true;
	for( int x = 0; x < columns; x++ )
	{
		if( invaderAlive[( row - 1 )*columns + x] )
		{
			colClean = false;
		}
		
		if( colClean )
		{
			left += Invader::dimBig.x + alienSpacing;
		}
		else
		{
			break;
		}
	}
	//get right
	colClean = true;
	for( int x = columns - 1; x >= 0; x-- )
	{
		if( invaderAlive[( row - 1 )*columns + x] )
		{
			colClean = false;
		}
		
		if( colClean )
		{
			right -= Invader::dimBig.x + alienSpacing;
		}
		else
		{
			break;
		}
	}
	
	return Rect<float>( left, right, top, bottom );
}

int Alien::GetBottomRow() const
{
	int bottom = rows;
	bool rowClean = true;
	for( int y = rows - 1; y >= 0; y-- )
	{
		for( int x = 0; x < columns; x++ )
		{
			if( invaderAlive[y*columns + x] )
			{
				rowClean = false;
			}
		}
		if( rowClean )
		{
			bottom--;
		}
		else
		{
			break;
		}
	}
	return bottom;
}

std::vector<Rect<float>> Alien::GetAliensForRow( const int row ) const
{
	std::vector<Rect<float>> alienRects;
	for( int x = 0; x < columns; x++ )
	{
		if( row > 4 )
		{
			if( invaderBig[x + columns].IsAlive() )
			{
				alienRects.emplace_back( invaderBig[x + columns].GetRect() );
			}
		}
		else if( row > 3 )
		{
			if( invaderBig[x].IsAlive() )
			{
				alienRects.emplace_back( invaderBig[x].GetRect() );
			}
		}
		else if( row > 2 )
		{
			if( invaderMid[x + columns].IsAlive() )
			{
				alienRects.emplace_back( invaderMid[x + columns].GetRect() );
			}
		}
		else if( row > 1 )
		{
			if( invaderMid[x].IsAlive() )
			{
				alienRects.emplace_back( invaderMid[x].GetRect() );
			}
		}
		else
		{
			if( invaderSmall[x].IsAlive() )
			{
				alienRects.emplace_back( invaderSmall[x].GetRect() );
			}
		}
	}
	return alienRects;
}

Alien::~Alien()
{
	pPlaySpace = nullptr;
}

void Alien::IncreaseSpeed()
{
	if( !( moveSpeed > 0.95f ) )
	{
		if( ( Count() % 5 ) == 0 && Count() != ( n_small + n_mid + n_big ) && !speedIncreased )
		{
			moveSpeed += increaseSpeed;
			speedIncreased = true;
		}
		if( speedIncreased && ( Count() % 5 ) != 0 )
		{
			speedIncreased = false;
		}
	}
}

void Alien::SetArea()
{
	UpdateInvaderAlive();
	float left = loc.x;
	float right = loc.x + dim.x;
	float top = loc.y;
	float bottom = loc.y + dim.y;
	//get left
	bool colClean = true;
	for( int x = 0; x < columns; x++ )
	{
		for( int y = 0; y < rows; y++ )
		{
			if( invaderAlive[y*columns + x] )
			{
				colClean = false;
			}
		}
		if( colClean )
		{
			left += Invader::dimBig.x + alienSpacing;
		}
		else
		{
			break;
		}
	}
	//get right
	colClean = true;
	for( int x = columns - 1; x >= 0; x-- )
	{
		for( int y = 0; y < rows; y++ )
		{
			if( invaderAlive[y*columns + x] )
			{
				colClean = false;
			}
		}
		if( colClean )
		{
			right -= Invader::dimBig.x + alienSpacing;
		}
		else
		{
			break;
		}
	}
	//get top
	bool rowClean = true;
	for( int y = 0; y < rows; y++ )
	{
		for( int x = 0; x < columns; x++ )
		{
			if( invaderAlive[y*columns + x] )
			{
				rowClean = false;
			}
		}
		if( rowClean )
		{
			top += Invader::dimBig.y + alienSpacing;
		}
		else
		{
			break;
		}
	}
	//get bottom
	rowClean = true;
	for( int y = rows - 1; y >= 0; y-- )
	{
		for( int x = 0; x < columns; x++ )
		{
			if( invaderAlive[y*columns + x] )
			{
				rowClean = false;
			}
		}
		if( rowClean )
		{
			bottom -= Invader::dimBig.y + alienSpacing;
		}
		else
		{
			break;
		}
	}
	area = Rect<float>( left, right, top, bottom );
}

void Alien::UpdateInvaderAlive()
{
	for( int i = 0; i < n_small; i++ )
	{
		invaderAlive[i] = invaderSmall[i].IsAlive();
	}
	for( int i = 0; i < n_mid; i++ )
	{
		invaderAlive[n_small + i] = invaderMid[i].IsAlive();
	}
	for( int i = 0; i < n_big; i++ )
	{
		invaderAlive[n_small + n_mid + i] = invaderBig[i].IsAlive();
	}
}
