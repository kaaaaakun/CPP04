#include <iostream>
#include <sstream>
#include <string>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void coutColor(const std::string& str, const std::string& color) {
  std::cout << color << str << RESET << std::endl;
}

std::string itoa(int i) {
  std::stringstream ss;
  ss << i;
  return ss.str();
}

void subjectTest() {
  coutColor("-- subject test--------------------------", YELLOW);
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  delete j;  // should not create a leak
  delete i;
}

void arrayTest() {
  coutColor("-- AnimalArray test --------------------------", YELLOW);
  const int AnimalNum = 10;
  Animal* AnimalArray[AnimalNum];
  for (int i = 0; i < AnimalNum / 2; i++) {
    coutColor("AnimalArray[" + itoa(i) + "]: new Dog()", GREEN);
    AnimalArray[i] = new Dog();
  }
  for (int i = AnimalNum / 2; i < AnimalNum; i++) {
    coutColor("AnimalArray[" + itoa(i) + "]: new Cat()", GREEN);
    AnimalArray[i] = new Cat();
  }
  for (int i = 0; i < AnimalNum; i++) {
    AnimalArray[i]->makeSound();
  }
  for (int i = 0; i < AnimalNum; i++) {
    coutColor("AnimalArray[" + itoa(i) + "]: delete", RED);
    delete AnimalArray[i];
  }
}

void deeplyCopyTest() {
  coutColor("-- DeeplyCopy test --------------------------", YELLOW);
  Dog dog1;
  dog1.setIdea(0, "dog1 idea0");

  coutColor("dog1 idea0: " + dog1.getIdea(0), YELLOW);
  coutColor("dog1 idea1: " + dog1.getIdea(1), YELLOW);

  Dog dog2(dog1);
  coutColor("dog2 idea0: " + dog2.getIdea(0), GREEN);
  coutColor("dog2 idea1: " + dog2.getIdea(1), GREEN);

  dog2.setIdea(0, "dog2 idea0");
  coutColor("- dog2.setIdea (0, \"dog2 idea0\") -", BLUE);
  coutColor("dog1 idea0: " + dog1.getIdea(0), YELLOW);
  coutColor("dog2 idea0: " + dog2.getIdea(0), GREEN);
}

int main() {
  subjectTest();
  arrayTest();
  deeplyCopyTest();

  return 0;
}

// __attribute__((destructor)) static void destructor() {
//   system("leaks -q main");
// }
