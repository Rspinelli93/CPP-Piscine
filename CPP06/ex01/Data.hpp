#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

class Data
{
	private:
		int			_id;
		std::string _name;
	public:
		Data();
		~Data();
		Data( int id, std::string &name );
		Data( Data const &other );
		Data &operator=( Data const &other );

		int getId( void ) const;
		std::string getName( void ) const;
		void setId( int id );
		void setName( std::string name );
};

#endif