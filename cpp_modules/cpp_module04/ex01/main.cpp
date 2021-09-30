#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	const Animal *arr[100];

	for (int i = 0; i < 100; i++)
	{
		if (i < 50)
			arr[i] = new Cat();
		else
			arr[i] = new Dog();
	}
	for (int i = 0; i < 100; i++)
		delete arr[i];
	return (0);
}