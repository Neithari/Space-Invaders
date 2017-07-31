#pragma once

#include "Graphics.h"
#include "Location.h"
#include "Dimention.h"
#include "InvaderBig.h"
#include "InvaderMid.h"
#include "InvaderSmall.h"
#include "AlienShot.h"
#include <random>

class Alien
{
public:
	Alien( Graphics& gfx );
	void Restart();
	void Draw();
	void Update( const float dt );
	bool Collision( const Location& in_loc,const Dimention& in_dim );
	const Location GetShotLoc( const int i ) const;
	const Dimention& GetShotDim() const;
	void DeleteShot( const int i );
	int Count();
private:
	bool OutsideBorder( const Location & in_loc,const Dimention & in_dim );
private:
	Graphics& gfx;
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> chanceDist;
	std::uniform_int_distribution<int> shotDist;
	static constexpr int chance = 5;
	static constexpr int n_small = 15;
	static constexpr int n_mid = 30;
	static constexpr int n_big = 30;
	Dimention dim;
	Location loc = { 50,50 };
	static constexpr int alienSpacing = 10;
	int count_small = n_small;
	int count_mid = n_mid;
	int count_big = n_big;
	InvaderSmall invaderSmall[n_small];
	InvaderMid invaderMid[n_mid];
	InvaderBig invaderBig[n_big];
	static constexpr int shotMax = 15;
	AlienShot shot[shotMax];
	bool columnClean[15] = {};
	Location delta_loc = { float(alienSpacing),0 };
	//Timing
	float moveSpeed = 1.0f;
	float moveTime = 0.0f;
};