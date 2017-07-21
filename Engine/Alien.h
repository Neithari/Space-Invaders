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
	Alien( Graphics& gfx );
	const Dimention& GetDimention() const;
	const Location& GetLocation() const;
	void Draw();
	void Update();

private:
	Graphics& gfx;
	Dimention dim;
	Location loc;
	static constexpr int n_small = 15;
	static constexpr int n_mid = 30;
	static constexpr int n_big = 30;
	int count_small = n_small;
	int count_mid = n_mid;
	int count_big = n_big;
	InvaderSmall invaderSmall[n_small];
	InvaderMid invaderMid[n_mid];
	InvaderBig invaderBig[n_big];
};