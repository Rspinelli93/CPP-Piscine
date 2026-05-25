#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Wrong.hpp"

int	main()
{
	{
		std::cout << "\nUSING VIRTUAL DECLARATION:\n---------------\n" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << "\n";
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		std::cout << "\n";
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		
		std::cout << "\n";
		delete(meta);
		delete(j);
		delete(i);
	}
	{
		std::cout << "\n\nWRONG ANIMAL TEST:\n---------------\n" << std::endl;
		WrongAnimal* meta = new WrongAnimal();
		WrongAnimal* i = new WrongCat();

		std::cout << "\n";
		std::cout << i->getType() << " " << std::endl;

		std::cout << "\n";
		i->makeSound(); //will not output the cat sound!
		meta->makeSound();

		std::cout << "\n";
		delete(meta);
		delete(i);
	}
	return (0);
}
