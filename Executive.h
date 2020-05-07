#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "Graph.h"
#include <string>
#include <limits>
#include <fstream>

class Executive
{
public:
  Executive(std::string fileName);
  ~Executive(){};
  void runPartA();
  void runPartB();
private:
  Disjoint m_set;
  Graph m_graph;
  std::vector<int> m_elements;
  std::vector<std::string> m_islands;
  int** m_arr;
  int m_size;
};
#endif
