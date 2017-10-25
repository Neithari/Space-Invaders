#pragma once

#include "Graphics.h"
#include "Vec2.h"
#include "Vec2.h"
#include "Invader.h"
#include "AlienShot.h"
#include <random>
#include <vector>

class Alien
{
public:
	Alien( Graphics& gfx , const int shotMax, const int shotChance );
	void Draw();
	void Update( const float dt );
	bool Collision( const Vec2<float>& in_loc,const Vec2<int>& in_dim );
	bool Collision( const Rect<float>& other );
	const Vec2<float> GetShotLoc( const int i ) const;
	const Vec2<int>& GetShotDim() const;
	const Rect<float> GetShotRect( const int i ) const;
	bool IsShotAlive( const int i ) const;
	void DeleteShot( const int i );
	int Count();
private:
	bool OutsideBorder( const Vec2<float> & in_loc,const Vec2<int> & in_dim );
private:
	Graphics& gfx;
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> chanceDist;
	std::uniform_int_distribution<int> shotDist;
	const int shotChance;
	static constexpr int n_small = 15;
	static constexpr int n_mid = 30;
	static constexpr int n_big = 30;
	Vec2<int> dim;
	Vec2<float> loc = { 50,50 };
	static constexpr int alienSpacing = 10;
	int count_small = n_small;
	int count_mid = n_mid;
	int count_big = n_big;
	std::vector<Invader> invaderSmall;
	std::vector<Invader> invaderMid;
	std::vector<Invader> invaderBig;
	const int shotMax;
	std::vector<AlienShot> shot;
	bool columnClean[15] = {};
	Vec2<float> delta_loc = { float(alienSpacing),0 };
	//Timing
	float moveSpeed = 0.5f;
	float moveTime = 0.0f;
};