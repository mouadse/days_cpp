#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <exception>
#include <iostream>
#include <string>

class Brain
{
  protected:
    std::string ideas[100];

  public:
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain();

    std::string getIdea(int index) const;
    void setIdea(const std::string& idea, int index);

    void printIdeas() const;
};

#endif
