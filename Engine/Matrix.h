#pragma once

#include <vector>
#include <string>
#include <fstream>
#include "Vec2.h"
#include "Rect.h"

class Matrix
{
public:
	Matrix() = default;
	Matrix( std::string filename );

	int Index( const int x, const int y );
	Rect GetRect();
	Rect GetCompleteRect();
public:
	std::vector<bool> matrix;
	Vec2 dim = { 0,0 };
};