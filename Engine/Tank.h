#pragma once

#include "Graphics.h"
#include "Location.h"
#include "Dimention.h"
#include "Keyboard.h"
#include "TankShot.h"

class Tank
{
public:
	Tank( Graphics& gfx );
	Tank( Graphics& gfx ,const Location& in_loc );
	const Dimention& GetDimention() const;
	const Location& GetLocation() const;
	void Draw();
	void Update( const Keyboard& kbd );
	bool Collision( const Location& in_loc,const Dimention& in_dim );
	const Location GetShotLoc( const int i ) const;
	const Dimention& GetShotDim() const;
	void DeleteShot( const int i );
	bool IsAlive();
private:
	void Kill();
	void DrawTank();
	float ClampToScreen();
private:
	Graphics& gfx;
	static constexpr Dimention dim = { 20,18 };
	static constexpr float speed = 1.5f;
	static constexpr int shotMax = 30;
	bool rapidShotPrevent = false;
	TankShot shot[shotMax];
	Location loc;
	bool isAlive = true;
};