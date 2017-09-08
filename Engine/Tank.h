#pragma once

#include "Graphics.h"
#include "Sprite.h"
#include "Location.h"
#include "Dimention.h"
#include "Keyboard.h"
#include "TankShot.h"
#include <vector>

class Tank
{
public:
	Tank( Graphics& gfx );
	Tank( Graphics& gfx,const Location& in_loc );
	Tank( const Tank& ) = delete;
	Tank& operator=( const Tank& ) = delete;

	void Restart();
	const Dimention& GetDimention() const;
	const Location& GetLocation() const;
	void Draw();
	void Update( const Keyboard& kbd,const float dt );
	bool Collision( const Location& in_loc,const Dimention& in_dim ) const;
	const Location GetShotLoc( const int i ) const;
	const Dimention GetShotDim() const;
	const int GetShotCount() const;
	void CreateShot( const Location& origin );
	void DeleteShot( const int i );
	bool IsAlive() const;
private:
	void Kill();
	float ClampToScreen();
private:
	Graphics& gfx;
	static constexpr Dimention dim = { 20,18 };
	static constexpr float speed = 90.0f;
	bool rapidShotPrevent = false;
	std::vector<TankShot> shot;
	Location loc;
	bool isAlive = true;
};