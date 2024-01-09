#include "Animal.hpp"

Animal::Animal() : type_("Animal") {
  std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

Animal::Animal(const Animal& other) {
  std::cout << "Animal copy constructor called" << std::endl;
  *this = other;
}

Animal& Animal::operator=(const Animal& other) {
  if (this != &other) {
    this->type_ = other.type_;
  }
  return *this;
}

std::string Animal::getType() const { return this->type_; }

void Animal::setType(std::string type) { this->type_ = type; }
