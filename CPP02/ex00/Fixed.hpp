#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

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
};


#endif