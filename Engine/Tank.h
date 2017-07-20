#pragma once

#include "Graphics.h"
#include "Location.h"
#include "Dimention.h"
#include "Keyboard.h"

class Tank
{
public:
	Tank( const Location& in_loc);
	Dimention GetDimention() const;
	Location GetLocation() const;
	void Draw( Graphics& gfx );
	void Update( const Keyboard& kbd );
private:
	static constexpr Dimention dim = { 20,18 };
	static constexpr float speed = 1.0f;
	Location loc;
};