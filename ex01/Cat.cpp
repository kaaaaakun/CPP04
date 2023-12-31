#include "Cat.hpp"

Cat::Cat() {
  std::cout << "Cat default constructor called" << std::endl;
  type_ = "Cat";
  brain_ = new Brain();
}

Cat::~Cat() {
  delete brain_;
  std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& other) {
  std::cout << "Cat copy constructor called" << std::endl;
  this->brain_ = new Brain(*other.brain_);
  this->type_ = other.type_;
}

Cat& Cat::operator=(const Cat& other) {
  if (this != &other) {
    this->type_ = other.type_;
    delete brain_;
    this->brain_ = new Brain(*other.brain_);
  }
  return *this;
}

void Cat::makeSound() const {
  std::cout << type_ << " にゃーにゃー" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea) {
  this->brain_->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
  return this->brain_->getIdea(index);
}
