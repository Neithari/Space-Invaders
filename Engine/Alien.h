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
	void Draw();
	void Update();
	void Collision( const Location& in_loc,const Dimention& in_dim );

private:
	Graphics& gfx;
	static constexpr int n_small = 15;
	static constexpr int n_mid = 30;
	static constexpr int n_big = 30;
	static constexpr Location loc = { 50,50 };
	static constexpr int alienSpacing = 10;
	int count_small = n_small;
	int count_mid = n_mid;
	int count_big = n_big;
	InvaderSmall invaderSmall[n_small];
	InvaderMid invaderMid[n_mid];
	InvaderBig invaderBig[n_big];
};