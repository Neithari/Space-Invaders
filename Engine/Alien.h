#pragma once

#include "Graphics.h"
#include "Location.h"
#include "Dimention.h"
#include "InvaderBig.h"
#include "InvaderMid.h"
#include "InvaderSmall.h"

class Alien
{
public:
	const Dimention& GetDimention() const;
	const Location& GetLocation() const;

private:
	Dimention dim;
	Location loc;
};