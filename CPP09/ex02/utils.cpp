#include "utils.hpp"

static bool is_digits(const std::string &str);

/// @brief Parser for the arguments passed when launching the program
/// @param argv Array of strings to parse
/// @return False if found an error ( messages are printed accordingly )
bool	parseArgs( int ac, char **av )
{
	if (ac == 1)
	{
		std::cout << RED <<"Error:" << BLACK << "\nUsage: PmergeMe + [int] + [int] + [int] ..." << std::endl;
		return (false);
	}
	for ( int i = 1; i < ac; i++ )
	{
		std::string temp = av[i];
		if (!is_digits(temp))
		{
			std::cout << RED <<"Error:" << BLACK << "\nFound not valid parameter" << std::endl;
			return (false);
		}
	}
	return (true);
}

static bool is_digits(const std::string &str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}

/// @brief Prints all the members (up to 10) of a vector
/// @param V The vector to print
void	printVector( std::vector<int> &V )
{
	std::vector<int>::iterator it = V.begin();
	if (V.size() > 10)
	{
		for (int i = 0; i <= 10; i++)
		{
			std::cout << *it << " ";
			it++;
		}
		std::cout << PURPLE <<" [...]" << BLACK;
	}
	else
	{
		while (it != V.end())
		{
			std::cout << *it << " ";
			it++;
		}
	}
	std::cout << "\n";
}

/// @brief Prints all the members (up to 10) of a deque
/// @param V The deque to print
void	printDeque( std::deque<int> &D )
{
	std::deque<int>::iterator it = D.begin();
	if (D.size() > 10)
	{
		for (int i = 0; i <= 10; i++)
		{
			std::cout << *it << " ";
			it++;
		}
		std::cout << PURPLE <<" [...]" << BLACK;
	}
	else
	{
		while (it != D.end())
		{
			std::cout << *it << " ";
			it++;
		}
	}
	std::cout << "\n";
}

/// @brief Runs test for n numbers
/// @param n Numbers to test
void	runTest( int n )
{
	std::vector<int> V;
	populateNContainer(V, n);
	std::deque<int> D;
	populateNContainer(D, n);

	std::cout << GREEN << "Vector Merge Insertion\n---------" << BLACK << std::endl;
	printVector(V);
	timeOfExecution(VectorMergeInsertion, V);
	printVector(V);

	std::cout << GREEN << "\nDeque Merge Insertion\n---------" << BLACK << std::endl;
	printDeque(D);
	timeOfExecution(DequeMergeInsertion, D);
	printDeque(D);
}
