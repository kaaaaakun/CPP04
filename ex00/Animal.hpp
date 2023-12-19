#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <numeric>

class Animal {
 protected:
  std::string type_;

 public:
  Animal();
  ~Animal();
  Animal(const Animal &other);
  Animal &operator=(const Animal &other);

  virtual void speak() const = 0;
};

class Dog : public Animal {
 public:
  Dog();
  ~Dog();
  Dog(const Dog &other);
  Dog &operator=(const Dog &other);
};

class Cat : public Animal {
 public:
  Cat();
  ~Cat();
  Cat(const Cat &other);
  Cat &operator=(const Cat &other);
};

#endif
