#pragma once

class Dimention
{
public:
	void Add( const Dimention& val )
	{
		width += val.width;
		height += val.height;
	}
	bool operator==( const Dimention& rhs ) const
	{
		return width == rhs.width && height == rhs.height;
	}
	int width;
	int height;
};