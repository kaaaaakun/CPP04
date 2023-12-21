#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>
#include <numeric>

class WrongAnimal {
 protected:
  std::string type_;

 public:
  WrongAnimal();
  virtual ~WrongAnimal();
  WrongAnimal(const WrongAnimal &other);
  WrongAnimal &operator=(const WrongAnimal &other);

  virtual void makeSound() const;
  virtual std::string getType() const;
};

#endif