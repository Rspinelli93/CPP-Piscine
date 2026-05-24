#include "Classes.hpp"

/*
dynamic_cast is a cast operator that converts data from one type
to another type at runtime. It is mainly used in inherited class
hierarchies for safely casting the base class pointer or reference
to derived class (called downcasting). To work with dynamic_cast,
there must be one virtual function in the base class.

https://www.geeksforgeeks.org/cpp/dynamic-_cast-in-cpp/ 

dynamic_cast <new_type>(expression)

If the object being pointed to is of the correct type (or a type convertible to it),
the cast succeeds. If the cast is invalid, the pointer is set to nullptr or it is
a reference, then it throws std::bad_cast exception.*/

int main( void )
{
	Base *ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete(ptr);
}