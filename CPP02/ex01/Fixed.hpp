#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int				_fixed;
		static const int bits = 8;
	public:
		Fixed( void );
		Fixed( const Fixed &num );
		~Fixed( void );
		Fixed &operator=(const Fixed &num);
		int getRawBits( void ) const;
		void setRawBits( int const raw );

		Fixed( const int num );
		Fixed( const float num );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &num);

#endif