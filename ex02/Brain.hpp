#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#define MAX_IDEAS 100
class Brain {
 protected:
  std::string ideas_[MAX_IDEAS];

 public:
  Brain();
  ~Brain();
  Brain(const Brain &other);
  Brain &operator=(const Brain &other);

  void setIdea(int index, std::string idea);
  std::string getIdea(int index);
};

#endif
