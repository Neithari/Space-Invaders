#pragma once

#include <vector>
#include <string>
#include <fstream>
#include "Vec2.h"

class Matrix
{
public:
	Matrix() = default;
	Matrix( std::string filename );

public:
	static constexpr int buffsize = 255;
	std::vector<bool> matrix;
	Vec2 dim;
};