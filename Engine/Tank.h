#pragma once

#include "Graphics.h"
#include "Location.h"
#include "Dimention.h"

class Tank
{
public:
	Dimention GetDimention() const;
	Location GetLocation() const;
	void Draw( Graphics& gfx );

private:
	static constexpr Dimention dim = { 20,18 };
	Location loc;
};