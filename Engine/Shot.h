#pragma once

#include "Graphics.h"
#include "Location.h"
#include "Dimention.h"
#include <assert.h>
#include "Tank.h"
#include "Alien.h"

class Shot
{
public:
	Shot();
	Shot( const Location& in_loc );
	void DrawTank( Graphics& gfx ) const;
	void DrawAlien( Graphics& gfx );
	void Initialize( const Location& in_loc );
	void Update();
	/*bool Colliding( const Tank& tank )
	{
		Colliding( tank.GetLocation(),tank.GetDimention );
	};
	bool Colliding( const Alien& alien )
	{
		Colliding( alien.GetLocation(),alien.GetDimention );
	};*/
	bool Colliding( const Location& objL,const Dimention& objD );

private:
	static constexpr Dimention dimAlien = { 3,5 };
	static constexpr Dimention dimTank = { 2,6 };
	static constexpr int toggleTime = 15;
	int toggleIndex = 0;
	Location loc;
	bool isInit = false;
	bool toggle = true;
	bool isColliding = false;
};