#include "Graph.h"

Graph::Graph()
{
  m_arr = nullptr;
  m_size = 0;
}

void Graph::buildGraph(int** arr, int size, std::vector<std::string> m_island)
{
  m_size = size;
  m_arr = new int*[m_size];
  for(int i = 0; i < m_size; i++)
  {
    m_arr[i] = new int[m_size];
    for(int j = 0; j < m_size; j++)
    {
      m_arr[i][j] = arr[i][j];
    }
  }
  for (int i = 0; i < (int)m_island.size(); i++)
  {
    m_islands.push_back(m_island[i]);
  }
}

void Graph::BFS(int k)
{
  //initialize data structure
  m_BFS.clear();
  cross_Edges.clear();

  if (k < 0 || k >= m_size)
  {
    std::cout << "Invalid starting vertex\n";
  }
  //initialize bool array
  bool* checked = new bool[m_size];
  for (int i = 0; i < m_size; i++)
  {
    checked[i] = false;
  }

  std::queue<int> m_queue;
  m_queue.push(k);
  checked[k] = true;

  int temp;
  while (!m_queue.empty())
  {
    temp = m_queue.front();
    m_queue.pop();
    for (int i = 0; i < m_size; i++)
    {
      if (!checked[i] && m_arr[temp][i] != -1)
      {
        std::Edge edge = std::make_tuple(temp, i);
        m_BFS.push_back(edge);
        m_queue.push(i);
        checked[i] = true;
      }
      else if (i > 0 && checked[i] && m_arr[temp][i] != -1)
      {
        if (temp > i)
        {
          std::Edge edge = std::make_tuple(temp, i);
          cross_Edges.push_back(edge);
        }
      }
    }
  }
  std::cout << "Tree Edges: ";
  for (int i = 0; i < (int)m_BFS.size(); i++)
  {
    std::cout << "(" << m_islands[std::get<0>(m_BFS[i])] << ", " << m_islands[std::get<1>(m_BFS[i])] << ") ";
  }
  std::cout << "\nCross Edges: ";
  for (int i = 0; i < (int)cross_Edges.size(); i++)
  {
    std::cout << "(" << m_islands[std::get<0>(cross_Edges[i])] << ", " << m_islands[std::get<1>(cross_Edges[i])] << ") ";
  }
  delete[] checked;
}

void Graph::clear()
{
  for (int i = 0; i < m_size; i++)
  {
    delete m_arr[i];
    m_arr[i] = nullptr;
  }
  delete[] m_arr;
}

void Graph::DFS_Helper(int k, bool checked[])
{
  int temp = 0;
  checked[k] = true;
  for (temp = 0; temp < m_size; temp++)
  {
    if (!checked[temp] && m_arr[k][temp] != -1)
    {
      std::Edge edge = std::make_tuple(k, temp);
      m_DFS.push_back(edge);
      DFS_Helper(temp, checked);
    }
    else if (k > 0 && checked[temp] && m_arr[k][temp] != -1)
    {
      if (k > temp)
      {
        std::Edge edge = std::make_tuple(k, temp);
        back_Edges.push_back(edge);
      }
    }
  }
}


void Graph::DFS(int k)
{
  m_DFS.clear();
  back_Edges.clear();
  if (k < 0 || k >= m_size)
  {
    std::cout << "Invalid starting vertex\n";
  }

  bool* checked = new bool[m_size];
  for (int i = 0; i < m_size; i++)
  {
    checked[i] = false;
  }
  DFS_Helper(k, checked);

  std::cout << "Tree Edges: ";
  for (int i = 0; i < (int)m_DFS.size(); i++)
  {
    std::cout << "(" << m_islands[std::get<0>(m_DFS[i])] << ", " << m_islands[std::get<1>(m_DFS[i])] << ") ";
  }
  std::cout << "\n";
  std::cout << "Back Edges: ";
  for (int i = 0; i < (int)back_Edges.size(); i++)
  {
    std::cout << "(" << m_islands[std::get<0>(back_Edges[i])] << ", " << m_islands[std::get<1>(back_Edges[i])] << ") ";
  }

  delete[] checked;
}

void Graph::PrimMST()
{
  int numOfEdges = 0;
  Prim_edges.clear();
  int temp1;
  int temp2;
  bool* checked = new bool[m_size];
  for (int i = 0; i < m_size; i++)
  {
    checked[i] = false;
  }
  checked[0] = true;
  while (numOfEdges < m_size - 1)
  {
    int min = INF;
    temp1 = 0;
    temp2 = 0;
    for (int i = 0; i < m_size; i++)
    {
      if (checked[i])
      {
        for (int j = 0; j < m_size; j++)
        {
          if (!checked[j] && m_arr[i][j] != -1)
          {
            if (min > m_arr[i][j])
            {
              min = m_arr[i][j];
              temp1 = i;
              temp2 = j;
            }
          }
        }
      }
    }
    std::Edge newEdge = std::make_tuple(temp1, temp2);
    std::tuple<int, std::Edge> minWeightedEdge = std::make_tuple(min, newEdge);
    Prim_edges.push_back(minWeightedEdge);
    checked[temp2] = true;
    numOfEdges++;
  }

  int totalLength = 0;
  std::cout << "Edges followed by min weight: ";
  for (int i = 0; i < (int)Prim_edges.size(); i++)
  {
    std::Edge edgeInList = std::get<1>(Prim_edges[i]);
    int edgeWeightInList = std::get<0>(Prim_edges[i]);
    std::cout << "(" << m_islands[std::get<0>(edgeInList)] << ", " << m_islands[std::get<1>(edgeInList)] << "){" << edgeWeightInList << "} ";
    totalLength = totalLength + edgeWeightInList;
  }

  std::cout << "\nTotal length of the route = " << totalLength << "\n";
  std::cout << "Total estimate to construct the bridges in the route = " << totalLength << "*250K = " << totalLength * 250 << "K $\n";

  delete[] checked;
}

void Graph::KruskalMST()
{
  edgesWith_Weight.clear();
  edgesWithM_Weight.clear();
  Disjoint tempSet;

  for (int i = 0; i < m_size; i++)
  {
    tempSet.insert(i);
  }
  for (int i = 0; i < m_size; i++)
  {
    for (int j = 0; j < m_size; j++)
    {
      if (m_arr[i][j] != -1)
      {
        std::Edge newEdge = std::make_tuple(i, j);
        std::tuple<int, std::Edge> weightedEdge = std::make_tuple(m_arr[i][j], newEdge);
        edgesWith_Weight.push_back(weightedEdge);
      }
    }
  }

  std::sort(edgesWith_Weight.begin(), edgesWith_Weight.end());

  for (int i = 0; i < (int)edgesWith_Weight.size(); i++)
  {
    std::Edge tempEdge = std::get<1>(edgesWith_Weight[i]);
    int temp1 = tempSet.search(std::get<0>(tempEdge));
    int temp2 = tempSet.search(std::get<1>(tempEdge));
    if (temp1 != temp2)
    {
      edgesWithM_Weight.push_back(edgesWith_Weight[i]);
      tempSet.unionSet(temp1, temp2);
    }
  }

  int length = 0;
  std::cout << "Edges followed by min weight: ";
  for (int i = 0; i < (int)edgesWithM_Weight.size(); i++)
  {
    std::Edge tempEdge = std::get<1>(edgesWith_Weight[i]);
    int tempEdgeW = std::get<0>(edgesWithM_Weight[i]);
    std::cout << "(" << m_islands[std::get<0>(tempEdge)] << ", " << m_islands[std::get<1>(tempEdge)] << "){" << tempEdgeW << "} ";
    length = length + tempEdgeW;
  }

  std::cout << "\nTotal length of the route = " << length << "\n";
  std::cout << "Total estimate to construct the bridges in the route = " << length << "*250K = " << length * 250 << "K $\n";
  tempSet.empty();
}
