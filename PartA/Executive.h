#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "Disjoint.h"
#include <string>

class Executive
{
public:
  Executive(std::string fileName);
  ~Executive(){};
  void run();
private:
  Disjoint m_set;
};
#endif
