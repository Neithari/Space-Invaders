#include "Alien.h"

Alien::Alien( Graphics & gfx )
	:
	gfx( gfx )
{
}

const Dimention& Alien::GetDimention() const
{
	return dim;
}

const Location& Alien::GetLocation() const
{
	return loc;
}

void Alien::Draw()
{

}

void Alien::Update()
{
}
