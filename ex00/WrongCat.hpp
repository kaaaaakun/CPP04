#ifndef WRONG_CAT_HPP_
#define WRONG_CAT_HPP_

#include <iostream>

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
 public:
  WrongCat();
  ~WrongCat();
  WrongCat(const WrongCat &other);
  WrongCat &operator=(const WrongCat &other);

  void makeSound() const;
};

#endif
