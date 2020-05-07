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
      if (arr[i][j] != -1)
      {
        std::Edge newEdge = std::make_tuple(i, j);
        std::tuple<int, std::Edge> weightedEdge = std::make_tuple(arr[i][j], newEdge);
        edgesWith_Weight.push_back(weightedEdge);
      }
    }
  }

  std::sort(edgesWith_Weight.begin(), edgesWith_Weight.end());

  for (int i = 0; i < (int)edgesWith_Weight.size(); i++)
  {
    std::Edge tempEdge = std::get<1>(edgesWith_Weight[i]);
    int temp1 = tempSet.find_byValue(std::get<0>(tempEdge));
    int temp2 = tempSet.find_byValue(std::get<1>(tempEdge));
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
  tempSet.clear();
}
