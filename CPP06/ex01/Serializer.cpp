#include "Serializer.hpp"

//---------------- Orthodox Cannonical ---------------

Serializer::Serializer() { std::cout << "Serializer: Constructor" << std::endl; }

Serializer::Serializer( Serializer const &other ) { (void)other; std::cout << "Serializer: Copy constructor" << std::endl; }

Serializer &Serializer::operator=( Serializer const &other ) { (void)other; return ( *this ); }

Serializer::~Serializer() { std::cout << "Serializer: Destructor" << std::endl; }

//---------------- Serialization ------------------

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t i = reinterpret_cast<uintptr_t>(ptr);
	return ( i );
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data *Ret = reinterpret_cast<Data*>(raw);
	return ( Ret );
}