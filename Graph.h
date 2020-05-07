#ifndef GRAPH_H
#define GRAPH_H

#include "Disjoint.h"
#include <algorithm>
#include <tuple>
#include <queue>

#define INF 9999999
#define Edge tuple<int, int>

class Graph
{
public:
  Graph(); //done
  ~Graph(){}; //done
  void buildGraph(int** arr, int size, std::vector<std::string> islands); //done
  void clear(); //done
  void BFS(int k); //done
  void DFS(int k); //done
  void KruskalMST();
  void PrimMST(); //done
private:
  int m_size;
  int** m_arr;

  std::vector<std::string> m_islands;
  std::vector<std::Edge> m_BFS;
  std::vector<std::Edge> m_DFS;
  std::vector<std::Edge> back_Edges;
  std::vector<std::Edge> cross_Edges;
  std::vector<std::tuple<int, std::Edge>> edgesWith_Weight;
  std::vector<std::tuple<int, std::Edge>> edgesWithM_Weight;
  std::vector<std::tuple<int, std::Edge>> Prim_edges;

  void DFS_Helper(int k, bool checked[]); //done
};
#endif
