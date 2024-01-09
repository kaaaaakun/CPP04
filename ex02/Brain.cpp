#include "Brain.hpp"
#include "Animal.hpp"

Brain::Brain() { std::cout << "Brain default constructor called" << std::endl; }

Brain::~Brain() { std::cout << "Brain destructor called" << std::endl; }

Brain::Brain(const Brain& other) {
  std::cout << "Brain copy constructor called" << std::endl;
  *this = other;
}

Brain& Brain::operator=(const Brain& other) {
  if (this != &other) {
    for (int i = 0; i < MAX_IDEAS; i++) {
      this->ideas_[i] = other.ideas_[i];
    }
  }
  return *this;
  (void)other;
}

void Brain::setIdea(int index, std::string idea) {
  if (index < 0 || MAX_IDEAS <= index) {
    std::cout << RED << "Index out of bounds" << RESET << std::endl;
    return;
  }
  ideas_[index] = idea;
}

std::string Brain::getIdea(int index) {
  if (index < 0 || MAX_IDEAS <= index) {
    return (std::string(RED) + "Out of index" + std::string(RESET));
  }
  return ideas_[index];
}
