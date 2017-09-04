#include "Matrix.h"

Matrix::Matrix(std::string filename)
{
	std::ifstream in(filename);
	if ( in )
	{
		bool column = true;
		for ( char c = in.get(); in.good(); c = in.get() )
		{
			if ( c == '\n' )
			{
				dim.y++;
				column = false;
			}
			if ( c == '1' )
			{
				matrix.push_back(true);
			}
			if ( c == '0' )
			{
				matrix.push_back(false);
			}
			if ( column )
			{
				dim.x++;
			}
		}
		dim.y++;
	}
}

int Matrix::Index(const int x, const int y)
{
	return y*dim.x + x;
}
