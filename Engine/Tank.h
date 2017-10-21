#pragma once

#include "Graphics.h"
#include "Sprite.h"
#include "Vec2.h"
#include "Dimention.h"
#include "Keyboard.h"
#include "TankShot.h"
#include <vector>
#include "Rect.h"

class Tank
{
public:
	Tank( Graphics& gfx );
	Tank( Graphics& gfx,const Vec2<float>& in_loc );
	Tank( const Tank& ) = delete;
	Tank& operator=( const Tank& ) = delete;

	void Restart();
	const Dimention& GetDimention() const;
	const Vec2<float>& GetLocation() const;
	void Draw();
	void Update( const Keyboard& kbd,const float dt );
	bool Collision( const Vec2<float>& in_loc,const Dimention& in_dim ) const;
	bool Collision( const Rect& obj ) const;
	const Vec2<float> GetShotLoc( const int i ) const;
	const Dimention& GetShotDim() const;
	const Rect GetShotRect( const int i ) const;
	const Rect GetTankRect() const;
	const int GetShotCount() const;
	void CreateShot( const Vec2<float>& origin );
	void DeleteShot( const int i );
private:
	float ClampToScreen();
private:
	Graphics& gfx;
	static constexpr Dimention dim = { 20,18 };
	static constexpr float speed = 90.0f;
	const Vec2<float> startLoc;
	Vec2<float> loc;
	bool rapidShotPrevent = false;
	std::vector<TankShot> shot;
	bool isAlive = true;
};