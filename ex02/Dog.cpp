#include "Dog.hpp"

Dog::Dog() {
  std::cout << "Dog default constructor called" << std::endl;
  type_ = "Dog";
  brain_ = new Brain();
}

Dog::~Dog() {
  delete brain_;
  std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& other) {
  std::cout << "Dog copy constructor called" << std::endl;
  this->brain_ = new Brain(*other.brain_);
  this->type_ = other.type_;
}

Dog& Dog::operator=(const Dog& other) {
  if (this != &other) {
    this->type_ = other.type_;
    delete brain_;
    this->brain_ = new Brain(*other.brain_);
  }
  return *this;
}

void Dog::makeSound() const { std::cout << type_ << " わんわん" << std::endl; }

void Dog::setIdea(int index, const std::string& idea) {
  this->brain_->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
  return this->brain_->getIdea(index);
}
