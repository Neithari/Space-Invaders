#pragma once

#include "Graphics.h"
#include "Location.h"
#include "Dimention.h"

class Alien
{
public:
	Dimention GetDimention() const;
	Location GetLocation() const;

private:
	Dimention dim;
	Location loc;
};