#pragma once

#include "Graphics.h"
#include "Vec2.h"
#include "Invader.h"
#include "AlienShot.h"
#include <random>
#include <vector>

class Alien
{
public:
	Alien( Graphics& gfx , const int shotMax, const int shotChance, const Rect<float>& playSpace );
	void Draw();
	bool Update( const float dt );
	bool Collision( const Vec2<float>& in_loc,const Vec2<int>& in_dim, unsigned int& score );
	bool Collision( const Rect<float>& other, unsigned int& score );
	Vec2<float> GetShotLoc( const int i ) const;
	const Vec2<int>& GetShotDim() const;
	Rect<float> GetShotRect( const int i ) const;
	bool IsShotAlive( const int i ) const;
	void DeleteShot( const int i );
	int Count() const;
	const Rect<float>& GetRect() const;
	Rect<float> GetRectForRow( const int row ) const;
	int GetBottomRow() const;

private:
	void IncreaseSpeed();
	void SetArea();
	void UpdateInvaderAlive();
private:
	Graphics& gfx;
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> chanceDist;
	std::uniform_int_distribution<int> shotDist;
	const int shotChance;
	static constexpr int columns = 15;
	static constexpr int rows = 5;
	static constexpr int n_small = 15;
	static constexpr int n_mid = 30;
	static constexpr int n_big = 30;
	const Rect<float> playSpace;
	Vec2<int> dim;
	Vec2<float> loc = { 50,50 };
	Rect<float> area;
	static constexpr int alienSpacing = 10;
	int count_small = n_small;
	int count_mid = n_mid;
	int count_big = n_big;
	std::vector<Invader> invaderSmall;
	std::vector<Invader> invaderMid;
	std::vector<Invader> invaderBig;
	const int shotMax;
	std::vector<AlienShot> shot;
	bool columnClean[columns] = {};
	bool invaderAlive[n_small + n_mid + n_big] = {};
	Vec2<float> delta_loc = { float(alienSpacing),0 };
	//Timing
	float moveSpeed = 0.5f;
	float increaseSpeed = 0.05f;
	bool speedIncreased = false;
	float moveTime = 0.0f;
};