#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "Graph.h"
#include <string>
#include <fstream>

class Executive
{
public:
  Executive(std::string fileName);
  ~Executive(){};
  void run();
private:
  Disjoint m_set;
  std::vector<int> m_elements;
};
#endif
