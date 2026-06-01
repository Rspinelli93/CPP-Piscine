#ifndef DATABASE_HPP
# define DATABASE_HPP

#include <iostream>
#include <map>
#include <iomanip>
#include <bits/stdc++.h>
#include <cstring>
#include <string>
#include "parse.hpp"
#include <iterator>

/// @brief Two functions are defined to add the data considering both parsing scenarios.
/// @class Data base class
class DataBase
{
	private:
		std::multimap<std::string, float> _data;
	public:
		DataBase();
		~DataBase();
		DataBase( DataBase const &other );
		DataBase &operator=( DataBase const &other );

		void addDataStd( std::string str );
		void addDataUsr( std::string str );
		void getValues( DataBase *other ) const;
		class invalidFormatException : public std::exception
		{
			const char* what() const throw();
		};

		//+ Utility functions
		void printData( void );
};

#endif

/*
- Syntax.
std::map<std::string, float> db;

+ insert
db["2011-01-03"] = 0.3;
db.insert(std::make_pair("2011-01-03", 0.3));

+ access value by key
float price = db["2011-01-03"];

+ iterate
std::map<std::string, float>::iterator it = db.begin();
while (it != db.end()) {
    it->first;  // key (date)
    it->second; // value (price)
    it++;

+ find comparison
upper_bound()
}*/