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

		bool operator>( const Fixed &num ) const;
		bool operator<( const Fixed &num ) const;
		bool operator>=( const Fixed &num ) const;
		bool operator<=( const Fixed &num ) const;
		bool operator==( const Fixed &num ) const;
		bool operator!=( const Fixed &num ) const;
		Fixed operator+( const Fixed &num ) const;
		Fixed operator-( const Fixed &num ) const;
		Fixed operator*( const Fixed &num ) const;
		Fixed operator/( const Fixed &num ) const;
		Fixed &operator++( void );
		Fixed operator++( int );
		Fixed &operator--( void );
		Fixed operator--( int );
		static const Fixed &min( const Fixed &a, const Fixed &b );
		static Fixed &min( Fixed &a, Fixed &b );
		static const Fixed &max( const Fixed &a, const Fixed &b );
		static Fixed &max( Fixed &a, Fixed &b );
};

std::ostream &operator<<(std::ostream &out, const Fixed &num);


#endif