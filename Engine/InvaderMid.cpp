#include "InvaderMid.h"

void InvaderMid::Draw( Graphics& gfx,const Location& in_loc )
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

void InvaderMid::DrawMove0( Graphics& gfx ) const
{
	if ( isAlive )
	{
		int x = int( loc.x );
		int y = int( loc.y );
		//width = 20;
		//height = 16;

		gfx.PutPixel( 3 + x,0 + y,247,117,1 );
		gfx.PutPixel( 4 + x,0 + y,247,117,1 );
		gfx.PutPixel( 15 + x,0 + y,247,117,1 );
		gfx.PutPixel( 16 + x,0 + y,247,117,1 );
		gfx.PutPixel( 3 + x,1 + y,247,117,1 );
		gfx.PutPixel( 4 + x,1 + y,247,117,1 );
		gfx.PutPixel( 15 + x,1 + y,247,117,1 );
		gfx.PutPixel( 16 + x,1 + y,247,117,1 );
		gfx.PutPixel( 5 + x,2 + y,247,117,1 );
		gfx.PutPixel( 6 + x,2 + y,247,117,1 );
		gfx.PutPixel( 13 + x,2 + y,247,117,1 );
		gfx.PutPixel( 14 + x,2 + y,247,117,1 );
		gfx.PutPixel( 5 + x,3 + y,247,117,1 );
		gfx.PutPixel( 6 + x,3 + y,247,117,1 );
		gfx.PutPixel( 13 + x,3 + y,247,117,1 );
		gfx.PutPixel( 14 + x,3 + y,247,117,1 );
		gfx.PutPixel( 3 + x,4 + y,0,77,100 );
		gfx.PutPixel( 4 + x,4 + y,0,77,100 );
		gfx.PutPixel( 5 + x,4 + y,0,77,100 );
		gfx.PutPixel( 6 + x,4 + y,0,77,100 );
		gfx.PutPixel( 7 + x,4 + y,247,117,1 );
		gfx.PutPixel( 8 + x,4 + y,247,117,1 );
		gfx.PutPixel( 9 + x,4 + y,0,77,100 );
		gfx.PutPixel( 10 + x,4 + y,0,77,100 );
		gfx.PutPixel( 11 + x,4 + y,247,117,1 );
		gfx.PutPixel( 12 + x,4 + y,247,117,1 );
		gfx.PutPixel( 13 + x,4 + y,0,77,100 );
		gfx.PutPixel( 14 + x,4 + y,0,77,100 );
		gfx.PutPixel( 15 + x,4 + y,0,77,100 );
		gfx.PutPixel( 16 + x,4 + y,0,77,100 );
		gfx.PutPixel( 3 + x,5 + y,0,77,100 );
		gfx.PutPixel( 4 + x,5 + y,0,77,100 );
		gfx.PutPixel( 5 + x,5 + y,0,77,100 );
		gfx.PutPixel( 6 + x,5 + y,0,77,100 );
		gfx.PutPixel( 7 + x,5 + y,247,117,1 );
		gfx.PutPixel( 8 + x,5 + y,247,117,1 );
		gfx.PutPixel( 9 + x,5 + y,0,77,100 );
		gfx.PutPixel( 10 + x,5 + y,0,77,100 );
		gfx.PutPixel( 11 + x,5 + y,247,117,1 );
		gfx.PutPixel( 12 + x,5 + y,247,117,1 );
		gfx.PutPixel( 13 + x,5 + y,0,77,100 );
		gfx.PutPixel( 14 + x,5 + y,0,77,100 );
		gfx.PutPixel( 15 + x,5 + y,0,77,100 );
		gfx.PutPixel( 16 + x,5 + y,0,77,100 );
		gfx.PutPixel( 2 + x,6 + y,0,77,100 );
		gfx.PutPixel( 3 + x,6 + y,0,77,100 );
		gfx.PutPixel( 4 + x,6 + y,0,77,100 );
		gfx.PutPixel( 7 + x,6 + y,0,77,100 );
		gfx.PutPixel( 8 + x,6 + y,0,77,100 );
		gfx.PutPixel( 9 + x,6 + y,247,117,1 );
		gfx.PutPixel( 10 + x,6 + y,247,117,1 );
		gfx.PutPixel( 11 + x,6 + y,0,77,100 );
		gfx.PutPixel( 12 + x,6 + y,0,77,100 );
		gfx.PutPixel( 15 + x,6 + y,0,77,100 );
		gfx.PutPixel( 16 + x,6 + y,0,77,100 );
		gfx.PutPixel( 17 + x,6 + y,0,77,100 );
		gfx.PutPixel( 2 + x,7 + y,0,77,100 );
		gfx.PutPixel( 3 + x,7 + y,0,77,100 );
		gfx.PutPixel( 4 + x,7 + y,0,77,100 );
		gfx.PutPixel( 7 + x,7 + y,0,77,100 );
		gfx.PutPixel( 8 + x,7 + y,0,77,100 );
		gfx.PutPixel( 9 + x,7 + y,247,117,1 );
		gfx.PutPixel( 10 + x,7 + y,247,117,1 );
		gfx.PutPixel( 11 + x,7 + y,0,77,100 );
		gfx.PutPixel( 12 + x,7 + y,0,77,100 );
		gfx.PutPixel( 15 + x,7 + y,0,77,100 );
		gfx.PutPixel( 16 + x,7 + y,0,77,100 );
		gfx.PutPixel( 17 + x,7 + y,0,77,100 );
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
		gfx.PutPixel( 0 + x,10 + y,0,77,100 );
		gfx.PutPixel( 1 + x,10 + y,0,77,100 );
		gfx.PutPixel( 4 + x,10 + y,0,77,100 );
		gfx.PutPixel( 5 + x,10 + y,0,77,100 );
		gfx.PutPixel( 6 + x,10 + y,0,77,100 );
		gfx.PutPixel( 7 + x,10 + y,247,117,1 );
		gfx.PutPixel( 8 + x,10 + y,247,117,1 );
		gfx.PutPixel( 9 + x,10 + y,247,117,1 );
		gfx.PutPixel( 10 + x,10 + y,247,117,1 );
		gfx.PutPixel( 11 + x,10 + y,247,117,1 );
		gfx.PutPixel( 12 + x,10 + y,247,117,1 );
		gfx.PutPixel( 13 + x,10 + y,0,77,100 );
		gfx.PutPixel( 14 + x,10 + y,0,77,100 );
		gfx.PutPixel( 15 + x,10 + y,0,77,100 );
		gfx.PutPixel( 18 + x,10 + y,0,77,100 );
		gfx.PutPixel( 19 + x,10 + y,0,77,100 );
		gfx.PutPixel( 0 + x,11 + y,0,77,100 );
		gfx.PutPixel( 1 + x,11 + y,0,77,100 );
		gfx.PutPixel( 4 + x,11 + y,0,77,100 );
		gfx.PutPixel( 5 + x,11 + y,0,77,100 );
		gfx.PutPixel( 6 + x,11 + y,0,77,100 );
		gfx.PutPixel( 7 + x,11 + y,247,117,1 );
		gfx.PutPixel( 8 + x,11 + y,247,117,1 );
		gfx.PutPixel( 9 + x,11 + y,247,117,1 );
		gfx.PutPixel( 10 + x,11 + y,247,117,1 );
		gfx.PutPixel( 11 + x,11 + y,247,117,1 );
		gfx.PutPixel( 12 + x,11 + y,247,117,1 );
		gfx.PutPixel( 13 + x,11 + y,0,77,100 );
		gfx.PutPixel( 14 + x,11 + y,0,77,100 );
		gfx.PutPixel( 15 + x,11 + y,0,77,100 );
		gfx.PutPixel( 18 + x,11 + y,0,77,100 );
		gfx.PutPixel( 19 + x,11 + y,0,77,100 );
		gfx.PutPixel( 0 + x,12 + y,0,77,100 );
		gfx.PutPixel( 1 + x,12 + y,0,77,100 );
		gfx.PutPixel( 4 + x,12 + y,0,77,100 );
		gfx.PutPixel( 5 + x,12 + y,0,77,100 );
		gfx.PutPixel( 14 + x,12 + y,0,77,100 );
		gfx.PutPixel( 15 + x,12 + y,0,77,100 );
		gfx.PutPixel( 18 + x,12 + y,0,77,100 );
		gfx.PutPixel( 19 + x,12 + y,0,77,100 );
		gfx.PutPixel( 0 + x,13 + y,0,77,100 );
		gfx.PutPixel( 1 + x,13 + y,0,77,100 );
		gfx.PutPixel( 4 + x,13 + y,0,77,100 );
		gfx.PutPixel( 5 + x,13 + y,0,77,100 );
		gfx.PutPixel( 14 + x,13 + y,0,77,100 );
		gfx.PutPixel( 15 + x,13 + y,0,77,100 );
		gfx.PutPixel( 18 + x,13 + y,0,77,100 );
		gfx.PutPixel( 19 + x,13 + y,0,77,100 );
		gfx.PutPixel( 6 + x,14 + y,0,77,100 );
		gfx.PutPixel( 7 + x,14 + y,0,77,100 );
		gfx.PutPixel( 8 + x,14 + y,0,77,100 );
		gfx.PutPixel( 11 + x,14 + y,0,77,100 );
		gfx.PutPixel( 12 + x,14 + y,0,77,100 );
		gfx.PutPixel( 13 + x,14 + y,0,77,100 );
		gfx.PutPixel( 6 + x,15 + y,0,77,100 );
		gfx.PutPixel( 7 + x,15 + y,0,77,100 );
		gfx.PutPixel( 8 + x,15 + y,0,77,100 );
		gfx.PutPixel( 11 + x,15 + y,0,77,100 );
		gfx.PutPixel( 12 + x,15 + y,0,77,100 );
		gfx.PutPixel( 13 + x,15 + y,0,77,100 );
	}
}

void InvaderMid::DrawMove1( Graphics& gfx ) const
{
	if ( isAlive )
	{
		int x = int( loc.x );
		int y = int( loc.y );
		//width = 20;
		//height = 16;

		gfx.PutPixel( 3 + x,0 + y,247,117,1 );
		gfx.PutPixel( 4 + x,0 + y,247,117,1 );
		gfx.PutPixel( 15 + x,0 + y,247,117,1 );
		gfx.PutPixel( 16 + x,0 + y,247,117,1 );
		gfx.PutPixel( 3 + x,1 + y,247,117,1 );
		gfx.PutPixel( 4 + x,1 + y,247,117,1 );
		gfx.PutPixel( 15 + x,1 + y,247,117,1 );
		gfx.PutPixel( 16 + x,1 + y,247,117,1 );
		gfx.PutPixel( 0 + x,2 + y,0,77,100 );
		gfx.PutPixel( 1 + x,2 + y,0,77,100 );
		gfx.PutPixel( 5 + x,2 + y,247,117,1 );
		gfx.PutPixel( 6 + x,2 + y,247,117,1 );
		gfx.PutPixel( 13 + x,2 + y,247,117,1 );
		gfx.PutPixel( 14 + x,2 + y,247,117,1 );
		gfx.PutPixel( 18 + x,2 + y,0,77,100 );
		gfx.PutPixel( 19 + x,2 + y,0,77,100 );
		gfx.PutPixel( 0 + x,3 + y,0,77,100 );
		gfx.PutPixel( 1 + x,3 + y,0,77,100 );
		gfx.PutPixel( 5 + x,3 + y,247,117,1 );
		gfx.PutPixel( 6 + x,3 + y,247,117,1 );
		gfx.PutPixel( 13 + x,3 + y,247,117,1 );
		gfx.PutPixel( 14 + x,3 + y,247,117,1 );
		gfx.PutPixel( 18 + x,3 + y,0,77,100 );
		gfx.PutPixel( 19 + x,3 + y,0,77,100 );
		gfx.PutPixel( 0 + x,4 + y,0,77,100 );
		gfx.PutPixel( 1 + x,4 + y,0,77,100 );
		gfx.PutPixel( 3 + x,4 + y,0,77,100 );
		gfx.PutPixel( 4 + x,4 + y,0,77,100 );
		gfx.PutPixel( 5 + x,4 + y,0,77,100 );
		gfx.PutPixel( 6 + x,4 + y,0,77,100 );
		gfx.PutPixel( 7 + x,4 + y,247,117,1 );
		gfx.PutPixel( 8 + x,4 + y,247,117,1 );
		gfx.PutPixel( 9 + x,4 + y,0,77,100 );
		gfx.PutPixel( 10 + x,4 + y,0,77,100 );
		gfx.PutPixel( 11 + x,4 + y,247,117,1 );
		gfx.PutPixel( 12 + x,4 + y,247,117,1 );
		gfx.PutPixel( 13 + x,4 + y,0,77,100 );
		gfx.PutPixel( 14 + x,4 + y,0,77,100 );
		gfx.PutPixel( 15 + x,4 + y,0,77,100 );
		gfx.PutPixel( 16 + x,4 + y,0,77,100 );
		gfx.PutPixel( 18 + x,4 + y,0,77,100 );
		gfx.PutPixel( 19 + x,4 + y,0,77,100 );
		gfx.PutPixel( 0 + x,5 + y,0,77,100 );
		gfx.PutPixel( 1 + x,5 + y,0,77,100 );
		gfx.PutPixel( 3 + x,5 + y,0,77,100 );
		gfx.PutPixel( 4 + x,5 + y,0,77,100 );
		gfx.PutPixel( 5 + x,5 + y,0,77,100 );
		gfx.PutPixel( 6 + x,5 + y,0,77,100 );
		gfx.PutPixel( 7 + x,5 + y,247,117,1 );
		gfx.PutPixel( 8 + x,5 + y,247,117,1 );
		gfx.PutPixel( 9 + x,5 + y,0,77,100 );
		gfx.PutPixel( 10 + x,5 + y,0,77,100 );
		gfx.PutPixel( 11 + x,5 + y,247,117,1 );
		gfx.PutPixel( 12 + x,5 + y,247,117,1 );
		gfx.PutPixel( 13 + x,5 + y,0,77,100 );
		gfx.PutPixel( 14 + x,5 + y,0,77,100 );
		gfx.PutPixel( 15 + x,5 + y,0,77,100 );
		gfx.PutPixel( 16 + x,5 + y,0,77,100 );
		gfx.PutPixel( 18 + x,5 + y,0,77,100 );
		gfx.PutPixel( 19 + x,5 + y,0,77,100 );
		gfx.PutPixel( 0 + x,6 + y,0,77,100 );
		gfx.PutPixel( 1 + x,6 + y,0,77,100 );
		gfx.PutPixel( 2 + x,6 + y,0,77,100 );
		gfx.PutPixel( 3 + x,6 + y,0,77,100 );
		gfx.PutPixel( 4 + x,6 + y,0,77,100 );
		gfx.PutPixel( 7 + x,6 + y,0,77,100 );
		gfx.PutPixel( 8 + x,6 + y,0,77,100 );
		gfx.PutPixel( 9 + x,6 + y,247,117,1 );
		gfx.PutPixel( 10 + x,6 + y,247,117,1 );
		gfx.PutPixel( 11 + x,6 + y,0,77,100 );
		gfx.PutPixel( 12 + x,6 + y,0,77,100 );
		gfx.PutPixel( 15 + x,6 + y,0,77,100 );
		gfx.PutPixel( 16 + x,6 + y,0,77,100 );
		gfx.PutPixel( 17 + x,6 + y,0,77,100 );
		gfx.PutPixel( 18 + x,6 + y,0,77,100 );
		gfx.PutPixel( 19 + x,6 + y,0,77,100 );
		gfx.PutPixel( 0 + x,7 + y,0,77,100 );
		gfx.PutPixel( 1 + x,7 + y,0,77,100 );
		gfx.PutPixel( 2 + x,7 + y,0,77,100 );
		gfx.PutPixel( 3 + x,7 + y,0,77,100 );
		gfx.PutPixel( 4 + x,7 + y,0,77,100 );
		gfx.PutPixel( 7 + x,7 + y,0,77,100 );
		gfx.PutPixel( 8 + x,7 + y,0,77,100 );
		gfx.PutPixel( 9 + x,7 + y,247,117,1 );
		gfx.PutPixel( 10 + x,7 + y,247,117,1 );
		gfx.PutPixel( 11 + x,7 + y,0,77,100 );
		gfx.PutPixel( 12 + x,7 + y,0,77,100 );
		gfx.PutPixel( 15 + x,7 + y,0,77,100 );
		gfx.PutPixel( 16 + x,7 + y,0,77,100 );
		gfx.PutPixel( 17 + x,7 + y,0,77,100 );
		gfx.PutPixel( 18 + x,7 + y,0,77,100 );
		gfx.PutPixel( 19 + x,7 + y,0,77,100 );
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
		gfx.PutPixel( 4 + x,10 + y,0,77,100 );
		gfx.PutPixel( 5 + x,10 + y,0,77,100 );
		gfx.PutPixel( 6 + x,10 + y,0,77,100 );
		gfx.PutPixel( 7 + x,10 + y,247,117,1 );
		gfx.PutPixel( 8 + x,10 + y,247,117,1 );
		gfx.PutPixel( 9 + x,10 + y,247,117,1 );
		gfx.PutPixel( 10 + x,10 + y,247,117,1 );
		gfx.PutPixel( 11 + x,10 + y,247,117,1 );
		gfx.PutPixel( 12 + x,10 + y,247,117,1 );
		gfx.PutPixel( 13 + x,10 + y,0,77,100 );
		gfx.PutPixel( 14 + x,10 + y,0,77,100 );
		gfx.PutPixel( 15 + x,10 + y,0,77,100 );
		gfx.PutPixel( 4 + x,11 + y,0,77,100 );
		gfx.PutPixel( 5 + x,11 + y,0,77,100 );
		gfx.PutPixel( 6 + x,11 + y,0,77,100 );
		gfx.PutPixel( 7 + x,11 + y,247,117,1 );
		gfx.PutPixel( 8 + x,11 + y,247,117,1 );
		gfx.PutPixel( 9 + x,11 + y,247,117,1 );
		gfx.PutPixel( 10 + x,11 + y,247,117,1 );
		gfx.PutPixel( 11 + x,11 + y,247,117,1 );
		gfx.PutPixel( 12 + x,11 + y,247,117,1 );
		gfx.PutPixel( 13 + x,11 + y,0,77,100 );
		gfx.PutPixel( 14 + x,11 + y,0,77,100 );
		gfx.PutPixel( 15 + x,11 + y,0,77,100 );
		gfx.PutPixel( 3 + x,12 + y,0,77,100 );
		gfx.PutPixel( 4 + x,12 + y,0,77,100 );
		gfx.PutPixel( 15 + x,12 + y,0,77,100 );
		gfx.PutPixel( 16 + x,12 + y,0,77,100 );
		gfx.PutPixel( 3 + x,13 + y,0,77,100 );
		gfx.PutPixel( 4 + x,13 + y,0,77,100 );
		gfx.PutPixel( 15 + x,13 + y,0,77,100 );
		gfx.PutPixel( 16 + x,13 + y,0,77,100 );
		gfx.PutPixel( 1 + x,14 + y,0,77,100 );
		gfx.PutPixel( 2 + x,14 + y,0,77,100 );
		gfx.PutPixel( 17 + x,14 + y,0,77,100 );
		gfx.PutPixel( 18 + x,14 + y,0,77,100 );
		gfx.PutPixel( 1 + x,15 + y,0,77,100 );
		gfx.PutPixel( 2 + x,15 + y,0,77,100 );
		gfx.PutPixel( 17 + x,15 + y,0,77,100 );
		gfx.PutPixel( 18 + x,15 + y,0,77,100 );
	}
}

void InvaderMid::DrawExplosion( Graphics& gfx ) const
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

bool InvaderMid::IsAlive() const
{
	return isAlive;
}

Dimention InvaderMid::GetDim() const
{
	return dim;
}

Location InvaderMid::GetLoc() const
{
	return loc;
}

void InvaderMid::Init( const Location& in_loc )
{
	if ( !isAlive )
	{
		loc = in_loc;
		isAlive = true;
	}
}

void InvaderMid::Collision( const Location& in_loc,const Dimention& in_dim )
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
