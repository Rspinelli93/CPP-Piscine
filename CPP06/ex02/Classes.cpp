#include "Classes.hpp"

Base::~Base() { std::cout << "Destructor" << std::endl; }

Base	*generate(void)
{
	static bool seeded = false;
    if (!seeded)
    {
        srand(time(NULL));
        seeded = true;
    }

	int randomNum = rand() % 3;

	switch (randomNum)
	{
		case (0):
			return (new A());
		case (1):
			return (new B());
		case (2):
			return (new C());
		default:
			return (NULL);
	}
}

void	identify(Base* p)
{
	A* pA = dynamic_cast<A*>(p);
	if (pA != NULL)
		std::cout << "A" << std::endl;
	B* pB = dynamic_cast<B*>(p);
	if (pB != NULL)
		std::cout << "B" << std::endl;
	C* pC = dynamic_cast<C*>(p);
	if (pC != NULL)
		std::cout << "C" << std::endl;
}

void    identify(Base& p)
{
    try 
	{ 
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
    catch(...) {}

    try 
	{ 
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
    catch(...) {}

    try {
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
    catch(...) {}
}