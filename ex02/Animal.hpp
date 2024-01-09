#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

class Animal {
 protected:
  std::string type_;

 public:
  Animal();
  virtual ~Animal();
  Animal(const Animal &other);
  Animal &operator=(const Animal &other);

  virtual void makeSound() const = 0;
  virtual std::string getType() const;
  virtual void setType(std::string type);
};

#endif
