#include "templates.hpp"

int	main( void )
{
	std::cout << "\033[32m" << "Test swap int\n----------" << "\033[0m" << std::endl;
	{
		int	a = 5;
		int b = 10;
	
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "Swap!" << std::endl;
		::swap(a, b);
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << "\n" << std::endl;
	}
	std::cout << "\033[32m" << "Test swap char\n----------" << "\033[0m" << std::endl;
	{
		char	c1 = 'A';
		char	c2 = 'Z';
	
		std::cout << "Char 1 = " << c1 << std::endl;
		std::cout << "Char 2 = " << c2 << std::endl;
		std::cout << "Swap!" << std::endl;
		::swap(c1, c2);
		std::cout << "Char 1 = " << c1 << std::endl;
		std::cout << "Char 2 = " << c2 << "\n" << std::endl;
	}
	std::cout << "\033[32m" << "Test swap string\n----------" << "\033[0m" << std::endl;
	{
		std::string	s1 = "Hola";
		std::string	s2 = "Chau";
	
		std::cout << "String a = " << s1 << std::endl;
		std::cout << "String b = " << s2 << std::endl;
		std::cout << "Swap!" << std::endl;
		::swap(s1, s2);
		std::cout << "String a = " << s1 << std::endl;
		std::cout << "String b = " << s2 << "\n" << std::endl;
	}
	std::cout << "\033[32m" << "Test min - max\n----------" << "\033[0m" << std::endl;
	{
		std::cout << "max( 8, 7 ) --> " << ::max( 8, 7 ) << std::endl;
		std::cout << "max( 0, 8 ) --> " << ::max( 0, 8 ) << std::endl;
		std::cout << "min( 5, 8 ) --> " << ::min( 5, 8 ) << std::endl;
		std::cout << "min( -23, -78 ) --> " << ::min( -23, -78 ) << std::endl;
		std::cout << "max( 'c', 'd' ) --> " << ::max( 'c', 'd' ) << std::endl;
		std::cout << "max( 'z', 'y' ) --> " << ::max( 'z', 'y' ) << std::endl;
		std::cout << "min( 'r', 'z' ) --> " << ::min( 'r', 'z' ) << std::endl;
		std::cout << "min( hola, holissss ) --> " << ::min( "hola", "holissss" ) << "\n"<< std::endl;
	}
	std::cout << "\033[32m" << "Test subject\n----------" << "\033[0m" << std::endl;
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
		return 0;
	}
}