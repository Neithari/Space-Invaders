#pragma once

#include "Graphics.h"
#include "Location.h"
#include "Dimention.h"

class Tank
{
public:
	Tank( const Location& in_loc);
	Dimention GetDimention() const;
	Location GetLocation() const;
	void Draw( Graphics& gfx );

private:
	static constexpr Dimention dim = { 20,18 };
	Location loc;
};