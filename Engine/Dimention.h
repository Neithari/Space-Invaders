#pragma once

class Dimention
{
public:
	Dimention() = default;
	
	bool operator==( const Dimention& rhs ) const;
public:
	int width;
	int height;
};