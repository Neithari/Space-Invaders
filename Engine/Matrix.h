#pragma once

#include <vector>
#include <string>
#include <fstream>
#include "Vec2.h"
#include "Rect.h"

class Matrix
{
public:
	Matrix( std::string filename );

	int Index( const int x, const int y ) const;
	void setFalse( const int x, const int y );
public:
	std::vector<bool> matrix;
	Vec2 dim = { 0,0 };
};