#include "Matrix.h"

Matrix::Matrix( std::string filename )
{
	std::string buf;
	std::ifstream in( filename );
	if ( in )
	{
		std::getline( in,buf );
		std::string::size_type sz;   // alias of size_t
		dim.x = std::stoi( buf,&sz );
		std::getline( in,buf );
		dim.y = std::stoi( buf,&sz );

		for ( int i = 0; i < dim.y; i++ )
		{
			std::getline( in,buf );
			for ( int j = 0; j < buf.size(); j++ )
			{
				if ( buf[j] == '1' )
				{
					matrix.push_back( true );
				}
				if ( buf[j] == '0' )
				{
					matrix.push_back( false );
				}
			}
		}
	}
}
