#ifndef DISJOINT_H
#define DISJOINT_H

#include "Node.h"
#include <iostream>
#include <vector>

class Disjoint
{
public:
  Disjoint(); //done
  ~Disjoint(); //done
  void makeSet(std::vector<int> elements); //done
  void unionSet(int X, int Y); //done
  void find(int k); //done
  bool checkDup(int k); //done
  Node* checkParent(Node* node); //done
  Node* findParent(Node* node); //done
  void pathCompression(int k); //done
  void printPath(int k);

private:
  Node** m_arr;
  int m_size;

  int recFind(Node* node); //done
  Node* getFind(int k); //done

};
#endif
