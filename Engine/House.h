#pragma once

#include "Graphics.h"
#include <string>
#include "Vec2.h"
#include "PixelArt.h"

class House
{
public:
	House( const Vec2& in_loc );

	void Draw( Graphics& gfx );
	bool IsColliding( const Rect& obj );
private:
	const std::string filename = "house.g";
	Vec2 loc;
	PixelArt house;
};