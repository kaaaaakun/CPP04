#include "Dog.hpp"

Dog::Dog() {
  std::cout << "Dog default constructor called" << std::endl;
  type_ = "Dog";
}

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }

Dog::Dog(const Dog& other) {
  std::cout << "Dog copy constructor called" << std::endl;
  *this = other;
}

Dog& Dog::operator=(const Dog& other) {
  if (this != &other) {
    this->type_ = other.type_;
  }
  return *this;
}

void Dog::makeSound() const { std::cout << type_ << " わんわん" << std::endl; }
