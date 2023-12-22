#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void coutColor(const std::string& str, const std::string& color) {
  std::cout << color << str << RESET << std::endl;
}

int main() {
  {
    coutColor("--subject TST--------------------------", YELLOW);

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();  // will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;
  }
  {
    coutColor("--TEST 1--------------------------", YELLOW);
    const Animal* animals[] = {new Animal(), new Dog(), new Cat()};
    for (int i = 0; i < 3; ++i) {
      coutColor("Type: " + animals[i]->getType(), GREEN);
      animals[i]->makeSound();
      delete animals[i];
    }
  }
  {
    coutColor("--TEST 2--------------------------", YELLOW);
    const WrongAnimal* animals[] = {new WrongAnimal(), new WrongCat()};
    for (int i = 0; i < 2; ++i) {
      coutColor("Type: " + animals[i]->getType(), GREEN);
      animals[i]->makeSound();
      delete animals[i];
    }
    coutColor("--TEST 3--------------------------", YELLOW);
    WrongCat* cat = new WrongCat;
    coutColor("Type: " + cat->getType(), GREEN);
    cat->makeSound();
    delete cat;
  }

  coutColor("\n-- canonical form test ------------------------", YELLOW);
  {
    coutColor("--ANIMAL--------------------------", GREEN);
    Animal animal1;
    Animal animal2(animal1);
    animal1 = animal2;
  }
  {
    coutColor("--DOG--------------------------", GREEN);
    Dog dog1;
    Dog dog2(dog1);
    dog1 = dog2;
  }
  {
    coutColor("--CAT--------------------------", GREEN);
    Cat cat1;
    Cat cat2(cat1);
    cat1 = cat2;
  }
  {
    coutColor("--WRONG ANIMAL--------------------------", RED);
    WrongAnimal wrong_animal1;
    WrongAnimal wrong_animal2(wrong_animal1);
    wrong_animal1 = wrong_animal2;
  }
  {
    coutColor("--WRONG CAT--------------------------", RED);
    WrongCat wrong_cat1;
    WrongCat wrong_cat2(wrong_cat1);
    wrong_cat1 = wrong_cat2;
  }
  return 0;
}
