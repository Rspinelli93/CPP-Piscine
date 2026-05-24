#ifndef CLASSES_HPP
# define CLASSES_HPP

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <ctime>

class Base
{
	public:
		virtual ~Base();
};

class A : public Base { };

class B : public Base { };

class C : public Base { };

/// @brief It randomly instantiates A, B, or C.
/// @return Returns the instance as a Base pointer.
Base	*generate(void);

/// @brief It prints the actual type of the object pointed to by p: "A", "B", or "C".
/// @param p The pointer to the Base class.
void	identify(Base* p);

/// @brief It prints the actual type of the object referenced by p: "A", "B", or "C".
/// @param p The pointer to the Base class.
/// @exception Using a pointer inside this function is forbidden.
void	identify(Base& p);

#endif