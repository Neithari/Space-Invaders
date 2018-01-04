#pragma once

#include "Graphics.h"
#include "SpriteEffect.h"
#include "Surface.h"
#include "Vec2.h"
#include "Vec2.h"
#include "Keyboard.h"
#include "TankShot.h"
#include <vector>
#include "Rect.h"

class Tank
{
public:
	Tank( Graphics& gfx,const Vec2<float>& in_loc, const Rect<float>* in_pPlaySpace, const int in_maxShotCount );
	Tank( const Tank& ) = delete;
	Tank& operator=( const Tank& ) = delete;

	void Restart();
	const Vec2<int>& GetDimention() const;
	const Vec2<float>& GetLocation() const;
	void Draw();
	void DrawHit();
	void Update( const Keyboard& kbd,const float dt );
	bool Collision( const Vec2<float>& in_loc,const Vec2<int>& in_dim ) const;
	bool Collision( const Rect<float>& obj ) const;
	const Vec2<float> GetShotLoc( const int i ) const;
	const Vec2<int>& GetShotDim() const;
	const Rect<float> GetShotRect( const int i ) const;
	const Rect<float> GetTankRect() const;
	const int GetShotCount() const;
	void CreateShot( const Vec2<float>& origin );
	void DeleteShot( const int i );
	~Tank();
private:
	float ClampToPlaySpace();
public:
	static constexpr Vec2<int> dim = { 20,18 };
	static constexpr float speed = 90.0f;
private:
	Graphics& gfx;
	const Surface sprite = Surface( "Sprites\\Tank20x18.bmp" );
	const Rect<float>* pPlaySpace = nullptr;
	const int maxShotCount;
	const Vec2<float> startLoc;
	Vec2<float> loc;
	bool rapidShotPrevent = false;
	std::vector<TankShot> shot;
	bool isAlive = true;
};