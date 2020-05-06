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
  void find(int k);
  bool checkDup(int k);
  Node* checkParent(Node* node); //done
  Node* findParent(Node* node);
  void pathCompression(Node* node);
  void print(int k);

private:
  Node** m_arr;
  int m_size;

  int recFind(Node* node); //done
  Node* getFind(int k); //done

};
#endif
