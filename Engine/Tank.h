#pragma once

#include "Graphics.h"
#include "Location.h"
#include "Dimention.h"
#include "Keyboard.h"
#include "TankShot.h"

class Tank
{
public:
	Tank();
	Tank( const Location& in_loc );
	const Dimention& GetDimention() const;
	const Location& GetLocation() const;
	void Draw( Graphics& gfx );
	void Update( const Keyboard& kbd );
	const Location& GetShotLoc( const int i ) const;
	const Dimention& GetShotDim() const;
private:
	void DrawTank( Graphics& gfx );
private:
	static constexpr Dimention dim = { 20,18 };
	static constexpr float speed = 1.5f;
	static constexpr int shotMax = 30;
	bool rapidShotPrevent = false;
	TankShot shot[shotMax];
	Location loc;
};