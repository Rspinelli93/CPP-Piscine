#include "MutantStack.hpp"
#include <list>
#include <vector>

int main()
{
	std::cout << "\nTest with a MutantStack:\n---------" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "Remove last: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "Size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	std::cout << "\nTest with a list:\n---------" << std::endl;
	{
		std::list<int> myList;
		myList.push_back(5);
		myList.push_back(17);
		std::cout << "Remove last: " << myList.back() << std::endl;
		myList.pop_back();
		std::cout << "Size: " << myList.size() << std::endl;
		myList.push_back(3);
		myList.push_back(5);
		myList.push_back(737);
		myList.push_back(0);
		std::list<int>::iterator it = myList.begin();
		std::list<int>::iterator ite = myList.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	std::cout << "\nTest with a vector:\n---------" << std::endl;
	{
		std::vector<int> myVector;
		myVector.push_back(5);
		myVector.push_back(17);
		std::cout << "Remove last: " << myVector.back() << std::endl;
		myVector.pop_back();
		std::cout << "Size: " << myVector.size() << std::endl;
		myVector.push_back(3);
		myVector.push_back(5);
		myVector.push_back(737);
		myVector.push_back(0);
		std::vector<int>::iterator it = myVector.begin();
		std::vector<int>::iterator ite = myVector.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	return 0;
}