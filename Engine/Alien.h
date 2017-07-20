#pragma once

#include "Graphics.h"
#include "Location.h"
#include "Dimention.h"

class Alien
{
public:
	const Dimention& GetDimention() const;
	const Location& GetLocation() const;

private:
	Dimention dim;
	Location loc;
};