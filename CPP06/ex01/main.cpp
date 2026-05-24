#include "Serializer.hpp"
#include "Data.hpp"

int main( void )
{
	Data *myData = new Data();
	myData->setId(42);
	myData->setName("Rick");

	std::cout << "Print myData values: Id: " << myData->getId() << " - Name: " << myData->getName() << std::endl;

	uintptr_t serial = Serializer::serialize(myData);
	std::cout << "Serialized value: " << serial << std::endl;

	Data *ptr = Serializer::deserialize(serial);
	std::cout << "Deserialized value: " << ptr << std::endl;

	std::cout << "Print ptr values: Id: " << ptr->getId() << " - Name: " << ptr->getName() << std::endl;
	delete(myData);
	return(0);
}

/*
*FOR RICKY OF THE FUTURE:

reinterpret_cast — converts any pointer to an integer type and back without
changing the underlying bits. Most dangerous cast, no type safety.
Used for low-level memory manipulation like serialization.

*The 4 C++ casts:

-static_cast — safe conversions between related types (int→float)
-dynamic_cast — safe downcast, returns nullptr if fail
-const_cast — adds/removes const
-reinterpret_cast — raw bit reinterpretation, anything goes

Only guaranteed safe: pointer→uintptr_t→same pointer type. Anything else is UB.
C++98: use #include <stdint.h> for uintptr_t, not <cstdint>.*/