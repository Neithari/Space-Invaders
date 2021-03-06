#pragma once

#include "Graphics.h"
#include "Vec2.h"
#include "Invader.h"
#include "AlienShot.h"
#include <random>
#include <vector>
#include "UFO.h"
#include "Sound.h"

class Alien
{
public:
	Alien( Graphics& gfx , const int shotMax, const int shotChance, const Rect<float>* in_pPlaySpace );
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
	// for collision with house
	std::vector<Rect<float>> GetAliensForRow( const int row ) const;
	float GetMoveSpeed() const;
	float GetMoveTime() const;
	bool IsUFOAlive() const;
	const Vec2<int>& GetCollisionLoc() const;
	~Alien();
private:
	void IncreaseSpeed();
	void SetArea();
	void UpdateInvaderAlive();
public:
	static constexpr int columns = 13;
	static constexpr int rows = 5;
	static constexpr int n_small = columns;
	static constexpr int n_mid = columns * 2;
	static constexpr int n_big = columns * 2;
	static constexpr int ufoChance = 5;
	static constexpr int alienSpacing = 10;
private:
	Graphics& gfx;
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> chanceDist;
	std::uniform_int_distribution<int> shotDist;
	int shotChance;
	const Rect<float>* pPlaySpace = nullptr;
	Vec2<int> dim;
	Vec2<float> loc;
	Rect<float> area;
	int count_small = n_small;
	int count_mid = n_mid;
	int count_big = n_big;
	std::vector<Invader> invaderSmall;
	std::vector<Invader> invaderMid;
	std::vector<Invader> invaderBig;
	UFO* pUFO = nullptr;
	bool ufoAlive;
	const float ufoCD = 9.0f;
	float cooldown = 7.0f;
	const int shotMax;
	std::vector<AlienShot> shot;
	bool columnClean[columns] = {};
	int columnsNotClean = columns;
	bool invaderAlive[n_small + n_mid + n_big] = {};
	Vec2<float> delta_loc{ float( alienSpacing ),0 };
	//Timing
	float moveSpeed = 0.5f;
	float increaseSpeed = 0.05f;
	bool speedIncreased = false;
	float moveTime = 0.0f;
	// Explosion Drawing
	Vec2<int> collisionLoc{ 0,0 };
};