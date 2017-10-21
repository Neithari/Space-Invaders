#pragma once
#include "Graphics.h"
#include "Vec2.h"

class Sprite
{
public:
	static void DrawTitle( const int x,const int y,Graphics& gfx );
	static void DrawGameOver( const int x,const int y,Graphics& gfx );
	static void DrawYouWon( const int x,const int y,Graphics& gfx );
	static void DrawAlienShot1( const int x,const int y,Graphics& gfx );
	static void DrawAlienShot2( const int x,const int y,Graphics& gfx );
	static void DrawHouse( const int x,const int y,Graphics& gfx );
	static void DrawInvaderExplosion( const int x,const int y,Graphics& gfx );
	static void DrawInvaderSmall0( const int x,const int y,Graphics& gfx );
	static void DrawInvaderSmall1( const int x,const int y,Graphics& gfx );
	static void DrawInvaderMed0( const int x,const int y,Graphics& gfx );
	static void DrawInvaderMed1( const int x,const int y,Graphics& gfx );
	static void DrawInvaderBig0( const int x,const int y,Graphics& gfx );
	static void DrawInvaderBig1( const int x,const int y,Graphics& gfx );
	static void DrawTank( const int x,const int y,Graphics& gfx );
	static void DrawTankShot( const int x,const int y,Graphics& gfx );
};