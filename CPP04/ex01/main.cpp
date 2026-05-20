#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main()
{
	{
		const Animal *array[6];

		std::cout << "\nCREATING DOGS:\n---------------\n" << std::endl;
		for (int i = 0; i < 3; i++)
			array[i] = new Dog();

		std::cout << "\nCREATING CATS:\n---------------\n" << std::endl;
		for (int i = 3; i < 6; i++)
			array[i] = new Cat();
		
		std::cout << "\nDESTRUCTORS:\n---------------\n" << std::endl;
		for (int i = 0; i < 6; i++)
			delete(array[i]);
	}
	{
		std::cout << "\nCREATING Originals:\n---------------\n" << std::endl;
		Dog *Doggy = new Dog();
		Cat *Julio = new Cat();

		Doggy->getBrain()->setIdea("I hate cats", 0);
		Julio->getBrain()->setIdea("I hate dogs", 0);

		std::cout << "\nCREATING Copies:\n---------------\n" << std::endl;
		Dog *CopyDog(Doggy);
		Cat *CopyCat(Julio);

		CopyDog->getBrain()->setIdea("I love treats", 0);
		CopyCat->getBrain()->setIdea("I love scratching the couch", 0);

		std::cout << "\nPRINTING IDEAS:\n---------------\n" << std::endl;
		std::cout << "Doggy: " << Doggy->getBrain()->getIdea(0) << std::endl;
		std::cout << "Julio: " << Julio->getBrain()->getIdea(0) << std::endl;
		std::cout << "CopyDog: " << CopyDog->getBrain()->getIdea(0) << std::endl;
		std::cout << "CopyCat: " << CopyCat->getBrain()->getIdea(0) << std::endl;

		std::cout << "\nDESTRUCTORS:\n---------------\n" << std::endl;
	}
}
