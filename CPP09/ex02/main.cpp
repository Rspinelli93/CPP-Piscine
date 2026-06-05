#include "MergeInsertion.hpp"
#include "utils.hpp"
#include <string>

int main( int ac, char **av )
{
	bool	test = false;
	if ( ac == 2 )
	{
		std::string input = av[1];
		if (!input.compare("test"))
		{
			runTest(5000);
			test = true;
		}
	}
	if (!test)
	{
		if (!parseArgs(ac, av))
			return (1);
		std::vector<int> V;
		populateContainer(V, ac, av);
		std::deque<int> D;
		populateContainer(D, ac, av);
	
		std::cout << GREEN << "Vector Merge Insertion\n---------" << BLACK << std::endl;
		printVector(V);
		timeOfExecution(VectorMergeInsertion, V);
		printVector(V);
	
		std::cout << GREEN << "\nDeque Merge Insertion\n---------" << BLACK << std::endl;
		printDeque(D);
		timeOfExecution(DequeMergeInsertion, D);
		printDeque(D);
	}

}
