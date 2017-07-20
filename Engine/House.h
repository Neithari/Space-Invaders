#pragma once

#include "Graphics.h"
#include "Location.h"
#include "Dimention.h"

class House
{
public:
	House( const Location& in_loc );
	Dimention GetDimention() const;
	Location GetLocation() const;
	void Draw( Graphics& gfx );

private:
	static constexpr Dimention dim = { 40,30 };
	Location loc;
};