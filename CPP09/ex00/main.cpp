#include "DataBase.hpp"
#include "parse.hpp"
#include <iostream>
#include <string>
#include <utility>
#include <fstream> 

int main( int ac, char **av )
{
 	if (ac != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}

	DataBase	myDB;
	DataBase	inputData;
	std::string input = av[1];

	if (input.compare("test"))
	{
		//+ Open user file
		std::ifstream	userFile(av[1]);
		std::string		buff;
		if (!userFile.is_open())
		{
			std::cout << "Error: userFile not found" << std::endl;
			return (1);
		}

		//+ Populate userData
		getline (userFile, buff);
		while (getline (userFile, buff))
		{
			try
			{
				inputData.addDataUsr(buff);
			}
			catch(const std::exception& e)
			{
				std::cerr << buff << "\033[35m [Not added] \n" << "\033[31m" << e.what() << "\n" << "\033[0m\n";
			}
		}

		//+ Open given file
		std::ifstream	givenFile("../data.csv");
		if (!givenFile.is_open())
		{
			std::cout << "Error: .csv givenFile not found [store at ./CPP09]" << std::endl;
			return (1);
		}

		//+ Populate givenData
		getline (givenFile, buff);
		while (getline (givenFile, buff))
		{
			try
			{
				myDB.addDataStd(buff);
			}
			catch(const std::exception& e)
			{
				std::cerr << buff << " not added: " << e.what() << '\n';
			}
		}
		std::cout << "\033[32mExchange Rate values:\n-------------------\033[0m" << std::endl;
		myDB.getValues( &inputData );
		givenFile.close();
		userFile.close();
	}
	else
		parseTest();
	return (0);
}
