#include "Animal.hpp"

Animal::Animal() : type_(NULL) {
  std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal() {
  std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
  std::cout << "Animal copy constructor called" << std::endl;
  *this = other;
}

Animal &Animal::operator=(const Animal& other) {
  std::cout << "Animal assignment operator called" << std::endl;
  if (this != &other) {
	this->type_ = other.type_;
  }
  return *this;
}
