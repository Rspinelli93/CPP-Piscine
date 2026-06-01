#include "DataBase.hpp"

//----------------------- ORTHODOX -----------------------

DataBase::DataBase() {}

DataBase::~DataBase() {}

DataBase::DataBase( DataBase const &other ) { this->_data = other._data; }

DataBase &DataBase::operator=( DataBase const &other )
{
	if (this != &other )
		this->_data = other._data;
	return (*this);
}

//----------------------- DATA MANAGMENT -----------------------

void DataBase::addDataStd( std::string str )
{
	size_t		comma = str.find(",");
	if (comma == std::string::npos)
    	throw invalidFormatException();

	std::string date = str.substr(0, comma);
	std::string	eRateStr = str.substr(comma + 1, str.size());

	float		eRate = strtod(eRateStr.c_str(), NULL);

	if (!parse(date, eRateStr))
		throw invalidFormatException();
	
	this->_data.insert(std::make_pair(date, eRate));
}

void DataBase::addDataUsr( std::string str )
{
	size_t		dash = str.find("|");
	if (dash == std::string::npos)
		throw invalidFormatException();
	std::string date = str.substr(0, dash - 1);
	std::string	eRateStr = str.substr(dash + 2, str.size());

	float		eRate = strtod(eRateStr.c_str(), NULL);

	if (!parse(date, eRateStr) || eRate > 1000)
		throw invalidFormatException();
	
	this->_data.insert(std::make_pair(date, eRate));
}

void DataBase::getValues( DataBase *other ) const
{
	std::map<std::string, float>::const_iterator DB_it;
	std::map<std::string, float>::const_iterator U_it = other->_data.begin();

	while (U_it != other->_data.end())
	{
		DB_it = this->_data.lower_bound(U_it->first);
		if (DB_it->first.compare(U_it->first))
    		--DB_it;
		std::cout << U_it->first << " => " << U_it->second << " = " << (U_it->second * DB_it->second) << std::endl;
		U_it++;
	}
}

//----------------------- EXCEPTION -----------------------

const char* DataBase::invalidFormatException::what() const throw() { return ("Invalid format"); }

//----------------------- UTILITY -----------------------

void DataBase::printData( void )
{
	std::map<std::string, float>::iterator it = this->_data.begin();
	while (it != this->_data.end())
	{
		std::cout << it->first << " - " << it->second << std::endl;
		it++;
	}
}