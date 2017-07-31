#include "InvaderBig.h"

void InvaderBig::Draw( Graphics& gfx,const Location& in_loc )
{
	loc = in_loc;
	if ( isAlive )
	{
		if ( toggle )
		{
			DrawMove0( gfx );
			if ( toggleIndex >= toggleTime )
			{
				toggle = false;
				toggleIndex = 0;
			}
			toggleIndex++;
		}
		else
		{
			DrawMove1( gfx );
			if ( toggleIndex >= toggleTime )
			{
				toggle = true;
				toggleIndex = 0;
			}
			toggleIndex++;
		}
	}
}

void InvaderBig::DrawMove0( Graphics& gfx ) const
{
	if ( isAlive )
	{
		int x = int( loc.x );
		int y = int( loc.y );
		//width = 24;
		//height = 16;

		gfx.PutPixel( 8 + x,0 + y,0,77,100 );
		gfx.PutPixel( 9 + x,0 + y,0,77,100 );
		gfx.PutPixel( 10 + x,0 + y,0,77,100 );
		gfx.PutPixel( 11 + x,0 + y,0,77,100 );
		gfx.PutPixel( 12 + x,0 + y,0,77,100 );
		gfx.PutPixel( 13 + x,0 + y,0,77,100 );
		gfx.PutPixel( 14 + x,0 + y,0,77,100 );
		gfx.PutPixel( 15 + x,0 + y,0,77,100 );
		gfx.PutPixel( 8 + x,1 + y,0,77,100 );
		gfx.PutPixel( 9 + x,1 + y,0,77,100 );
		gfx.PutPixel( 10 + x,1 + y,0,77,100 );
		gfx.PutPixel( 11 + x,1 + y,0,77,100 );
		gfx.PutPixel( 12 + x,1 + y,0,77,100 );
		gfx.PutPixel( 13 + x,1 + y,0,77,100 );
		gfx.PutPixel( 14 + x,1 + y,0,77,100 );
		gfx.PutPixel( 15 + x,1 + y,0,77,100 );
		gfx.PutPixel( 2 + x,2 + y,0,77,100 );
		gfx.PutPixel( 3 + x,2 + y,0,77,100 );
		gfx.PutPixel( 4 + x,2 + y,0,77,100 );
		gfx.PutPixel( 5 + x,2 + y,0,77,100 );
		gfx.PutPixel( 6 + x,2 + y,0,77,100 );
		gfx.PutPixel( 7 + x,2 + y,0,77,100 );
		gfx.PutPixel( 8 + x,2 + y,0,77,100 );
		gfx.PutPixel( 9 + x,2 + y,0,77,100 );
		gfx.PutPixel( 10 + x,2 + y,0,77,100 );
		gfx.PutPixel( 11 + x,2 + y,0,77,100 );
		gfx.PutPixel( 12 + x,2 + y,0,77,100 );
		gfx.PutPixel( 13 + x,2 + y,0,77,100 );
		gfx.PutPixel( 14 + x,2 + y,0,77,100 );
		gfx.PutPixel( 15 + x,2 + y,0,77,100 );
		gfx.PutPixel( 16 + x,2 + y,0,77,100 );
		gfx.PutPixel( 17 + x,2 + y,0,77,100 );
		gfx.PutPixel( 18 + x,2 + y,0,77,100 );
		gfx.PutPixel( 19 + x,2 + y,0,77,100 );
		gfx.PutPixel( 20 + x,2 + y,0,77,100 );
		gfx.PutPixel( 21 + x,2 + y,0,77,100 );
		gfx.PutPixel( 2 + x,3 + y,0,77,100 );
		gfx.PutPixel( 3 + x,3 + y,0,77,100 );
		gfx.PutPixel( 4 + x,3 + y,0,77,100 );
		gfx.PutPixel( 5 + x,3 + y,0,77,100 );
		gfx.PutPixel( 6 + x,3 + y,0,77,100 );
		gfx.PutPixel( 7 + x,3 + y,0,77,100 );
		gfx.PutPixel( 8 + x,3 + y,0,77,100 );
		gfx.PutPixel( 9 + x,3 + y,0,77,100 );
		gfx.PutPixel( 10 + x,3 + y,0,77,100 );
		gfx.PutPixel( 11 + x,3 + y,0,77,100 );
		gfx.PutPixel( 12 + x,3 + y,0,77,100 );
		gfx.PutPixel( 13 + x,3 + y,0,77,100 );
		gfx.PutPixel( 14 + x,3 + y,0,77,100 );
		gfx.PutPixel( 15 + x,3 + y,0,77,100 );
		gfx.PutPixel( 16 + x,3 + y,0,77,100 );
		gfx.PutPixel( 17 + x,3 + y,0,77,100 );
		gfx.PutPixel( 18 + x,3 + y,0,77,100 );
		gfx.PutPixel( 19 + x,3 + y,0,77,100 );
		gfx.PutPixel( 20 + x,3 + y,0,77,100 );
		gfx.PutPixel( 21 + x,3 + y,0,77,100 );
		gfx.PutPixel( 0 + x,4 + y,0,77,100 );
		gfx.PutPixel( 1 + x,4 + y,0,77,100 );
		gfx.PutPixel( 2 + x,4 + y,0,77,100 );
		gfx.PutPixel( 3 + x,4 + y,0,77,100 );
		gfx.PutPixel( 4 + x,4 + y,0,77,100 );
		gfx.PutPixel( 5 + x,4 + y,0,77,100 );
		gfx.PutPixel( 6 + x,4 + y,0,77,100 );
		gfx.PutPixel( 7 + x,4 + y,0,77,100 );
		gfx.PutPixel( 8 + x,4 + y,0,77,100 );
		gfx.PutPixel( 9 + x,4 + y,0,77,100 );
		gfx.PutPixel( 10 + x,4 + y,0,77,100 );
		gfx.PutPixel( 11 + x,4 + y,0,77,100 );
		gfx.PutPixel( 12 + x,4 + y,0,77,100 );
		gfx.PutPixel( 13 + x,4 + y,0,77,100 );
		gfx.PutPixel( 14 + x,4 + y,0,77,100 );
		gfx.PutPixel( 15 + x,4 + y,0,77,100 );
		gfx.PutPixel( 16 + x,4 + y,0,77,100 );
		gfx.PutPixel( 17 + x,4 + y,0,77,100 );
		gfx.PutPixel( 18 + x,4 + y,0,77,100 );
		gfx.PutPixel( 19 + x,4 + y,0,77,100 );
		gfx.PutPixel( 20 + x,4 + y,0,77,100 );
		gfx.PutPixel( 21 + x,4 + y,0,77,100 );
		gfx.PutPixel( 22 + x,4 + y,0,77,100 );
		gfx.PutPixel( 23 + x,4 + y,0,77,100 );
		gfx.PutPixel( 0 + x,5 + y,0,77,100 );
		gfx.PutPixel( 1 + x,5 + y,0,77,100 );
		gfx.PutPixel( 2 + x,5 + y,0,77,100 );
		gfx.PutPixel( 3 + x,5 + y,0,77,100 );
		gfx.PutPixel( 4 + x,5 + y,0,77,100 );
		gfx.PutPixel( 5 + x,5 + y,0,77,100 );
		gfx.PutPixel( 6 + x,5 + y,0,77,100 );
		gfx.PutPixel( 7 + x,5 + y,0,77,100 );
		gfx.PutPixel( 8 + x,5 + y,0,77,100 );
		gfx.PutPixel( 9 + x,5 + y,0,77,100 );
		gfx.PutPixel( 10 + x,5 + y,0,77,100 );
		gfx.PutPixel( 11 + x,5 + y,0,77,100 );
		gfx.PutPixel( 12 + x,5 + y,0,77,100 );
		gfx.PutPixel( 13 + x,5 + y,0,77,100 );
		gfx.PutPixel( 14 + x,5 + y,0,77,100 );
		gfx.PutPixel( 15 + x,5 + y,0,77,100 );
		gfx.PutPixel( 16 + x,5 + y,0,77,100 );
		gfx.PutPixel( 17 + x,5 + y,0,77,100 );
		gfx.PutPixel( 18 + x,5 + y,0,77,100 );
		gfx.PutPixel( 19 + x,5 + y,0,77,100 );
		gfx.PutPixel( 20 + x,5 + y,0,77,100 );
		gfx.PutPixel( 21 + x,5 + y,0,77,100 );
		gfx.PutPixel( 22 + x,5 + y,0,77,100 );
		gfx.PutPixel( 23 + x,5 + y,0,77,100 );
		gfx.PutPixel( 0 + x,6 + y,0,77,100 );
		gfx.PutPixel( 1 + x,6 + y,0,77,100 );
		gfx.PutPixel( 2 + x,6 + y,0,77,100 );
		gfx.PutPixel( 3 + x,6 + y,0,77,100 );
		gfx.PutPixel( 4 + x,6 + y,0,77,100 );
		gfx.PutPixel( 5 + x,6 + y,0,77,100 );
		gfx.PutPixel( 10 + x,6 + y,0,77,100 );
		gfx.PutPixel( 11 + x,6 + y,0,77,100 );
		gfx.PutPixel( 12 + x,6 + y,0,77,100 );
		gfx.PutPixel( 13 + x,6 + y,0,77,100 );
		gfx.PutPixel( 18 + x,6 + y,0,77,100 );
		gfx.PutPixel( 19 + x,6 + y,0,77,100 );
		gfx.PutPixel( 20 + x,6 + y,0,77,100 );
		gfx.PutPixel( 21 + x,6 + y,0,77,100 );
		gfx.PutPixel( 22 + x,6 + y,0,77,100 );
		gfx.PutPixel( 23 + x,6 + y,0,77,100 );
		gfx.PutPixel( 0 + x,7 + y,0,77,100 );
		gfx.PutPixel( 1 + x,7 + y,0,77,100 );
		gfx.PutPixel( 2 + x,7 + y,0,77,100 );
		gfx.PutPixel( 3 + x,7 + y,0,77,100 );
		gfx.PutPixel( 4 + x,7 + y,0,77,100 );
		gfx.PutPixel( 5 + x,7 + y,0,77,100 );
		gfx.PutPixel( 10 + x,7 + y,0,77,100 );
		gfx.PutPixel( 11 + x,7 + y,0,77,100 );
		gfx.PutPixel( 12 + x,7 + y,0,77,100 );
		gfx.PutPixel( 13 + x,7 + y,0,77,100 );
		gfx.PutPixel( 18 + x,7 + y,0,77,100 );
		gfx.PutPixel( 19 + x,7 + y,0,77,100 );
		gfx.PutPixel( 20 + x,7 + y,0,77,100 );
		gfx.PutPixel( 21 + x,7 + y,0,77,100 );
		gfx.PutPixel( 22 + x,7 + y,0,77,100 );
		gfx.PutPixel( 23 + x,7 + y,0,77,100 );
		gfx.PutPixel( 0 + x,8 + y,0,77,100 );
		gfx.PutPixel( 1 + x,8 + y,0,77,100 );
		gfx.PutPixel( 2 + x,8 + y,0,77,100 );
		gfx.PutPixel( 3 + x,8 + y,0,77,100 );
		gfx.PutPixel( 4 + x,8 + y,0,77,100 );
		gfx.PutPixel( 5 + x,8 + y,0,77,100 );
		gfx.PutPixel( 6 + x,8 + y,0,77,100 );
		gfx.PutPixel( 7 + x,8 + y,0,77,100 );
		gfx.PutPixel( 8 + x,8 + y,0,77,100 );
		gfx.PutPixel( 9 + x,8 + y,0,77,100 );
		gfx.PutPixel( 10 + x,8 + y,0,77,100 );
		gfx.PutPixel( 11 + x,8 + y,0,77,100 );
		gfx.PutPixel( 12 + x,8 + y,0,77,100 );
		gfx.PutPixel( 13 + x,8 + y,0,77,100 );
		gfx.PutPixel( 14 + x,8 + y,0,77,100 );
		gfx.PutPixel( 15 + x,8 + y,0,77,100 );
		gfx.PutPixel( 16 + x,8 + y,0,77,100 );
		gfx.PutPixel( 17 + x,8 + y,0,77,100 );
		gfx.PutPixel( 18 + x,8 + y,0,77,100 );
		gfx.PutPixel( 19 + x,8 + y,0,77,100 );
		gfx.PutPixel( 20 + x,8 + y,0,77,100 );
		gfx.PutPixel( 21 + x,8 + y,0,77,100 );
		gfx.PutPixel( 22 + x,8 + y,0,77,100 );
		gfx.PutPixel( 23 + x,8 + y,0,77,100 );
		gfx.PutPixel( 0 + x,9 + y,0,77,100 );
		gfx.PutPixel( 1 + x,9 + y,0,77,100 );
		gfx.PutPixel( 2 + x,9 + y,0,77,100 );
		gfx.PutPixel( 3 + x,9 + y,0,77,100 );
		gfx.PutPixel( 4 + x,9 + y,0,77,100 );
		gfx.PutPixel( 5 + x,9 + y,0,77,100 );
		gfx.PutPixel( 6 + x,9 + y,0,77,100 );
		gfx.PutPixel( 7 + x,9 + y,0,77,100 );
		gfx.PutPixel( 8 + x,9 + y,0,77,100 );
		gfx.PutPixel( 9 + x,9 + y,0,77,100 );
		gfx.PutPixel( 10 + x,9 + y,0,77,100 );
		gfx.PutPixel( 11 + x,9 + y,0,77,100 );
		gfx.PutPixel( 12 + x,9 + y,0,77,100 );
		gfx.PutPixel( 13 + x,9 + y,0,77,100 );
		gfx.PutPixel( 14 + x,9 + y,0,77,100 );
		gfx.PutPixel( 15 + x,9 + y,0,77,100 );
		gfx.PutPixel( 16 + x,9 + y,0,77,100 );
		gfx.PutPixel( 17 + x,9 + y,0,77,100 );
		gfx.PutPixel( 18 + x,9 + y,0,77,100 );
		gfx.PutPixel( 19 + x,9 + y,0,77,100 );
		gfx.PutPixel( 20 + x,9 + y,0,77,100 );
		gfx.PutPixel( 21 + x,9 + y,0,77,100 );
		gfx.PutPixel( 22 + x,9 + y,0,77,100 );
		gfx.PutPixel( 23 + x,9 + y,0,77,100 );
		gfx.PutPixel( 6 + x,10 + y,252,114,3 );
		gfx.PutPixel( 7 + x,10 + y,252,114,3 );
		gfx.PutPixel( 8 + x,10 + y,252,114,3 );
		gfx.PutPixel( 9 + x,10 + y,252,114,3 );
		gfx.PutPixel( 14 + x,10 + y,252,114,3 );
		gfx.PutPixel( 15 + x,10 + y,252,114,3 );
		gfx.PutPixel( 16 + x,10 + y,252,114,3 );
		gfx.PutPixel( 17 + x,10 + y,252,114,3 );
		gfx.PutPixel( 6 + x,11 + y,252,114,3 );
		gfx.PutPixel( 7 + x,11 + y,252,114,3 );
		gfx.PutPixel( 8 + x,11 + y,252,114,3 );
		gfx.PutPixel( 9 + x,11 + y,252,114,3 );
		gfx.PutPixel( 14 + x,11 + y,252,114,3 );
		gfx.PutPixel( 15 + x,11 + y,252,114,3 );
		gfx.PutPixel( 16 + x,11 + y,252,114,3 );
		gfx.PutPixel( 17 + x,11 + y,252,114,3 );
		gfx.PutPixel( 4 + x,12 + y,252,114,3 );
		gfx.PutPixel( 5 + x,12 + y,252,114,3 );
		gfx.PutPixel( 6 + x,12 + y,252,114,3 );
		gfx.PutPixel( 7 + x,12 + y,252,114,3 );
		gfx.PutPixel( 10 + x,12 + y,252,114,3 );
		gfx.PutPixel( 11 + x,12 + y,252,114,3 );
		gfx.PutPixel( 12 + x,12 + y,252,114,3 );
		gfx.PutPixel( 13 + x,12 + y,252,114,3 );
		gfx.PutPixel( 16 + x,12 + y,252,114,3 );
		gfx.PutPixel( 17 + x,12 + y,252,114,3 );
		gfx.PutPixel( 18 + x,12 + y,252,114,3 );
		gfx.PutPixel( 19 + x,12 + y,252,114,3 );
		gfx.PutPixel( 4 + x,13 + y,252,114,3 );
		gfx.PutPixel( 5 + x,13 + y,252,114,3 );
		gfx.PutPixel( 6 + x,13 + y,252,114,3 );
		gfx.PutPixel( 7 + x,13 + y,252,114,3 );
		gfx.PutPixel( 10 + x,13 + y,252,114,3 );
		gfx.PutPixel( 11 + x,13 + y,252,114,3 );
		gfx.PutPixel( 12 + x,13 + y,252,114,3 );
		gfx.PutPixel( 13 + x,13 + y,252,114,3 );
		gfx.PutPixel( 16 + x,13 + y,252,114,3 );
		gfx.PutPixel( 17 + x,13 + y,252,114,3 );
		gfx.PutPixel( 18 + x,13 + y,252,114,3 );
		gfx.PutPixel( 19 + x,13 + y,252,114,3 );
		gfx.PutPixel( 0 + x,14 + y,252,114,3 );
		gfx.PutPixel( 1 + x,14 + y,252,114,3 );
		gfx.PutPixel( 2 + x,14 + y,252,114,3 );
		gfx.PutPixel( 3 + x,14 + y,252,114,3 );
		gfx.PutPixel( 20 + x,14 + y,252,114,3 );
		gfx.PutPixel( 21 + x,14 + y,252,114,3 );
		gfx.PutPixel( 22 + x,14 + y,252,114,3 );
		gfx.PutPixel( 23 + x,14 + y,252,114,3 );
		gfx.PutPixel( 0 + x,15 + y,252,114,3 );
		gfx.PutPixel( 1 + x,15 + y,252,114,3 );
		gfx.PutPixel( 2 + x,15 + y,252,114,3 );
		gfx.PutPixel( 3 + x,15 + y,252,114,3 );
		gfx.PutPixel( 20 + x,15 + y,252,114,3 );
		gfx.PutPixel( 21 + x,15 + y,252,114,3 );
		gfx.PutPixel( 22 + x,15 + y,252,114,3 );
		gfx.PutPixel( 23 + x,15 + y,252,114,3 );
	}
}

void InvaderBig::DrawMove1( Graphics& gfx ) const
{
	if ( isAlive )
	{
		int x = int( loc.x );
		int y = int( loc.y );
		//width = 24;
		//height = 16;

		gfx.PutPixel( 8 + x,0 + y,0,77,100 );
		gfx.PutPixel( 9 + x,0 + y,0,77,100 );
		gfx.PutPixel( 10 + x,0 + y,0,77,100 );
		gfx.PutPixel( 11 + x,0 + y,0,77,100 );
		gfx.PutPixel( 12 + x,0 + y,0,77,100 );
		gfx.PutPixel( 13 + x,0 + y,0,77,100 );
		gfx.PutPixel( 14 + x,0 + y,0,77,100 );
		gfx.PutPixel( 15 + x,0 + y,0,77,100 );
		gfx.PutPixel( 8 + x,1 + y,0,77,100 );
		gfx.PutPixel( 9 + x,1 + y,0,77,100 );
		gfx.PutPixel( 10 + x,1 + y,0,77,100 );
		gfx.PutPixel( 11 + x,1 + y,0,77,100 );
		gfx.PutPixel( 12 + x,1 + y,0,77,100 );
		gfx.PutPixel( 13 + x,1 + y,0,77,100 );
		gfx.PutPixel( 14 + x,1 + y,0,77,100 );
		gfx.PutPixel( 15 + x,1 + y,0,77,100 );
		gfx.PutPixel( 2 + x,2 + y,0,77,100 );
		gfx.PutPixel( 3 + x,2 + y,0,77,100 );
		gfx.PutPixel( 4 + x,2 + y,0,77,100 );
		gfx.PutPixel( 5 + x,2 + y,0,77,100 );
		gfx.PutPixel( 6 + x,2 + y,0,77,100 );
		gfx.PutPixel( 7 + x,2 + y,0,77,100 );
		gfx.PutPixel( 8 + x,2 + y,0,77,100 );
		gfx.PutPixel( 9 + x,2 + y,0,77,100 );
		gfx.PutPixel( 10 + x,2 + y,0,77,100 );
		gfx.PutPixel( 11 + x,2 + y,0,77,100 );
		gfx.PutPixel( 12 + x,2 + y,0,77,100 );
		gfx.PutPixel( 13 + x,2 + y,0,77,100 );
		gfx.PutPixel( 14 + x,2 + y,0,77,100 );
		gfx.PutPixel( 15 + x,2 + y,0,77,100 );
		gfx.PutPixel( 16 + x,2 + y,0,77,100 );
		gfx.PutPixel( 17 + x,2 + y,0,77,100 );
		gfx.PutPixel( 18 + x,2 + y,0,77,100 );
		gfx.PutPixel( 19 + x,2 + y,0,77,100 );
		gfx.PutPixel( 20 + x,2 + y,0,77,100 );
		gfx.PutPixel( 21 + x,2 + y,0,77,100 );
		gfx.PutPixel( 2 + x,3 + y,0,77,100 );
		gfx.PutPixel( 3 + x,3 + y,0,77,100 );
		gfx.PutPixel( 4 + x,3 + y,0,77,100 );
		gfx.PutPixel( 5 + x,3 + y,0,77,100 );
		gfx.PutPixel( 6 + x,3 + y,0,77,100 );
		gfx.PutPixel( 7 + x,3 + y,0,77,100 );
		gfx.PutPixel( 8 + x,3 + y,0,77,100 );
		gfx.PutPixel( 9 + x,3 + y,0,77,100 );
		gfx.PutPixel( 10 + x,3 + y,0,77,100 );
		gfx.PutPixel( 11 + x,3 + y,0,77,100 );
		gfx.PutPixel( 12 + x,3 + y,0,77,100 );
		gfx.PutPixel( 13 + x,3 + y,0,77,100 );
		gfx.PutPixel( 14 + x,3 + y,0,77,100 );
		gfx.PutPixel( 15 + x,3 + y,0,77,100 );
		gfx.PutPixel( 16 + x,3 + y,0,77,100 );
		gfx.PutPixel( 17 + x,3 + y,0,77,100 );
		gfx.PutPixel( 18 + x,3 + y,0,77,100 );
		gfx.PutPixel( 19 + x,3 + y,0,77,100 );
		gfx.PutPixel( 20 + x,3 + y,0,77,100 );
		gfx.PutPixel( 21 + x,3 + y,0,77,100 );
		gfx.PutPixel( 0 + x,4 + y,0,77,100 );
		gfx.PutPixel( 1 + x,4 + y,0,77,100 );
		gfx.PutPixel( 2 + x,4 + y,0,77,100 );
		gfx.PutPixel( 3 + x,4 + y,0,77,100 );
		gfx.PutPixel( 4 + x,4 + y,0,77,100 );
		gfx.PutPixel( 5 + x,4 + y,0,77,100 );
		gfx.PutPixel( 6 + x,4 + y,0,77,100 );
		gfx.PutPixel( 7 + x,4 + y,0,77,100 );
		gfx.PutPixel( 8 + x,4 + y,0,77,100 );
		gfx.PutPixel( 9 + x,4 + y,0,77,100 );
		gfx.PutPixel( 10 + x,4 + y,0,77,100 );
		gfx.PutPixel( 11 + x,4 + y,0,77,100 );
		gfx.PutPixel( 12 + x,4 + y,0,77,100 );
		gfx.PutPixel( 13 + x,4 + y,0,77,100 );
		gfx.PutPixel( 14 + x,4 + y,0,77,100 );
		gfx.PutPixel( 15 + x,4 + y,0,77,100 );
		gfx.PutPixel( 16 + x,4 + y,0,77,100 );
		gfx.PutPixel( 17 + x,4 + y,0,77,100 );
		gfx.PutPixel( 18 + x,4 + y,0,77,100 );
		gfx.PutPixel( 19 + x,4 + y,0,77,100 );
		gfx.PutPixel( 20 + x,4 + y,0,77,100 );
		gfx.PutPixel( 21 + x,4 + y,0,77,100 );
		gfx.PutPixel( 22 + x,4 + y,0,77,100 );
		gfx.PutPixel( 23 + x,4 + y,0,77,100 );
		gfx.PutPixel( 0 + x,5 + y,0,77,100 );
		gfx.PutPixel( 1 + x,5 + y,0,77,100 );
		gfx.PutPixel( 2 + x,5 + y,0,77,100 );
		gfx.PutPixel( 3 + x,5 + y,0,77,100 );
		gfx.PutPixel( 4 + x,5 + y,0,77,100 );
		gfx.PutPixel( 5 + x,5 + y,0,77,100 );
		gfx.PutPixel( 6 + x,5 + y,0,77,100 );
		gfx.PutPixel( 7 + x,5 + y,0,77,100 );
		gfx.PutPixel( 8 + x,5 + y,0,77,100 );
		gfx.PutPixel( 9 + x,5 + y,0,77,100 );
		gfx.PutPixel( 10 + x,5 + y,0,77,100 );
		gfx.PutPixel( 11 + x,5 + y,0,77,100 );
		gfx.PutPixel( 12 + x,5 + y,0,77,100 );
		gfx.PutPixel( 13 + x,5 + y,0,77,100 );
		gfx.PutPixel( 14 + x,5 + y,0,77,100 );
		gfx.PutPixel( 15 + x,5 + y,0,77,100 );
		gfx.PutPixel( 16 + x,5 + y,0,77,100 );
		gfx.PutPixel( 17 + x,5 + y,0,77,100 );
		gfx.PutPixel( 18 + x,5 + y,0,77,100 );
		gfx.PutPixel( 19 + x,5 + y,0,77,100 );
		gfx.PutPixel( 20 + x,5 + y,0,77,100 );
		gfx.PutPixel( 21 + x,5 + y,0,77,100 );
		gfx.PutPixel( 22 + x,5 + y,0,77,100 );
		gfx.PutPixel( 23 + x,5 + y,0,77,100 );
		gfx.PutPixel( 0 + x,6 + y,0,77,100 );
		gfx.PutPixel( 1 + x,6 + y,0,77,100 );
		gfx.PutPixel( 2 + x,6 + y,0,77,100 );
		gfx.PutPixel( 3 + x,6 + y,0,77,100 );
		gfx.PutPixel( 4 + x,6 + y,0,77,100 );
		gfx.PutPixel( 5 + x,6 + y,0,77,100 );
		gfx.PutPixel( 10 + x,6 + y,0,77,100 );
		gfx.PutPixel( 11 + x,6 + y,0,77,100 );
		gfx.PutPixel( 12 + x,6 + y,0,77,100 );
		gfx.PutPixel( 13 + x,6 + y,0,77,100 );
		gfx.PutPixel( 18 + x,6 + y,0,77,100 );
		gfx.PutPixel( 19 + x,6 + y,0,77,100 );
		gfx.PutPixel( 20 + x,6 + y,0,77,100 );
		gfx.PutPixel( 21 + x,6 + y,0,77,100 );
		gfx.PutPixel( 22 + x,6 + y,0,77,100 );
		gfx.PutPixel( 23 + x,6 + y,0,77,100 );
		gfx.PutPixel( 0 + x,7 + y,0,77,100 );
		gfx.PutPixel( 1 + x,7 + y,0,77,100 );
		gfx.PutPixel( 2 + x,7 + y,0,77,100 );
		gfx.PutPixel( 3 + x,7 + y,0,77,100 );
		gfx.PutPixel( 4 + x,7 + y,0,77,100 );
		gfx.PutPixel( 5 + x,7 + y,0,77,100 );
		gfx.PutPixel( 10 + x,7 + y,0,77,100 );
		gfx.PutPixel( 11 + x,7 + y,0,77,100 );
		gfx.PutPixel( 12 + x,7 + y,0,77,100 );
		gfx.PutPixel( 13 + x,7 + y,0,77,100 );
		gfx.PutPixel( 18 + x,7 + y,0,77,100 );
		gfx.PutPixel( 19 + x,7 + y,0,77,100 );
		gfx.PutPixel( 20 + x,7 + y,0,77,100 );
		gfx.PutPixel( 21 + x,7 + y,0,77,100 );
		gfx.PutPixel( 22 + x,7 + y,0,77,100 );
		gfx.PutPixel( 23 + x,7 + y,0,77,100 );
		gfx.PutPixel( 0 + x,8 + y,0,77,100 );
		gfx.PutPixel( 1 + x,8 + y,0,77,100 );
		gfx.PutPixel( 2 + x,8 + y,0,77,100 );
		gfx.PutPixel( 3 + x,8 + y,0,77,100 );
		gfx.PutPixel( 4 + x,8 + y,0,77,100 );
		gfx.PutPixel( 5 + x,8 + y,0,77,100 );
		gfx.PutPixel( 6 + x,8 + y,0,77,100 );
		gfx.PutPixel( 7 + x,8 + y,0,77,100 );
		gfx.PutPixel( 8 + x,8 + y,0,77,100 );
		gfx.PutPixel( 9 + x,8 + y,0,77,100 );
		gfx.PutPixel( 10 + x,8 + y,0,77,100 );
		gfx.PutPixel( 11 + x,8 + y,0,77,100 );
		gfx.PutPixel( 12 + x,8 + y,0,77,100 );
		gfx.PutPixel( 13 + x,8 + y,0,77,100 );
		gfx.PutPixel( 14 + x,8 + y,0,77,100 );
		gfx.PutPixel( 15 + x,8 + y,0,77,100 );
		gfx.PutPixel( 16 + x,8 + y,0,77,100 );
		gfx.PutPixel( 17 + x,8 + y,0,77,100 );
		gfx.PutPixel( 18 + x,8 + y,0,77,100 );
		gfx.PutPixel( 19 + x,8 + y,0,77,100 );
		gfx.PutPixel( 20 + x,8 + y,0,77,100 );
		gfx.PutPixel( 21 + x,8 + y,0,77,100 );
		gfx.PutPixel( 22 + x,8 + y,0,77,100 );
		gfx.PutPixel( 23 + x,8 + y,0,77,100 );
		gfx.PutPixel( 0 + x,9 + y,0,77,100 );
		gfx.PutPixel( 1 + x,9 + y,0,77,100 );
		gfx.PutPixel( 2 + x,9 + y,0,77,100 );
		gfx.PutPixel( 3 + x,9 + y,0,77,100 );
		gfx.PutPixel( 4 + x,9 + y,0,77,100 );
		gfx.PutPixel( 5 + x,9 + y,0,77,100 );
		gfx.PutPixel( 6 + x,9 + y,0,77,100 );
		gfx.PutPixel( 7 + x,9 + y,0,77,100 );
		gfx.PutPixel( 8 + x,9 + y,0,77,100 );
		gfx.PutPixel( 9 + x,9 + y,0,77,100 );
		gfx.PutPixel( 10 + x,9 + y,0,77,100 );
		gfx.PutPixel( 11 + x,9 + y,0,77,100 );
		gfx.PutPixel( 12 + x,9 + y,0,77,100 );
		gfx.PutPixel( 13 + x,9 + y,0,77,100 );
		gfx.PutPixel( 14 + x,9 + y,0,77,100 );
		gfx.PutPixel( 15 + x,9 + y,0,77,100 );
		gfx.PutPixel( 16 + x,9 + y,0,77,100 );
		gfx.PutPixel( 17 + x,9 + y,0,77,100 );
		gfx.PutPixel( 18 + x,9 + y,0,77,100 );
		gfx.PutPixel( 19 + x,9 + y,0,77,100 );
		gfx.PutPixel( 20 + x,9 + y,0,77,100 );
		gfx.PutPixel( 21 + x,9 + y,0,77,100 );
		gfx.PutPixel( 22 + x,9 + y,0,77,100 );
		gfx.PutPixel( 23 + x,9 + y,0,77,100 );
		gfx.PutPixel( 4 + x,10 + y,252,114,3 );
		gfx.PutPixel( 5 + x,10 + y,252,114,3 );
		gfx.PutPixel( 6 + x,10 + y,252,114,3 );
		gfx.PutPixel( 7 + x,10 + y,252,114,3 );
		gfx.PutPixel( 8 + x,10 + y,252,114,3 );
		gfx.PutPixel( 9 + x,10 + y,252,114,3 );
		gfx.PutPixel( 14 + x,10 + y,252,114,3 );
		gfx.PutPixel( 15 + x,10 + y,252,114,3 );
		gfx.PutPixel( 16 + x,10 + y,252,114,3 );
		gfx.PutPixel( 17 + x,10 + y,252,114,3 );
		gfx.PutPixel( 18 + x,10 + y,252,114,3 );
		gfx.PutPixel( 19 + x,10 + y,252,114,3 );
		gfx.PutPixel( 4 + x,11 + y,252,114,3 );
		gfx.PutPixel( 5 + x,11 + y,252,114,3 );
		gfx.PutPixel( 6 + x,11 + y,252,114,3 );
		gfx.PutPixel( 7 + x,11 + y,252,114,3 );
		gfx.PutPixel( 8 + x,11 + y,252,114,3 );
		gfx.PutPixel( 9 + x,11 + y,252,114,3 );
		gfx.PutPixel( 14 + x,11 + y,252,114,3 );
		gfx.PutPixel( 15 + x,11 + y,252,114,3 );
		gfx.PutPixel( 16 + x,11 + y,252,114,3 );
		gfx.PutPixel( 17 + x,11 + y,252,114,3 );
		gfx.PutPixel( 18 + x,11 + y,252,114,3 );
		gfx.PutPixel( 19 + x,11 + y,252,114,3 );
		gfx.PutPixel( 2 + x,12 + y,252,114,3 );
		gfx.PutPixel( 3 + x,12 + y,252,114,3 );
		gfx.PutPixel( 4 + x,12 + y,252,114,3 );
		gfx.PutPixel( 5 + x,12 + y,252,114,3 );
		gfx.PutPixel( 10 + x,12 + y,252,114,3 );
		gfx.PutPixel( 11 + x,12 + y,252,114,3 );
		gfx.PutPixel( 12 + x,12 + y,252,114,3 );
		gfx.PutPixel( 13 + x,12 + y,252,114,3 );
		gfx.PutPixel( 18 + x,12 + y,252,114,3 );
		gfx.PutPixel( 19 + x,12 + y,252,114,3 );
		gfx.PutPixel( 20 + x,12 + y,252,114,3 );
		gfx.PutPixel( 21 + x,12 + y,252,114,3 );
		gfx.PutPixel( 2 + x,13 + y,252,114,3 );
		gfx.PutPixel( 3 + x,13 + y,252,114,3 );
		gfx.PutPixel( 4 + x,13 + y,252,114,3 );
		gfx.PutPixel( 5 + x,13 + y,252,114,3 );
		gfx.PutPixel( 10 + x,13 + y,252,114,3 );
		gfx.PutPixel( 11 + x,13 + y,252,114,3 );
		gfx.PutPixel( 12 + x,13 + y,252,114,3 );
		gfx.PutPixel( 13 + x,13 + y,252,114,3 );
		gfx.PutPixel( 18 + x,13 + y,252,114,3 );
		gfx.PutPixel( 19 + x,13 + y,252,114,3 );
		gfx.PutPixel( 20 + x,13 + y,252,114,3 );
		gfx.PutPixel( 21 + x,13 + y,252,114,3 );
		gfx.PutPixel( 4 + x,14 + y,252,114,3 );
		gfx.PutPixel( 5 + x,14 + y,252,114,3 );
		gfx.PutPixel( 6 + x,14 + y,252,114,3 );
		gfx.PutPixel( 7 + x,14 + y,252,114,3 );
		gfx.PutPixel( 16 + x,14 + y,252,114,3 );
		gfx.PutPixel( 17 + x,14 + y,252,114,3 );
		gfx.PutPixel( 18 + x,14 + y,252,114,3 );
		gfx.PutPixel( 19 + x,14 + y,252,114,3 );
		gfx.PutPixel( 4 + x,15 + y,252,114,3 );
		gfx.PutPixel( 5 + x,15 + y,252,114,3 );
		gfx.PutPixel( 6 + x,15 + y,252,114,3 );
		gfx.PutPixel( 7 + x,15 + y,252,114,3 );
		gfx.PutPixel( 16 + x,15 + y,252,114,3 );
		gfx.PutPixel( 17 + x,15 + y,252,114,3 );
		gfx.PutPixel( 18 + x,15 + y,252,114,3 );
		gfx.PutPixel( 19 + x,15 + y,252,114,3 );
	}
}

void InvaderBig::DrawExplosion( Graphics& gfx ) const
{
	int x = int( loc.x );
	int y = int( loc.y );
	//width = 20;
	//height = 16;

	gfx.PutPixel( 5 + x,0 + y,181,0,0 );
	gfx.PutPixel( 6 + x,0 + y,181,0,0 );
	gfx.PutPixel( 13 + x,0 + y,181,0,0 );
	gfx.PutPixel( 14 + x,0 + y,181,0,0 );
	gfx.PutPixel( 5 + x,1 + y,181,0,0 );
	gfx.PutPixel( 6 + x,1 + y,181,0,0 );
	gfx.PutPixel( 13 + x,1 + y,181,0,0 );
	gfx.PutPixel( 14 + x,1 + y,181,0,0 );
	gfx.PutPixel( 1 + x,2 + y,181,0,0 );
	gfx.PutPixel( 2 + x,2 + y,181,0,0 );
	gfx.PutPixel( 7 + x,2 + y,181,0,0 );
	gfx.PutPixel( 8 + x,2 + y,181,0,0 );
	gfx.PutPixel( 11 + x,2 + y,181,0,0 );
	gfx.PutPixel( 12 + x,2 + y,181,0,0 );
	gfx.PutPixel( 17 + x,2 + y,181,0,0 );
	gfx.PutPixel( 18 + x,2 + y,181,0,0 );
	gfx.PutPixel( 1 + x,3 + y,181,0,0 );
	gfx.PutPixel( 2 + x,3 + y,181,0,0 );
	gfx.PutPixel( 7 + x,3 + y,181,0,0 );
	gfx.PutPixel( 8 + x,3 + y,181,0,0 );
	gfx.PutPixel( 11 + x,3 + y,181,0,0 );
	gfx.PutPixel( 12 + x,3 + y,181,0,0 );
	gfx.PutPixel( 17 + x,3 + y,181,0,0 );
	gfx.PutPixel( 18 + x,3 + y,181,0,0 );
	gfx.PutPixel( 3 + x,4 + y,181,0,0 );
	gfx.PutPixel( 4 + x,4 + y,181,0,0 );
	gfx.PutPixel( 15 + x,4 + y,181,0,0 );
	gfx.PutPixel( 16 + x,4 + y,181,0,0 );
	gfx.PutPixel( 3 + x,5 + y,181,0,0 );
	gfx.PutPixel( 4 + x,5 + y,181,0,0 );
	gfx.PutPixel( 15 + x,5 + y,181,0,0 );
	gfx.PutPixel( 16 + x,5 + y,181,0,0 );
	gfx.PutPixel( 5 + x,6 + y,181,0,0 );
	gfx.PutPixel( 6 + x,6 + y,181,0,0 );
	gfx.PutPixel( 13 + x,6 + y,181,0,0 );
	gfx.PutPixel( 14 + x,6 + y,181,0,0 );
	gfx.PutPixel( 5 + x,7 + y,181,0,0 );
	gfx.PutPixel( 6 + x,7 + y,181,0,0 );
	gfx.PutPixel( 13 + x,7 + y,181,0,0 );
	gfx.PutPixel( 14 + x,7 + y,181,0,0 );
	gfx.PutPixel( 0 + x,8 + y,181,0,0 );
	gfx.PutPixel( 1 + x,8 + y,181,0,0 );
	gfx.PutPixel( 2 + x,8 + y,181,0,0 );
	gfx.PutPixel( 17 + x,8 + y,181,0,0 );
	gfx.PutPixel( 18 + x,8 + y,181,0,0 );
	gfx.PutPixel( 19 + x,8 + y,181,0,0 );
	gfx.PutPixel( 0 + x,9 + y,181,0,0 );
	gfx.PutPixel( 1 + x,9 + y,181,0,0 );
	gfx.PutPixel( 2 + x,9 + y,181,0,0 );
	gfx.PutPixel( 17 + x,9 + y,181,0,0 );
	gfx.PutPixel( 18 + x,9 + y,181,0,0 );
	gfx.PutPixel( 19 + x,9 + y,181,0,0 );
	gfx.PutPixel( 5 + x,10 + y,181,0,0 );
	gfx.PutPixel( 6 + x,10 + y,181,0,0 );
	gfx.PutPixel( 13 + x,10 + y,181,0,0 );
	gfx.PutPixel( 14 + x,10 + y,181,0,0 );
	gfx.PutPixel( 5 + x,11 + y,181,0,0 );
	gfx.PutPixel( 6 + x,11 + y,181,0,0 );
	gfx.PutPixel( 13 + x,11 + y,181,0,0 );
	gfx.PutPixel( 14 + x,11 + y,181,0,0 );
	gfx.PutPixel( 3 + x,12 + y,181,0,0 );
	gfx.PutPixel( 4 + x,12 + y,181,0,0 );
	gfx.PutPixel( 9 + x,12 + y,181,0,0 );
	gfx.PutPixel( 10 + x,12 + y,181,0,0 );
	gfx.PutPixel( 15 + x,12 + y,181,0,0 );
	gfx.PutPixel( 16 + x,12 + y,181,0,0 );
	gfx.PutPixel( 3 + x,13 + y,181,0,0 );
	gfx.PutPixel( 4 + x,13 + y,181,0,0 );
	gfx.PutPixel( 9 + x,13 + y,181,0,0 );
	gfx.PutPixel( 10 + x,13 + y,181,0,0 );
	gfx.PutPixel( 15 + x,13 + y,181,0,0 );
	gfx.PutPixel( 16 + x,13 + y,181,0,0 );
	gfx.PutPixel( 1 + x,14 + y,181,0,0 );
	gfx.PutPixel( 2 + x,14 + y,181,0,0 );
	gfx.PutPixel( 7 + x,14 + y,181,0,0 );
	gfx.PutPixel( 8 + x,14 + y,181,0,0 );
	gfx.PutPixel( 11 + x,14 + y,181,0,0 );
	gfx.PutPixel( 12 + x,14 + y,181,0,0 );
	gfx.PutPixel( 17 + x,14 + y,181,0,0 );
	gfx.PutPixel( 18 + x,14 + y,181,0,0 );
	gfx.PutPixel( 1 + x,15 + y,181,0,0 );
	gfx.PutPixel( 2 + x,15 + y,181,0,0 );
	gfx.PutPixel( 7 + x,15 + y,181,0,0 );
	gfx.PutPixel( 8 + x,15 + y,181,0,0 );
	gfx.PutPixel( 11 + x,15 + y,181,0,0 );
	gfx.PutPixel( 12 + x,15 + y,181,0,0 );
	gfx.PutPixel( 17 + x,15 + y,181,0,0 );
	gfx.PutPixel( 18 + x,15 + y,181,0,0 );
}

bool InvaderBig::IsAlive() const
{
	return isAlive;
}

Dimention InvaderBig::GetDim() const
{
	return dim;
}

Location InvaderBig::GetLoc() const
{
	return loc;
}

void InvaderBig::Init( const Location& in_loc )
{
	if ( !isAlive )
	{
		loc = in_loc;
		isAlive = true;
	}
}

void InvaderBig::Collision( const Location& in_loc,const Dimention& in_dim )
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
			isAlive = false;
		}
	}
}
