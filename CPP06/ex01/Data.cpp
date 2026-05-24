#include "Data.hpp"

//---------------- Orthodox Cannonical ---------------

Data::Data() { std::cout << "Data: Default constructor" << std::endl; }

Data::Data( int id, std::string &name ) : _id(id), _name(name) { std::cout << "Data: Param constructor" << std::endl; }

Data::~Data() { std::cout << "Data: Destructor" << std::endl; }

Data::Data( Data const &other ) : _id(other._id), _name(other._name) { std::cout << "Data: Copy constructor" << std::endl; }

Data &Data::operator=( Data const &other )
{
	if ( this != &other )
	{
		this->_id = other._id;
		this->_name = other._name;
	}
	return ( *this );
}

//---------------- Getters && Setters ---------------

int Data::getId( void ) const { return ( this->_id ); }

std::string Data::getName( void ) const { return ( this->_name ); }

void Data::setId( int id ) { this->_id = id; }

void Data::setName( std::string name ) { this->_name = name; };