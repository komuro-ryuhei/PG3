#include <stdio.h>
#include "Dog.h"
#include "Cat.h"

int main() {

	Animal* animalDog = new Dog();
	Animal* animalCat = new Cat();

	printf("動物の鳴き声");

	printf("\nいぬ : ");
	animalDog->Voice();

	printf("\nねこ : ");
	animalCat->Voice();

	delete animalDog;
	delete animalCat;

	return 0;
}