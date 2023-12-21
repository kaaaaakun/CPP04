#include "Cat.hpp"

Cat::Cat() {
  std::cout << "Cat default constructor called" << std::endl;
  type_ = "Cat";
}

Cat::~Cat() { std::cout << "Cat destructor called" << std::endl; }

Cat::Cat(const Cat& other) {
  std::cout << "Cat copy constructor called" << std::endl;
  *this = other;
}

Cat& Cat::operator=(const Cat& other) {
  if (this != &other) {
    this->type_ = other.type_;
  }
  return *this;
}

void Cat::makeSound() const {
  std::cout << type_ << " にゃーにゃー" << std::endl;
}
