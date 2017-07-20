#include "House.h"

House::House( const Location& in_loc )
	:
	loc( in_loc )
{
}

Dimention House::GetDimention() const
{
	return dim;
}

Location House::GetLocation() const
{
	return loc;
}

void House::Draw( Graphics & gfx )
{
	//width = 40;
	//height = 30;
	int x = int( loc.x );
	int y = int( loc.y );

	gfx.PutPixel( 9 + x,0 + y,9,164,24 );
	gfx.PutPixel( 10 + x,0 + y,9,164,24 );
	gfx.PutPixel( 11 + x,0 + y,9,164,24 );
	gfx.PutPixel( 12 + x,0 + y,9,164,24 );
	gfx.PutPixel( 13 + x,0 + y,9,164,24 );
	gfx.PutPixel( 14 + x,0 + y,9,164,24 );
	gfx.PutPixel( 15 + x,0 + y,9,164,24 );
	gfx.PutPixel( 16 + x,0 + y,9,164,24 );
	gfx.PutPixel( 17 + x,0 + y,9,164,24 );
	gfx.PutPixel( 18 + x,0 + y,9,164,24 );
	gfx.PutPixel( 19 + x,0 + y,9,164,24 );
	gfx.PutPixel( 20 + x,0 + y,9,164,24 );
	gfx.PutPixel( 21 + x,0 + y,9,164,24 );
	gfx.PutPixel( 22 + x,0 + y,9,164,24 );
	gfx.PutPixel( 23 + x,0 + y,9,164,24 );
	gfx.PutPixel( 24 + x,0 + y,9,164,24 );
	gfx.PutPixel( 25 + x,0 + y,9,164,24 );
	gfx.PutPixel( 26 + x,0 + y,9,164,24 );
	gfx.PutPixel( 27 + x,0 + y,9,164,24 );
	gfx.PutPixel( 28 + x,0 + y,9,164,24 );
	gfx.PutPixel( 29 + x,0 + y,9,171,25 );
	gfx.PutPixel( 30 + x,0 + y,9,171,25 );
	gfx.PutPixel( 8 + x,1 + y,9,171,25 );
	gfx.PutPixel( 9 + x,1 + y,9,171,25 );
	gfx.PutPixel( 10 + x,1 + y,9,171,25 );
	gfx.PutPixel( 11 + x,1 + y,9,171,25 );
	gfx.PutPixel( 12 + x,1 + y,9,171,25 );
	gfx.PutPixel( 13 + x,1 + y,9,171,25 );
	gfx.PutPixel( 14 + x,1 + y,9,171,25 );
	gfx.PutPixel( 15 + x,1 + y,9,171,25 );
	gfx.PutPixel( 16 + x,1 + y,9,171,25 );
	gfx.PutPixel( 17 + x,1 + y,9,171,25 );
	gfx.PutPixel( 18 + x,1 + y,9,171,25 );
	gfx.PutPixel( 19 + x,1 + y,9,171,25 );
	gfx.PutPixel( 20 + x,1 + y,9,171,25 );
	gfx.PutPixel( 21 + x,1 + y,9,171,25 );
	gfx.PutPixel( 22 + x,1 + y,9,171,25 );
	gfx.PutPixel( 23 + x,1 + y,9,171,25 );
	gfx.PutPixel( 24 + x,1 + y,9,171,25 );
	gfx.PutPixel( 25 + x,1 + y,9,171,25 );
	gfx.PutPixel( 26 + x,1 + y,9,171,25 );
	gfx.PutPixel( 27 + x,1 + y,9,171,25 );
	gfx.PutPixel( 28 + x,1 + y,9,171,25 );
	gfx.PutPixel( 29 + x,1 + y,9,171,25 );
	gfx.PutPixel( 30 + x,1 + y,9,171,25 );
	gfx.PutPixel( 31 + x,1 + y,9,171,25 );
	gfx.PutPixel( 7 + x,2 + y,9,171,25 );
	gfx.PutPixel( 8 + x,2 + y,9,171,25 );
	gfx.PutPixel( 9 + x,2 + y,9,171,25 );
	gfx.PutPixel( 10 + x,2 + y,9,171,25 );
	gfx.PutPixel( 11 + x,2 + y,9,171,25 );
	gfx.PutPixel( 12 + x,2 + y,9,171,25 );
	gfx.PutPixel( 13 + x,2 + y,9,171,25 );
	gfx.PutPixel( 14 + x,2 + y,9,171,25 );
	gfx.PutPixel( 15 + x,2 + y,9,171,25 );
	gfx.PutPixel( 16 + x,2 + y,9,171,25 );
	gfx.PutPixel( 17 + x,2 + y,9,171,25 );
	gfx.PutPixel( 18 + x,2 + y,9,171,25 );
	gfx.PutPixel( 19 + x,2 + y,9,171,25 );
	gfx.PutPixel( 20 + x,2 + y,9,171,25 );
	gfx.PutPixel( 21 + x,2 + y,9,171,25 );
	gfx.PutPixel( 22 + x,2 + y,9,171,25 );
	gfx.PutPixel( 23 + x,2 + y,9,171,25 );
	gfx.PutPixel( 24 + x,2 + y,9,171,25 );
	gfx.PutPixel( 25 + x,2 + y,9,171,25 );
	gfx.PutPixel( 26 + x,2 + y,9,171,25 );
	gfx.PutPixel( 27 + x,2 + y,9,171,25 );
	gfx.PutPixel( 28 + x,2 + y,9,171,25 );
	gfx.PutPixel( 29 + x,2 + y,9,171,25 );
	gfx.PutPixel( 30 + x,2 + y,9,171,25 );
	gfx.PutPixel( 31 + x,2 + y,9,171,25 );
	gfx.PutPixel( 32 + x,2 + y,9,171,25 );
	gfx.PutPixel( 6 + x,3 + y,9,171,25 );
	gfx.PutPixel( 7 + x,3 + y,9,171,25 );
	gfx.PutPixel( 8 + x,3 + y,9,171,25 );
	gfx.PutPixel( 9 + x,3 + y,9,171,25 );
	gfx.PutPixel( 10 + x,3 + y,9,171,25 );
	gfx.PutPixel( 11 + x,3 + y,9,171,25 );
	gfx.PutPixel( 12 + x,3 + y,9,171,25 );
	gfx.PutPixel( 13 + x,3 + y,9,171,25 );
	gfx.PutPixel( 14 + x,3 + y,9,171,25 );
	gfx.PutPixel( 15 + x,3 + y,9,171,25 );
	gfx.PutPixel( 16 + x,3 + y,9,171,25 );
	gfx.PutPixel( 17 + x,3 + y,9,171,25 );
	gfx.PutPixel( 18 + x,3 + y,9,171,25 );
	gfx.PutPixel( 19 + x,3 + y,9,171,25 );
	gfx.PutPixel( 20 + x,3 + y,9,171,25 );
	gfx.PutPixel( 21 + x,3 + y,9,171,25 );
	gfx.PutPixel( 22 + x,3 + y,9,171,25 );
	gfx.PutPixel( 23 + x,3 + y,9,171,25 );
	gfx.PutPixel( 24 + x,3 + y,9,171,25 );
	gfx.PutPixel( 25 + x,3 + y,9,171,25 );
	gfx.PutPixel( 26 + x,3 + y,9,171,25 );
	gfx.PutPixel( 27 + x,3 + y,9,171,25 );
	gfx.PutPixel( 28 + x,3 + y,9,171,25 );
	gfx.PutPixel( 29 + x,3 + y,9,171,25 );
	gfx.PutPixel( 30 + x,3 + y,9,171,25 );
	gfx.PutPixel( 31 + x,3 + y,9,171,25 );
	gfx.PutPixel( 32 + x,3 + y,9,171,25 );
	gfx.PutPixel( 33 + x,3 + y,9,171,25 );
	gfx.PutPixel( 5 + x,4 + y,9,171,25 );
	gfx.PutPixel( 6 + x,4 + y,9,171,25 );
	gfx.PutPixel( 7 + x,4 + y,9,171,25 );
	gfx.PutPixel( 8 + x,4 + y,9,171,25 );
	gfx.PutPixel( 9 + x,4 + y,9,171,25 );
	gfx.PutPixel( 10 + x,4 + y,9,171,25 );
	gfx.PutPixel( 11 + x,4 + y,9,171,25 );
	gfx.PutPixel( 12 + x,4 + y,9,171,25 );
	gfx.PutPixel( 13 + x,4 + y,9,171,25 );
	gfx.PutPixel( 14 + x,4 + y,9,171,25 );
	gfx.PutPixel( 15 + x,4 + y,255,192,0 );
	gfx.PutPixel( 16 + x,4 + y,255,192,0 );
	gfx.PutPixel( 17 + x,4 + y,255,192,0 );
	gfx.PutPixel( 18 + x,4 + y,255,192,0 );
	gfx.PutPixel( 19 + x,4 + y,9,171,25 );
	gfx.PutPixel( 20 + x,4 + y,9,171,25 );
	gfx.PutPixel( 21 + x,4 + y,0,77,100 );
	gfx.PutPixel( 22 + x,4 + y,0,77,100 );
	gfx.PutPixel( 23 + x,4 + y,0,77,100 );
	gfx.PutPixel( 24 + x,4 + y,0,77,100 );
	gfx.PutPixel( 25 + x,4 + y,9,171,25 );
	gfx.PutPixel( 26 + x,4 + y,9,171,25 );
	gfx.PutPixel( 27 + x,4 + y,9,171,25 );
	gfx.PutPixel( 28 + x,4 + y,9,171,25 );
	gfx.PutPixel( 29 + x,4 + y,9,171,25 );
	gfx.PutPixel( 30 + x,4 + y,9,171,25 );
	gfx.PutPixel( 31 + x,4 + y,9,171,25 );
	gfx.PutPixel( 32 + x,4 + y,9,171,25 );
	gfx.PutPixel( 33 + x,4 + y,9,171,25 );
	gfx.PutPixel( 34 + x,4 + y,9,171,25 );
	gfx.PutPixel( 4 + x,5 + y,9,171,25 );
	gfx.PutPixel( 5 + x,5 + y,9,171,25 );
	gfx.PutPixel( 6 + x,5 + y,9,171,25 );
	gfx.PutPixel( 7 + x,5 + y,9,171,25 );
	gfx.PutPixel( 8 + x,5 + y,9,171,25 );
	gfx.PutPixel( 9 + x,5 + y,9,171,25 );
	gfx.PutPixel( 10 + x,5 + y,9,171,25 );
	gfx.PutPixel( 11 + x,5 + y,9,171,25 );
	gfx.PutPixel( 12 + x,5 + y,9,171,25 );
	gfx.PutPixel( 13 + x,5 + y,9,171,25 );
	gfx.PutPixel( 14 + x,5 + y,9,171,25 );
	gfx.PutPixel( 15 + x,5 + y,255,192,0 );
	gfx.PutPixel( 16 + x,5 + y,9,171,25 );
	gfx.PutPixel( 17 + x,5 + y,9,171,25 );
	gfx.PutPixel( 18 + x,5 + y,9,171,25 );
	gfx.PutPixel( 19 + x,5 + y,9,171,25 );
	gfx.PutPixel( 20 + x,5 + y,9,171,25 );
	gfx.PutPixel( 21 + x,5 + y,9,171,25 );
	gfx.PutPixel( 22 + x,5 + y,0,77,100 );
	gfx.PutPixel( 23 + x,5 + y,0,77,100 );
	gfx.PutPixel( 24 + x,5 + y,9,171,25 );
	gfx.PutPixel( 25 + x,5 + y,9,171,25 );
	gfx.PutPixel( 26 + x,5 + y,9,171,25 );
	gfx.PutPixel( 27 + x,5 + y,9,171,25 );
	gfx.PutPixel( 28 + x,5 + y,9,171,25 );
	gfx.PutPixel( 29 + x,5 + y,9,171,25 );
	gfx.PutPixel( 30 + x,5 + y,9,171,25 );
	gfx.PutPixel( 31 + x,5 + y,9,171,25 );
	gfx.PutPixel( 32 + x,5 + y,9,171,25 );
	gfx.PutPixel( 33 + x,5 + y,9,171,25 );
	gfx.PutPixel( 34 + x,5 + y,9,171,25 );
	gfx.PutPixel( 35 + x,5 + y,9,171,25 );
	gfx.PutPixel( 3 + x,6 + y,9,171,25 );
	gfx.PutPixel( 4 + x,6 + y,9,171,25 );
	gfx.PutPixel( 5 + x,6 + y,9,171,25 );
	gfx.PutPixel( 6 + x,6 + y,9,171,25 );
	gfx.PutPixel( 7 + x,6 + y,9,171,25 );
	gfx.PutPixel( 8 + x,6 + y,9,171,25 );
	gfx.PutPixel( 9 + x,6 + y,9,171,25 );
	gfx.PutPixel( 10 + x,6 + y,9,171,25 );
	gfx.PutPixel( 11 + x,6 + y,9,171,25 );
	gfx.PutPixel( 12 + x,6 + y,9,171,25 );
	gfx.PutPixel( 13 + x,6 + y,9,171,25 );
	gfx.PutPixel( 14 + x,6 + y,9,171,25 );
	gfx.PutPixel( 15 + x,6 + y,255,192,0 );
	gfx.PutPixel( 16 + x,6 + y,9,171,25 );
	gfx.PutPixel( 17 + x,6 + y,9,171,25 );
	gfx.PutPixel( 18 + x,6 + y,9,171,25 );
	gfx.PutPixel( 19 + x,6 + y,9,171,25 );
	gfx.PutPixel( 20 + x,6 + y,9,171,25 );
	gfx.PutPixel( 21 + x,6 + y,9,171,25 );
	gfx.PutPixel( 22 + x,6 + y,0,77,100 );
	gfx.PutPixel( 23 + x,6 + y,0,77,100 );
	gfx.PutPixel( 24 + x,6 + y,9,171,25 );
	gfx.PutPixel( 25 + x,6 + y,9,171,25 );
	gfx.PutPixel( 26 + x,6 + y,9,171,25 );
	gfx.PutPixel( 27 + x,6 + y,9,171,25 );
	gfx.PutPixel( 28 + x,6 + y,9,171,25 );
	gfx.PutPixel( 29 + x,6 + y,9,171,25 );
	gfx.PutPixel( 30 + x,6 + y,9,171,25 );
	gfx.PutPixel( 31 + x,6 + y,9,171,25 );
	gfx.PutPixel( 32 + x,6 + y,9,171,25 );
	gfx.PutPixel( 33 + x,6 + y,9,171,25 );
	gfx.PutPixel( 34 + x,6 + y,9,171,25 );
	gfx.PutPixel( 35 + x,6 + y,9,171,25 );
	gfx.PutPixel( 36 + x,6 + y,9,171,25 );
	gfx.PutPixel( 2 + x,7 + y,9,171,25 );
	gfx.PutPixel( 3 + x,7 + y,9,171,25 );
	gfx.PutPixel( 4 + x,7 + y,9,171,25 );
	gfx.PutPixel( 5 + x,7 + y,9,171,25 );
	gfx.PutPixel( 6 + x,7 + y,9,171,25 );
	gfx.PutPixel( 7 + x,7 + y,9,171,25 );
	gfx.PutPixel( 8 + x,7 + y,9,171,25 );
	gfx.PutPixel( 9 + x,7 + y,9,171,25 );
	gfx.PutPixel( 10 + x,7 + y,9,171,25 );
	gfx.PutPixel( 11 + x,7 + y,9,171,25 );
	gfx.PutPixel( 12 + x,7 + y,9,171,25 );
	gfx.PutPixel( 13 + x,7 + y,9,171,25 );
	gfx.PutPixel( 14 + x,7 + y,9,171,25 );
	gfx.PutPixel( 15 + x,7 + y,255,192,0 );
	gfx.PutPixel( 16 + x,7 + y,255,192,0 );
	gfx.PutPixel( 17 + x,7 + y,255,192,0 );
	gfx.PutPixel( 18 + x,7 + y,255,192,0 );
	gfx.PutPixel( 19 + x,7 + y,9,171,25 );
	gfx.PutPixel( 20 + x,7 + y,9,171,25 );
	gfx.PutPixel( 21 + x,7 + y,9,171,25 );
	gfx.PutPixel( 22 + x,7 + y,0,77,100 );
	gfx.PutPixel( 23 + x,7 + y,0,77,100 );
	gfx.PutPixel( 24 + x,7 + y,9,171,25 );
	gfx.PutPixel( 25 + x,7 + y,9,171,25 );
	gfx.PutPixel( 26 + x,7 + y,9,171,25 );
	gfx.PutPixel( 27 + x,7 + y,9,171,25 );
	gfx.PutPixel( 28 + x,7 + y,9,171,25 );
	gfx.PutPixel( 29 + x,7 + y,9,171,25 );
	gfx.PutPixel( 30 + x,7 + y,9,171,25 );
	gfx.PutPixel( 31 + x,7 + y,9,171,25 );
	gfx.PutPixel( 32 + x,7 + y,9,171,25 );
	gfx.PutPixel( 33 + x,7 + y,9,171,25 );
	gfx.PutPixel( 34 + x,7 + y,9,171,25 );
	gfx.PutPixel( 35 + x,7 + y,9,171,25 );
	gfx.PutPixel( 36 + x,7 + y,9,171,25 );
	gfx.PutPixel( 37 + x,7 + y,9,171,25 );
	gfx.PutPixel( 1 + x,8 + y,9,171,25 );
	gfx.PutPixel( 2 + x,8 + y,9,171,25 );
	gfx.PutPixel( 3 + x,8 + y,9,171,25 );
	gfx.PutPixel( 4 + x,8 + y,9,171,25 );
	gfx.PutPixel( 5 + x,8 + y,9,171,25 );
	gfx.PutPixel( 6 + x,8 + y,9,171,25 );
	gfx.PutPixel( 7 + x,8 + y,9,171,25 );
	gfx.PutPixel( 8 + x,8 + y,9,171,25 );
	gfx.PutPixel( 9 + x,8 + y,9,171,25 );
	gfx.PutPixel( 10 + x,8 + y,9,171,25 );
	gfx.PutPixel( 11 + x,8 + y,9,171,25 );
	gfx.PutPixel( 12 + x,8 + y,9,171,25 );
	gfx.PutPixel( 13 + x,8 + y,9,171,25 );
	gfx.PutPixel( 14 + x,8 + y,9,171,25 );
	gfx.PutPixel( 15 + x,8 + y,9,171,25 );
	gfx.PutPixel( 16 + x,8 + y,9,171,25 );
	gfx.PutPixel( 17 + x,8 + y,9,171,25 );
	gfx.PutPixel( 18 + x,8 + y,255,192,0 );
	gfx.PutPixel( 19 + x,8 + y,9,171,25 );
	gfx.PutPixel( 20 + x,8 + y,9,171,25 );
	gfx.PutPixel( 21 + x,8 + y,9,171,25 );
	gfx.PutPixel( 22 + x,8 + y,0,77,100 );
	gfx.PutPixel( 23 + x,8 + y,0,77,100 );
	gfx.PutPixel( 24 + x,8 + y,9,171,25 );
	gfx.PutPixel( 25 + x,8 + y,9,171,25 );
	gfx.PutPixel( 26 + x,8 + y,9,171,25 );
	gfx.PutPixel( 27 + x,8 + y,9,171,25 );
	gfx.PutPixel( 28 + x,8 + y,9,171,25 );
	gfx.PutPixel( 29 + x,8 + y,9,171,25 );
	gfx.PutPixel( 30 + x,8 + y,9,171,25 );
	gfx.PutPixel( 31 + x,8 + y,9,171,25 );
	gfx.PutPixel( 32 + x,8 + y,9,171,25 );
	gfx.PutPixel( 33 + x,8 + y,9,171,25 );
	gfx.PutPixel( 34 + x,8 + y,9,171,25 );
	gfx.PutPixel( 35 + x,8 + y,9,171,25 );
	gfx.PutPixel( 36 + x,8 + y,9,171,25 );
	gfx.PutPixel( 37 + x,8 + y,9,171,25 );
	gfx.PutPixel( 38 + x,8 + y,9,171,25 );
	gfx.PutPixel( 0 + x,9 + y,9,171,25 );
	gfx.PutPixel( 1 + x,9 + y,9,171,25 );
	gfx.PutPixel( 2 + x,9 + y,9,171,25 );
	gfx.PutPixel( 3 + x,9 + y,9,171,25 );
	gfx.PutPixel( 4 + x,9 + y,9,171,25 );
	gfx.PutPixel( 5 + x,9 + y,9,171,25 );
	gfx.PutPixel( 6 + x,9 + y,9,171,25 );
	gfx.PutPixel( 7 + x,9 + y,9,171,25 );
	gfx.PutPixel( 8 + x,9 + y,9,171,25 );
	gfx.PutPixel( 9 + x,9 + y,9,171,25 );
	gfx.PutPixel( 10 + x,9 + y,9,171,25 );
	gfx.PutPixel( 11 + x,9 + y,9,171,25 );
	gfx.PutPixel( 12 + x,9 + y,9,171,25 );
	gfx.PutPixel( 13 + x,9 + y,9,171,25 );
	gfx.PutPixel( 14 + x,9 + y,9,171,25 );
	gfx.PutPixel( 15 + x,9 + y,9,171,25 );
	gfx.PutPixel( 16 + x,9 + y,9,171,25 );
	gfx.PutPixel( 17 + x,9 + y,9,171,25 );
	gfx.PutPixel( 18 + x,9 + y,255,192,0 );
	gfx.PutPixel( 19 + x,9 + y,9,171,25 );
	gfx.PutPixel( 20 + x,9 + y,9,171,25 );
	gfx.PutPixel( 21 + x,9 + y,9,171,25 );
	gfx.PutPixel( 22 + x,9 + y,0,77,100 );
	gfx.PutPixel( 23 + x,9 + y,0,77,100 );
	gfx.PutPixel( 24 + x,9 + y,9,171,25 );
	gfx.PutPixel( 25 + x,9 + y,9,171,25 );
	gfx.PutPixel( 26 + x,9 + y,9,171,25 );
	gfx.PutPixel( 27 + x,9 + y,9,171,25 );
	gfx.PutPixel( 28 + x,9 + y,9,171,25 );
	gfx.PutPixel( 29 + x,9 + y,9,171,25 );
	gfx.PutPixel( 30 + x,9 + y,9,171,25 );
	gfx.PutPixel( 31 + x,9 + y,9,171,25 );
	gfx.PutPixel( 32 + x,9 + y,9,171,25 );
	gfx.PutPixel( 33 + x,9 + y,9,171,25 );
	gfx.PutPixel( 34 + x,9 + y,9,171,25 );
	gfx.PutPixel( 35 + x,9 + y,9,171,25 );
	gfx.PutPixel( 36 + x,9 + y,9,171,25 );
	gfx.PutPixel( 37 + x,9 + y,9,171,25 );
	gfx.PutPixel( 38 + x,9 + y,9,171,25 );
	gfx.PutPixel( 39 + x,9 + y,9,171,25 );
	gfx.PutPixel( 0 + x,10 + y,9,171,25 );
	gfx.PutPixel( 1 + x,10 + y,9,171,25 );
	gfx.PutPixel( 2 + x,10 + y,9,171,25 );
	gfx.PutPixel( 3 + x,10 + y,9,171,25 );
	gfx.PutPixel( 4 + x,10 + y,9,171,25 );
	gfx.PutPixel( 5 + x,10 + y,9,171,25 );
	gfx.PutPixel( 6 + x,10 + y,9,171,25 );
	gfx.PutPixel( 7 + x,10 + y,9,171,25 );
	gfx.PutPixel( 8 + x,10 + y,9,171,25 );
	gfx.PutPixel( 9 + x,10 + y,9,171,25 );
	gfx.PutPixel( 10 + x,10 + y,9,171,25 );
	gfx.PutPixel( 11 + x,10 + y,9,171,25 );
	gfx.PutPixel( 12 + x,10 + y,9,171,25 );
	gfx.PutPixel( 13 + x,10 + y,9,171,25 );
	gfx.PutPixel( 14 + x,10 + y,9,171,25 );
	gfx.PutPixel( 15 + x,10 + y,255,192,0 );
	gfx.PutPixel( 16 + x,10 + y,255,192,0 );
	gfx.PutPixel( 17 + x,10 + y,255,192,0 );
	gfx.PutPixel( 18 + x,10 + y,255,192,0 );
	gfx.PutPixel( 19 + x,10 + y,9,171,25 );
	gfx.PutPixel( 20 + x,10 + y,9,171,25 );
	gfx.PutPixel( 21 + x,10 + y,0,77,100 );
	gfx.PutPixel( 22 + x,10 + y,0,77,100 );
	gfx.PutPixel( 23 + x,10 + y,0,77,100 );
	gfx.PutPixel( 24 + x,10 + y,0,77,100 );
	gfx.PutPixel( 25 + x,10 + y,9,171,25 );
	gfx.PutPixel( 26 + x,10 + y,9,171,25 );
	gfx.PutPixel( 27 + x,10 + y,9,171,25 );
	gfx.PutPixel( 28 + x,10 + y,9,171,25 );
	gfx.PutPixel( 29 + x,10 + y,9,171,25 );
	gfx.PutPixel( 30 + x,10 + y,9,171,25 );
	gfx.PutPixel( 31 + x,10 + y,9,171,25 );
	gfx.PutPixel( 32 + x,10 + y,9,171,25 );
	gfx.PutPixel( 33 + x,10 + y,9,171,25 );
	gfx.PutPixel( 34 + x,10 + y,9,171,25 );
	gfx.PutPixel( 35 + x,10 + y,9,171,25 );
	gfx.PutPixel( 36 + x,10 + y,9,171,25 );
	gfx.PutPixel( 37 + x,10 + y,9,171,25 );
	gfx.PutPixel( 38 + x,10 + y,9,171,25 );
	gfx.PutPixel( 39 + x,10 + y,9,171,25 );
	gfx.PutPixel( 0 + x,11 + y,9,171,25 );
	gfx.PutPixel( 1 + x,11 + y,9,171,25 );
	gfx.PutPixel( 2 + x,11 + y,9,171,25 );
	gfx.PutPixel( 3 + x,11 + y,9,171,25 );
	gfx.PutPixel( 4 + x,11 + y,9,171,25 );
	gfx.PutPixel( 5 + x,11 + y,9,171,25 );
	gfx.PutPixel( 6 + x,11 + y,9,171,25 );
	gfx.PutPixel( 7 + x,11 + y,9,171,25 );
	gfx.PutPixel( 8 + x,11 + y,9,171,25 );
	gfx.PutPixel( 9 + x,11 + y,9,171,25 );
	gfx.PutPixel( 10 + x,11 + y,9,171,25 );
	gfx.PutPixel( 11 + x,11 + y,9,171,25 );
	gfx.PutPixel( 12 + x,11 + y,9,171,25 );
	gfx.PutPixel( 13 + x,11 + y,9,171,25 );
	gfx.PutPixel( 14 + x,11 + y,9,171,25 );
	gfx.PutPixel( 15 + x,11 + y,9,171,25 );
	gfx.PutPixel( 16 + x,11 + y,9,171,25 );
	gfx.PutPixel( 17 + x,11 + y,9,171,25 );
	gfx.PutPixel( 18 + x,11 + y,9,171,25 );
	gfx.PutPixel( 19 + x,11 + y,9,171,25 );
	gfx.PutPixel( 20 + x,11 + y,9,171,25 );
	gfx.PutPixel( 21 + x,11 + y,9,171,25 );
	gfx.PutPixel( 22 + x,11 + y,9,171,25 );
	gfx.PutPixel( 23 + x,11 + y,9,171,25 );
	gfx.PutPixel( 24 + x,11 + y,9,171,25 );
	gfx.PutPixel( 25 + x,11 + y,9,171,25 );
	gfx.PutPixel( 26 + x,11 + y,9,171,25 );
	gfx.PutPixel( 27 + x,11 + y,9,171,25 );
	gfx.PutPixel( 28 + x,11 + y,9,171,25 );
	gfx.PutPixel( 29 + x,11 + y,9,171,25 );
	gfx.PutPixel( 30 + x,11 + y,9,171,25 );
	gfx.PutPixel( 31 + x,11 + y,9,171,25 );
	gfx.PutPixel( 32 + x,11 + y,9,171,25 );
	gfx.PutPixel( 33 + x,11 + y,9,171,25 );
	gfx.PutPixel( 34 + x,11 + y,9,171,25 );
	gfx.PutPixel( 35 + x,11 + y,9,171,25 );
	gfx.PutPixel( 36 + x,11 + y,9,171,25 );
	gfx.PutPixel( 37 + x,11 + y,9,171,25 );
	gfx.PutPixel( 38 + x,11 + y,9,171,25 );
	gfx.PutPixel( 39 + x,11 + y,9,171,25 );
	gfx.PutPixel( 0 + x,12 + y,9,171,25 );
	gfx.PutPixel( 1 + x,12 + y,9,171,25 );
	gfx.PutPixel( 2 + x,12 + y,9,171,25 );
	gfx.PutPixel( 3 + x,12 + y,9,171,25 );
	gfx.PutPixel( 4 + x,12 + y,9,171,25 );
	gfx.PutPixel( 5 + x,12 + y,9,171,25 );
	gfx.PutPixel( 6 + x,12 + y,9,171,25 );
	gfx.PutPixel( 7 + x,12 + y,9,171,25 );
	gfx.PutPixel( 8 + x,12 + y,9,171,25 );
	gfx.PutPixel( 9 + x,12 + y,9,171,25 );
	gfx.PutPixel( 10 + x,12 + y,9,171,25 );
	gfx.PutPixel( 11 + x,12 + y,9,171,25 );
	gfx.PutPixel( 12 + x,12 + y,9,171,25 );
	gfx.PutPixel( 13 + x,12 + y,9,171,25 );
	gfx.PutPixel( 14 + x,12 + y,9,171,25 );
	gfx.PutPixel( 15 + x,12 + y,9,171,25 );
	gfx.PutPixel( 16 + x,12 + y,9,171,25 );
	gfx.PutPixel( 17 + x,12 + y,9,171,25 );
	gfx.PutPixel( 18 + x,12 + y,9,171,25 );
	gfx.PutPixel( 19 + x,12 + y,9,171,25 );
	gfx.PutPixel( 20 + x,12 + y,9,171,25 );
	gfx.PutPixel( 21 + x,12 + y,9,171,25 );
	gfx.PutPixel( 22 + x,12 + y,9,171,25 );
	gfx.PutPixel( 23 + x,12 + y,9,171,25 );
	gfx.PutPixel( 24 + x,12 + y,9,171,25 );
	gfx.PutPixel( 25 + x,12 + y,9,171,25 );
	gfx.PutPixel( 26 + x,12 + y,9,171,25 );
	gfx.PutPixel( 27 + x,12 + y,9,171,25 );
	gfx.PutPixel( 28 + x,12 + y,9,171,25 );
	gfx.PutPixel( 29 + x,12 + y,9,171,25 );
	gfx.PutPixel( 30 + x,12 + y,9,171,25 );
	gfx.PutPixel( 31 + x,12 + y,9,171,25 );
	gfx.PutPixel( 32 + x,12 + y,9,171,25 );
	gfx.PutPixel( 33 + x,12 + y,9,171,25 );
	gfx.PutPixel( 34 + x,12 + y,9,171,25 );
	gfx.PutPixel( 35 + x,12 + y,9,171,25 );
	gfx.PutPixel( 36 + x,12 + y,9,171,25 );
	gfx.PutPixel( 37 + x,12 + y,9,171,25 );
	gfx.PutPixel( 38 + x,12 + y,9,171,25 );
	gfx.PutPixel( 39 + x,12 + y,9,171,25 );
	gfx.PutPixel( 0 + x,13 + y,9,171,25 );
	gfx.PutPixel( 1 + x,13 + y,9,171,25 );
	gfx.PutPixel( 2 + x,13 + y,9,171,25 );
	gfx.PutPixel( 3 + x,13 + y,9,171,25 );
	gfx.PutPixel( 4 + x,13 + y,9,171,25 );
	gfx.PutPixel( 5 + x,13 + y,9,171,25 );
	gfx.PutPixel( 6 + x,13 + y,9,171,25 );
	gfx.PutPixel( 7 + x,13 + y,9,171,25 );
	gfx.PutPixel( 8 + x,13 + y,9,171,25 );
	gfx.PutPixel( 9 + x,13 + y,9,171,25 );
	gfx.PutPixel( 10 + x,13 + y,9,171,25 );
	gfx.PutPixel( 11 + x,13 + y,9,171,25 );
	gfx.PutPixel( 12 + x,13 + y,9,171,25 );
	gfx.PutPixel( 13 + x,13 + y,9,171,25 );
	gfx.PutPixel( 14 + x,13 + y,9,171,25 );
	gfx.PutPixel( 15 + x,13 + y,9,171,25 );
	gfx.PutPixel( 16 + x,13 + y,9,171,25 );
	gfx.PutPixel( 17 + x,13 + y,9,171,25 );
	gfx.PutPixel( 18 + x,13 + y,9,171,25 );
	gfx.PutPixel( 21 + x,13 + y,9,171,25 );
	gfx.PutPixel( 22 + x,13 + y,9,171,25 );
	gfx.PutPixel( 23 + x,13 + y,9,171,25 );
	gfx.PutPixel( 24 + x,13 + y,9,171,25 );
	gfx.PutPixel( 25 + x,13 + y,9,171,25 );
	gfx.PutPixel( 26 + x,13 + y,9,171,25 );
	gfx.PutPixel( 27 + x,13 + y,9,171,25 );
	gfx.PutPixel( 28 + x,13 + y,9,171,25 );
	gfx.PutPixel( 29 + x,13 + y,9,171,25 );
	gfx.PutPixel( 30 + x,13 + y,9,171,25 );
	gfx.PutPixel( 31 + x,13 + y,9,171,25 );
	gfx.PutPixel( 32 + x,13 + y,9,171,25 );
	gfx.PutPixel( 33 + x,13 + y,9,171,25 );
	gfx.PutPixel( 34 + x,13 + y,9,171,25 );
	gfx.PutPixel( 35 + x,13 + y,9,171,25 );
	gfx.PutPixel( 36 + x,13 + y,9,171,25 );
	gfx.PutPixel( 37 + x,13 + y,9,171,25 );
	gfx.PutPixel( 38 + x,13 + y,9,171,25 );
	gfx.PutPixel( 39 + x,13 + y,9,171,25 );
	gfx.PutPixel( 0 + x,14 + y,9,171,25 );
	gfx.PutPixel( 1 + x,14 + y,9,171,25 );
	gfx.PutPixel( 2 + x,14 + y,9,171,25 );
	gfx.PutPixel( 3 + x,14 + y,9,171,25 );
	gfx.PutPixel( 4 + x,14 + y,9,171,25 );
	gfx.PutPixel( 5 + x,14 + y,9,171,25 );
	gfx.PutPixel( 6 + x,14 + y,9,171,25 );
	gfx.PutPixel( 7 + x,14 + y,9,171,25 );
	gfx.PutPixel( 8 + x,14 + y,9,171,25 );
	gfx.PutPixel( 9 + x,14 + y,9,171,25 );
	gfx.PutPixel( 10 + x,14 + y,9,171,25 );
	gfx.PutPixel( 11 + x,14 + y,9,171,25 );
	gfx.PutPixel( 12 + x,14 + y,9,171,25 );
	gfx.PutPixel( 13 + x,14 + y,9,171,25 );
	gfx.PutPixel( 14 + x,14 + y,9,171,25 );
	gfx.PutPixel( 15 + x,14 + y,9,171,25 );
	gfx.PutPixel( 16 + x,14 + y,9,171,25 );
	gfx.PutPixel( 17 + x,14 + y,9,171,25 );
	gfx.PutPixel( 22 + x,14 + y,9,171,25 );
	gfx.PutPixel( 23 + x,14 + y,9,171,25 );
	gfx.PutPixel( 24 + x,14 + y,9,171,25 );
	gfx.PutPixel( 25 + x,14 + y,9,171,25 );
	gfx.PutPixel( 26 + x,14 + y,9,171,25 );
	gfx.PutPixel( 27 + x,14 + y,9,171,25 );
	gfx.PutPixel( 28 + x,14 + y,9,171,25 );
	gfx.PutPixel( 29 + x,14 + y,9,171,25 );
	gfx.PutPixel( 30 + x,14 + y,9,171,25 );
	gfx.PutPixel( 31 + x,14 + y,9,171,25 );
	gfx.PutPixel( 32 + x,14 + y,9,171,25 );
	gfx.PutPixel( 33 + x,14 + y,9,171,25 );
	gfx.PutPixel( 34 + x,14 + y,9,171,25 );
	gfx.PutPixel( 35 + x,14 + y,9,171,25 );
	gfx.PutPixel( 36 + x,14 + y,9,171,25 );
	gfx.PutPixel( 37 + x,14 + y,9,171,25 );
	gfx.PutPixel( 38 + x,14 + y,9,171,25 );
	gfx.PutPixel( 39 + x,14 + y,9,171,25 );
	gfx.PutPixel( 0 + x,15 + y,9,171,25 );
	gfx.PutPixel( 1 + x,15 + y,9,171,25 );
	gfx.PutPixel( 2 + x,15 + y,9,171,25 );
	gfx.PutPixel( 3 + x,15 + y,9,171,25 );
	gfx.PutPixel( 4 + x,15 + y,9,171,25 );
	gfx.PutPixel( 5 + x,15 + y,9,171,25 );
	gfx.PutPixel( 6 + x,15 + y,9,171,25 );
	gfx.PutPixel( 7 + x,15 + y,9,171,25 );
	gfx.PutPixel( 8 + x,15 + y,9,171,25 );
	gfx.PutPixel( 9 + x,15 + y,9,171,25 );
	gfx.PutPixel( 10 + x,15 + y,9,171,25 );
	gfx.PutPixel( 11 + x,15 + y,9,171,25 );
	gfx.PutPixel( 12 + x,15 + y,9,171,25 );
	gfx.PutPixel( 13 + x,15 + y,9,171,25 );
	gfx.PutPixel( 14 + x,15 + y,9,171,25 );
	gfx.PutPixel( 15 + x,15 + y,9,171,25 );
	gfx.PutPixel( 16 + x,15 + y,9,171,25 );
	gfx.PutPixel( 23 + x,15 + y,9,171,25 );
	gfx.PutPixel( 24 + x,15 + y,9,171,25 );
	gfx.PutPixel( 25 + x,15 + y,9,171,25 );
	gfx.PutPixel( 26 + x,15 + y,9,171,25 );
	gfx.PutPixel( 27 + x,15 + y,9,171,25 );
	gfx.PutPixel( 28 + x,15 + y,9,171,25 );
	gfx.PutPixel( 29 + x,15 + y,9,171,25 );
	gfx.PutPixel( 30 + x,15 + y,9,171,25 );
	gfx.PutPixel( 31 + x,15 + y,9,171,25 );
	gfx.PutPixel( 32 + x,15 + y,9,171,25 );
	gfx.PutPixel( 33 + x,15 + y,9,171,25 );
	gfx.PutPixel( 34 + x,15 + y,9,171,25 );
	gfx.PutPixel( 35 + x,15 + y,9,171,25 );
	gfx.PutPixel( 36 + x,15 + y,9,171,25 );
	gfx.PutPixel( 37 + x,15 + y,9,171,25 );
	gfx.PutPixel( 38 + x,15 + y,9,171,25 );
	gfx.PutPixel( 39 + x,15 + y,9,171,25 );
	gfx.PutPixel( 0 + x,16 + y,9,171,25 );
	gfx.PutPixel( 1 + x,16 + y,9,171,25 );
	gfx.PutPixel( 2 + x,16 + y,9,171,25 );
	gfx.PutPixel( 3 + x,16 + y,9,171,25 );
	gfx.PutPixel( 4 + x,16 + y,9,171,25 );
	gfx.PutPixel( 5 + x,16 + y,9,171,25 );
	gfx.PutPixel( 6 + x,16 + y,9,171,25 );
	gfx.PutPixel( 7 + x,16 + y,9,171,25 );
	gfx.PutPixel( 8 + x,16 + y,9,171,25 );
	gfx.PutPixel( 9 + x,16 + y,9,171,25 );
	gfx.PutPixel( 10 + x,16 + y,9,171,25 );
	gfx.PutPixel( 11 + x,16 + y,9,171,25 );
	gfx.PutPixel( 12 + x,16 + y,9,171,25 );
	gfx.PutPixel( 13 + x,16 + y,9,171,25 );
	gfx.PutPixel( 14 + x,16 + y,9,171,25 );
	gfx.PutPixel( 15 + x,16 + y,9,171,25 );
	gfx.PutPixel( 24 + x,16 + y,9,171,25 );
	gfx.PutPixel( 25 + x,16 + y,9,171,25 );
	gfx.PutPixel( 26 + x,16 + y,9,171,25 );
	gfx.PutPixel( 27 + x,16 + y,9,171,25 );
	gfx.PutPixel( 28 + x,16 + y,9,171,25 );
	gfx.PutPixel( 29 + x,16 + y,9,171,25 );
	gfx.PutPixel( 30 + x,16 + y,9,171,25 );
	gfx.PutPixel( 31 + x,16 + y,9,171,25 );
	gfx.PutPixel( 32 + x,16 + y,9,171,25 );
	gfx.PutPixel( 33 + x,16 + y,9,171,25 );
	gfx.PutPixel( 34 + x,16 + y,9,171,25 );
	gfx.PutPixel( 35 + x,16 + y,9,171,25 );
	gfx.PutPixel( 36 + x,16 + y,9,171,25 );
	gfx.PutPixel( 37 + x,16 + y,9,171,25 );
	gfx.PutPixel( 38 + x,16 + y,9,171,25 );
	gfx.PutPixel( 39 + x,16 + y,9,171,25 );
	gfx.PutPixel( 0 + x,17 + y,9,171,25 );
	gfx.PutPixel( 1 + x,17 + y,9,171,25 );
	gfx.PutPixel( 2 + x,17 + y,9,171,25 );
	gfx.PutPixel( 3 + x,17 + y,9,171,25 );
	gfx.PutPixel( 4 + x,17 + y,9,171,25 );
	gfx.PutPixel( 5 + x,17 + y,9,171,25 );
	gfx.PutPixel( 6 + x,17 + y,9,171,25 );
	gfx.PutPixel( 7 + x,17 + y,9,171,25 );
	gfx.PutPixel( 8 + x,17 + y,9,171,25 );
	gfx.PutPixel( 9 + x,17 + y,9,171,25 );
	gfx.PutPixel( 10 + x,17 + y,9,171,25 );
	gfx.PutPixel( 11 + x,17 + y,9,171,25 );
	gfx.PutPixel( 12 + x,17 + y,9,171,25 );
	gfx.PutPixel( 13 + x,17 + y,9,171,25 );
	gfx.PutPixel( 14 + x,17 + y,9,171,25 );
	gfx.PutPixel( 25 + x,17 + y,9,171,25 );
	gfx.PutPixel( 26 + x,17 + y,9,171,25 );
	gfx.PutPixel( 27 + x,17 + y,9,171,25 );
	gfx.PutPixel( 28 + x,17 + y,9,171,25 );
	gfx.PutPixel( 29 + x,17 + y,9,171,25 );
	gfx.PutPixel( 30 + x,17 + y,9,171,25 );
	gfx.PutPixel( 31 + x,17 + y,9,171,25 );
	gfx.PutPixel( 32 + x,17 + y,9,171,25 );
	gfx.PutPixel( 33 + x,17 + y,9,171,25 );
	gfx.PutPixel( 34 + x,17 + y,9,171,25 );
	gfx.PutPixel( 35 + x,17 + y,9,171,25 );
	gfx.PutPixel( 36 + x,17 + y,9,171,25 );
	gfx.PutPixel( 37 + x,17 + y,9,171,25 );
	gfx.PutPixel( 38 + x,17 + y,9,171,25 );
	gfx.PutPixel( 39 + x,17 + y,9,171,25 );
	gfx.PutPixel( 0 + x,18 + y,9,171,25 );
	gfx.PutPixel( 1 + x,18 + y,9,171,25 );
	gfx.PutPixel( 2 + x,18 + y,9,171,25 );
	gfx.PutPixel( 3 + x,18 + y,9,171,25 );
	gfx.PutPixel( 4 + x,18 + y,9,171,25 );
	gfx.PutPixel( 5 + x,18 + y,9,171,25 );
	gfx.PutPixel( 6 + x,18 + y,9,171,25 );
	gfx.PutPixel( 7 + x,18 + y,9,171,25 );
	gfx.PutPixel( 8 + x,18 + y,9,171,25 );
	gfx.PutPixel( 9 + x,18 + y,9,171,25 );
	gfx.PutPixel( 10 + x,18 + y,9,171,25 );
	gfx.PutPixel( 11 + x,18 + y,9,171,25 );
	gfx.PutPixel( 12 + x,18 + y,9,171,25 );
	gfx.PutPixel( 13 + x,18 + y,9,171,25 );
	gfx.PutPixel( 26 + x,18 + y,9,171,25 );
	gfx.PutPixel( 27 + x,18 + y,9,171,25 );
	gfx.PutPixel( 28 + x,18 + y,9,171,25 );
	gfx.PutPixel( 29 + x,18 + y,9,171,25 );
	gfx.PutPixel( 30 + x,18 + y,9,171,25 );
	gfx.PutPixel( 31 + x,18 + y,9,171,25 );
	gfx.PutPixel( 32 + x,18 + y,9,171,25 );
	gfx.PutPixel( 33 + x,18 + y,9,171,25 );
	gfx.PutPixel( 34 + x,18 + y,9,171,25 );
	gfx.PutPixel( 35 + x,18 + y,9,171,25 );
	gfx.PutPixel( 36 + x,18 + y,9,171,25 );
	gfx.PutPixel( 37 + x,18 + y,9,171,25 );
	gfx.PutPixel( 38 + x,18 + y,9,171,25 );
	gfx.PutPixel( 39 + x,18 + y,9,171,25 );
	gfx.PutPixel( 0 + x,19 + y,9,171,25 );
	gfx.PutPixel( 1 + x,19 + y,9,171,25 );
	gfx.PutPixel( 2 + x,19 + y,9,171,25 );
	gfx.PutPixel( 3 + x,19 + y,9,171,25 );
	gfx.PutPixel( 4 + x,19 + y,9,171,25 );
	gfx.PutPixel( 5 + x,19 + y,9,171,25 );
	gfx.PutPixel( 6 + x,19 + y,9,171,25 );
	gfx.PutPixel( 7 + x,19 + y,9,171,25 );
	gfx.PutPixel( 8 + x,19 + y,9,171,25 );
	gfx.PutPixel( 9 + x,19 + y,9,171,25 );
	gfx.PutPixel( 10 + x,19 + y,9,171,25 );
	gfx.PutPixel( 11 + x,19 + y,9,171,25 );
	gfx.PutPixel( 12 + x,19 + y,9,171,25 );
	gfx.PutPixel( 27 + x,19 + y,9,171,25 );
	gfx.PutPixel( 28 + x,19 + y,9,171,25 );
	gfx.PutPixel( 29 + x,19 + y,9,171,25 );
	gfx.PutPixel( 30 + x,19 + y,9,171,25 );
	gfx.PutPixel( 31 + x,19 + y,9,171,25 );
	gfx.PutPixel( 32 + x,19 + y,9,171,25 );
	gfx.PutPixel( 33 + x,19 + y,9,171,25 );
	gfx.PutPixel( 34 + x,19 + y,9,171,25 );
	gfx.PutPixel( 35 + x,19 + y,9,171,25 );
	gfx.PutPixel( 36 + x,19 + y,9,171,25 );
	gfx.PutPixel( 37 + x,19 + y,9,171,25 );
	gfx.PutPixel( 38 + x,19 + y,9,171,25 );
	gfx.PutPixel( 39 + x,19 + y,9,171,25 );
	gfx.PutPixel( 0 + x,20 + y,9,171,25 );
	gfx.PutPixel( 1 + x,20 + y,9,171,25 );
	gfx.PutPixel( 2 + x,20 + y,9,171,25 );
	gfx.PutPixel( 3 + x,20 + y,9,171,25 );
	gfx.PutPixel( 4 + x,20 + y,9,171,25 );
	gfx.PutPixel( 5 + x,20 + y,9,171,25 );
	gfx.PutPixel( 6 + x,20 + y,9,171,25 );
	gfx.PutPixel( 7 + x,20 + y,9,171,25 );
	gfx.PutPixel( 8 + x,20 + y,9,171,25 );
	gfx.PutPixel( 9 + x,20 + y,9,171,25 );
	gfx.PutPixel( 10 + x,20 + y,9,171,25 );
	gfx.PutPixel( 11 + x,20 + y,9,171,25 );
	gfx.PutPixel( 28 + x,20 + y,9,171,25 );
	gfx.PutPixel( 29 + x,20 + y,9,171,25 );
	gfx.PutPixel( 30 + x,20 + y,9,171,25 );
	gfx.PutPixel( 31 + x,20 + y,9,171,25 );
	gfx.PutPixel( 32 + x,20 + y,9,171,25 );
	gfx.PutPixel( 33 + x,20 + y,9,171,25 );
	gfx.PutPixel( 34 + x,20 + y,9,171,25 );
	gfx.PutPixel( 35 + x,20 + y,9,171,25 );
	gfx.PutPixel( 36 + x,20 + y,9,171,25 );
	gfx.PutPixel( 37 + x,20 + y,9,171,25 );
	gfx.PutPixel( 38 + x,20 + y,9,171,25 );
	gfx.PutPixel( 39 + x,20 + y,9,171,25 );
	gfx.PutPixel( 0 + x,21 + y,9,171,25 );
	gfx.PutPixel( 1 + x,21 + y,9,171,25 );
	gfx.PutPixel( 2 + x,21 + y,9,171,25 );
	gfx.PutPixel( 3 + x,21 + y,9,171,25 );
	gfx.PutPixel( 4 + x,21 + y,9,171,25 );
	gfx.PutPixel( 5 + x,21 + y,9,171,25 );
	gfx.PutPixel( 6 + x,21 + y,9,171,25 );
	gfx.PutPixel( 7 + x,21 + y,9,171,25 );
	gfx.PutPixel( 8 + x,21 + y,9,171,25 );
	gfx.PutPixel( 9 + x,21 + y,9,171,25 );
	gfx.PutPixel( 10 + x,21 + y,9,171,25 );
	gfx.PutPixel( 29 + x,21 + y,9,171,25 );
	gfx.PutPixel( 30 + x,21 + y,9,171,25 );
	gfx.PutPixel( 31 + x,21 + y,9,171,25 );
	gfx.PutPixel( 32 + x,21 + y,9,171,25 );
	gfx.PutPixel( 33 + x,21 + y,9,171,25 );
	gfx.PutPixel( 34 + x,21 + y,9,171,25 );
	gfx.PutPixel( 35 + x,21 + y,9,171,25 );
	gfx.PutPixel( 36 + x,21 + y,9,171,25 );
	gfx.PutPixel( 37 + x,21 + y,9,171,25 );
	gfx.PutPixel( 38 + x,21 + y,9,171,25 );
	gfx.PutPixel( 39 + x,21 + y,9,171,25 );
	gfx.PutPixel( 0 + x,22 + y,9,171,25 );
	gfx.PutPixel( 1 + x,22 + y,9,171,25 );
	gfx.PutPixel( 2 + x,22 + y,9,171,25 );
	gfx.PutPixel( 3 + x,22 + y,9,171,25 );
	gfx.PutPixel( 4 + x,22 + y,9,171,25 );
	gfx.PutPixel( 5 + x,22 + y,9,171,25 );
	gfx.PutPixel( 6 + x,22 + y,9,171,25 );
	gfx.PutPixel( 7 + x,22 + y,9,171,25 );
	gfx.PutPixel( 8 + x,22 + y,9,171,25 );
	gfx.PutPixel( 9 + x,22 + y,9,171,25 );
	gfx.PutPixel( 30 + x,22 + y,9,171,25 );
	gfx.PutPixel( 31 + x,22 + y,9,171,25 );
	gfx.PutPixel( 32 + x,22 + y,9,171,25 );
	gfx.PutPixel( 33 + x,22 + y,9,171,25 );
	gfx.PutPixel( 34 + x,22 + y,9,171,25 );
	gfx.PutPixel( 35 + x,22 + y,9,171,25 );
	gfx.PutPixel( 36 + x,22 + y,9,171,25 );
	gfx.PutPixel( 37 + x,22 + y,9,171,25 );
	gfx.PutPixel( 38 + x,22 + y,9,171,25 );
	gfx.PutPixel( 39 + x,22 + y,9,171,25 );
	gfx.PutPixel( 0 + x,23 + y,9,171,25 );
	gfx.PutPixel( 1 + x,23 + y,9,171,25 );
	gfx.PutPixel( 2 + x,23 + y,9,171,25 );
	gfx.PutPixel( 3 + x,23 + y,9,171,25 );
	gfx.PutPixel( 4 + x,23 + y,9,171,25 );
	gfx.PutPixel( 5 + x,23 + y,9,171,25 );
	gfx.PutPixel( 6 + x,23 + y,9,171,25 );
	gfx.PutPixel( 7 + x,23 + y,9,171,25 );
	gfx.PutPixel( 8 + x,23 + y,9,171,25 );
	gfx.PutPixel( 9 + x,23 + y,9,171,25 );
	gfx.PutPixel( 30 + x,23 + y,9,171,25 );
	gfx.PutPixel( 31 + x,23 + y,9,171,25 );
	gfx.PutPixel( 32 + x,23 + y,9,171,25 );
	gfx.PutPixel( 33 + x,23 + y,9,171,25 );
	gfx.PutPixel( 34 + x,23 + y,9,171,25 );
	gfx.PutPixel( 35 + x,23 + y,9,171,25 );
	gfx.PutPixel( 36 + x,23 + y,9,171,25 );
	gfx.PutPixel( 37 + x,23 + y,9,171,25 );
	gfx.PutPixel( 38 + x,23 + y,9,171,25 );
	gfx.PutPixel( 39 + x,23 + y,9,171,25 );
	gfx.PutPixel( 0 + x,24 + y,9,171,25 );
	gfx.PutPixel( 1 + x,24 + y,9,171,25 );
	gfx.PutPixel( 2 + x,24 + y,9,171,25 );
	gfx.PutPixel( 3 + x,24 + y,9,171,25 );
	gfx.PutPixel( 4 + x,24 + y,9,171,25 );
	gfx.PutPixel( 5 + x,24 + y,9,171,25 );
	gfx.PutPixel( 6 + x,24 + y,9,171,25 );
	gfx.PutPixel( 7 + x,24 + y,9,171,25 );
	gfx.PutPixel( 8 + x,24 + y,9,171,25 );
	gfx.PutPixel( 9 + x,24 + y,9,171,25 );
	gfx.PutPixel( 30 + x,24 + y,9,171,25 );
	gfx.PutPixel( 31 + x,24 + y,9,171,25 );
	gfx.PutPixel( 32 + x,24 + y,9,171,25 );
	gfx.PutPixel( 33 + x,24 + y,9,171,25 );
	gfx.PutPixel( 34 + x,24 + y,9,171,25 );
	gfx.PutPixel( 35 + x,24 + y,9,171,25 );
	gfx.PutPixel( 36 + x,24 + y,9,171,25 );
	gfx.PutPixel( 37 + x,24 + y,9,171,25 );
	gfx.PutPixel( 38 + x,24 + y,9,171,25 );
	gfx.PutPixel( 39 + x,24 + y,9,171,25 );
	gfx.PutPixel( 0 + x,25 + y,9,171,25 );
	gfx.PutPixel( 1 + x,25 + y,9,171,25 );
	gfx.PutPixel( 2 + x,25 + y,9,171,25 );
	gfx.PutPixel( 3 + x,25 + y,9,171,25 );
	gfx.PutPixel( 4 + x,25 + y,9,171,25 );
	gfx.PutPixel( 5 + x,25 + y,9,171,25 );
	gfx.PutPixel( 6 + x,25 + y,9,171,25 );
	gfx.PutPixel( 7 + x,25 + y,9,171,25 );
	gfx.PutPixel( 8 + x,25 + y,9,171,25 );
	gfx.PutPixel( 9 + x,25 + y,9,171,25 );
	gfx.PutPixel( 30 + x,25 + y,9,171,25 );
	gfx.PutPixel( 31 + x,25 + y,9,171,25 );
	gfx.PutPixel( 32 + x,25 + y,9,171,25 );
	gfx.PutPixel( 33 + x,25 + y,9,171,25 );
	gfx.PutPixel( 34 + x,25 + y,9,171,25 );
	gfx.PutPixel( 35 + x,25 + y,9,171,25 );
	gfx.PutPixel( 36 + x,25 + y,9,171,25 );
	gfx.PutPixel( 37 + x,25 + y,9,171,25 );
	gfx.PutPixel( 38 + x,25 + y,9,171,25 );
	gfx.PutPixel( 39 + x,25 + y,9,171,25 );
	gfx.PutPixel( 0 + x,26 + y,9,171,25 );
	gfx.PutPixel( 1 + x,26 + y,9,171,25 );
	gfx.PutPixel( 2 + x,26 + y,9,171,25 );
	gfx.PutPixel( 3 + x,26 + y,9,171,25 );
	gfx.PutPixel( 4 + x,26 + y,9,171,25 );
	gfx.PutPixel( 5 + x,26 + y,9,171,25 );
	gfx.PutPixel( 6 + x,26 + y,9,171,25 );
	gfx.PutPixel( 7 + x,26 + y,9,171,25 );
	gfx.PutPixel( 8 + x,26 + y,9,171,25 );
	gfx.PutPixel( 9 + x,26 + y,9,171,25 );
	gfx.PutPixel( 30 + x,26 + y,9,171,25 );
	gfx.PutPixel( 31 + x,26 + y,9,171,25 );
	gfx.PutPixel( 32 + x,26 + y,9,171,25 );
	gfx.PutPixel( 33 + x,26 + y,9,171,25 );
	gfx.PutPixel( 34 + x,26 + y,9,171,25 );
	gfx.PutPixel( 35 + x,26 + y,9,171,25 );
	gfx.PutPixel( 36 + x,26 + y,9,171,25 );
	gfx.PutPixel( 37 + x,26 + y,9,171,25 );
	gfx.PutPixel( 38 + x,26 + y,9,171,25 );
	gfx.PutPixel( 39 + x,26 + y,9,171,25 );
	gfx.PutPixel( 0 + x,27 + y,9,171,25 );
	gfx.PutPixel( 1 + x,27 + y,9,171,25 );
	gfx.PutPixel( 2 + x,27 + y,9,171,25 );
	gfx.PutPixel( 3 + x,27 + y,9,171,25 );
	gfx.PutPixel( 4 + x,27 + y,9,171,25 );
	gfx.PutPixel( 5 + x,27 + y,9,171,25 );
	gfx.PutPixel( 6 + x,27 + y,9,171,25 );
	gfx.PutPixel( 7 + x,27 + y,9,171,25 );
	gfx.PutPixel( 8 + x,27 + y,9,171,25 );
	gfx.PutPixel( 9 + x,27 + y,9,171,25 );
	gfx.PutPixel( 30 + x,27 + y,9,171,25 );
	gfx.PutPixel( 31 + x,27 + y,9,171,25 );
	gfx.PutPixel( 32 + x,27 + y,9,171,25 );
	gfx.PutPixel( 33 + x,27 + y,9,171,25 );
	gfx.PutPixel( 34 + x,27 + y,9,171,25 );
	gfx.PutPixel( 35 + x,27 + y,9,171,25 );
	gfx.PutPixel( 36 + x,27 + y,9,171,25 );
	gfx.PutPixel( 37 + x,27 + y,9,171,25 );
	gfx.PutPixel( 38 + x,27 + y,9,171,25 );
	gfx.PutPixel( 39 + x,27 + y,9,171,25 );
	gfx.PutPixel( 0 + x,28 + y,9,171,25 );
	gfx.PutPixel( 1 + x,28 + y,9,171,25 );
	gfx.PutPixel( 2 + x,28 + y,9,171,25 );
	gfx.PutPixel( 3 + x,28 + y,9,171,25 );
	gfx.PutPixel( 4 + x,28 + y,9,171,25 );
	gfx.PutPixel( 5 + x,28 + y,9,171,25 );
	gfx.PutPixel( 6 + x,28 + y,9,171,25 );
	gfx.PutPixel( 7 + x,28 + y,9,171,25 );
	gfx.PutPixel( 8 + x,28 + y,9,171,25 );
	gfx.PutPixel( 9 + x,28 + y,9,171,25 );
	gfx.PutPixel( 30 + x,28 + y,9,171,25 );
	gfx.PutPixel( 31 + x,28 + y,9,171,25 );
	gfx.PutPixel( 32 + x,28 + y,9,171,25 );
	gfx.PutPixel( 33 + x,28 + y,9,171,25 );
	gfx.PutPixel( 34 + x,28 + y,9,171,25 );
	gfx.PutPixel( 35 + x,28 + y,9,171,25 );
	gfx.PutPixel( 36 + x,28 + y,9,171,25 );
	gfx.PutPixel( 37 + x,28 + y,9,171,25 );
	gfx.PutPixel( 38 + x,28 + y,9,171,25 );
	gfx.PutPixel( 39 + x,28 + y,9,171,25 );
	gfx.PutPixel( 0 + x,29 + y,9,164,24 );
	gfx.PutPixel( 1 + x,29 + y,9,164,24 );
	gfx.PutPixel( 2 + x,29 + y,9,164,24 );
	gfx.PutPixel( 3 + x,29 + y,9,164,24 );
	gfx.PutPixel( 4 + x,29 + y,9,164,24 );
	gfx.PutPixel( 5 + x,29 + y,9,164,24 );
	gfx.PutPixel( 6 + x,29 + y,9,164,24 );
	gfx.PutPixel( 7 + x,29 + y,9,164,24 );
	gfx.PutPixel( 8 + x,29 + y,9,164,24 );
	gfx.PutPixel( 9 + x,29 + y,9,164,24 );
	gfx.PutPixel( 30 + x,29 + y,9,164,24 );
	gfx.PutPixel( 31 + x,29 + y,9,164,24 );
	gfx.PutPixel( 32 + x,29 + y,9,164,24 );
	gfx.PutPixel( 33 + x,29 + y,9,164,24 );
	gfx.PutPixel( 34 + x,29 + y,9,164,24 );
	gfx.PutPixel( 35 + x,29 + y,9,164,24 );
	gfx.PutPixel( 36 + x,29 + y,9,164,24 );
	gfx.PutPixel( 37 + x,29 + y,9,164,24 );
	gfx.PutPixel( 38 + x,29 + y,9,164,24 );
	gfx.PutPixel( 39 + x,29 + y,9,164,24 );
}