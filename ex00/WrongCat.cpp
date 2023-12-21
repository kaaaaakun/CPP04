#include "WrongCat.hpp"

WrongCat::WrongCat() {
  std::cout << "WrongCat default constructor called" << std::endl;
  type_ = "WrongCat";
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) {
  std::cout << "WrongCat copy constructor called" << std::endl;
  *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
  if (this != &other) {
    this->type_ = other.type_;
  }
  return *this;
}

void WrongCat::makeSound() const {
  std::cout << type_ << " シャーシャー" << std::endl;
}
