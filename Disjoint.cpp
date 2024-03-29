#include "Disjoint.h"

Disjoint::Disjoint()
{
  m_arr = new Node*[1000];
  m_size = 0;
}

Disjoint::~Disjoint()
{
  for(int i = 0; i < m_size; i++)
  {
    delete m_arr[i];
    m_arr[i] = nullptr;
  }
  delete[] m_arr;
}

void Disjoint::makeSet(std::vector<int> elements)
{
  for (int i = 0; i < (int)elements.size(); i++)
  {
    m_arr[i] = new Node();
    m_arr[i]->setEntry(elements[i]);
    m_size++;
  }
}

Node* Disjoint::getFind(int k)
{
  Node* temp = nullptr;
  for(int i = 0; i < m_size; i++)
  {
    if (m_arr[i]->getEntry() == k)
    {
      temp = m_arr[i];
      break;
    }
  }
  return temp;
}

int Disjoint::recFind(Node* node)
{
  if (node->getParent() == nullptr)
  {
    return node->getEntry();
  }
  else
  {
    return recFind(node->getParent());
  }
}

Node* Disjoint::checkParent(Node* node)
{
  if (node != nullptr)
  {
    if (node->getParent() == nullptr)
    {
      return node;
    }
    else
    {
      return checkParent(node->getParent());
    }
  }
  else
  {
    return nullptr;
  }
}

Node* Disjoint::findParent(Node* node)
{
  if (node->getParent() == nullptr)
  {
    return node;
  }
  else
  {
    return findParent(node->getParent());
  }
}

void Disjoint::printPath(int k)
{
  Node* path = nullptr;
  if (k > 0 && k <= m_size)
  {
    for (int i = 0; i < k; i++)
    {
      path = m_arr[i];
    }
  }
  else
  {
    throw(std::runtime_error("Wrong index\n"));
  }
  std::cout << "The path for the element " << k << " is : ";
  std::cout << path->getEntry();
  while(path->getEntry() != recFind(path))
  {
    path = path->getParent();
    std::cout << " -> " << path->getEntry();
  }
  std::cout << '\n';
}

void Disjoint::unionSet(int X, int Y)
{
  bool temp1 = false; //check for whether can union or not
  bool temp2 = false; //use as a flag
  Node* n1 = checkParent(getFind(X));
  Node* n2 = checkParent(getFind(Y));

  if (n1 != nullptr && n2 != nullptr)
  {
    temp1 = true;
    if (n1->getRank() <= n2->getRank())
    {
      n1->setParent(n2);
      temp2 = true;
      if (n1->getRank() == n2->getRank())
      {
        n2->setRank(n2->getRank() + 1);
      }
    }
    else
    {
      n2->setParent(n1);
    }
  }
  if(temp1)
  {
    std::cout << X << " and " << Y << " have been merged. The representative element is ";
    if (temp2)
    {
      std::cout << recFind(n1) << '\n';
    }
    else
    {
      std::cout << recFind(n2) << '\n';
    }
  }
  else
  {
    std::cout << "unable to merge due to unfound entry in the set\n";
  }
}

bool Disjoint::checkDup(int k)
{
  bool temp = false;
  for (int i = 0; i < m_size; i++)
  {
    if (m_arr[i]->getEntry() == k)
    {
      temp = true;
      break;
    }
  }
  return temp;
}

void Disjoint::find(int k)
{
  Node* temp = getFind(k);
  if (temp != nullptr)
  {
    std::cout << k << " has been found successfully. Its representative element is " << recFind(temp) << " .\n";
  }
  else
  {
    std::cout << k << " is not found!\n";
  }
}

void Disjoint::pathCompression(int k)
{
  Node* temp = getFind(k);
  if (temp != nullptr)
  {
    if (recFind(temp) != k)
    {
      Node* temp1 = findParent(temp);
      Node* temp2 = temp->getParent();
      temp->setParent(temp1);
      pathCompression(temp2->getEntry());
    }
  }
}

void Disjoint::insert(int k)
{
  m_arr[m_size]=new Node();
  m_arr[m_size]->setEntry(k);
  m_size++;
}

int Disjoint::search(int k)
{
  Node* temp = nullptr;
  for(int i = 0; i < m_size; i++)
  {
    if(m_arr[i]->getEntry() == k)
    {
      temp = m_arr[i];
      break;
    }
  }
  if(temp != nullptr)
  {
    while(temp->getParent() != nullptr)
    {
      temp = temp->getParent();
    }
  }
  else
  {
    return -1; // report error
  }
  return temp->getEntry();
}

void Disjoint::empty()
{
  for (int i = 0; i < m_size; i++)
  {
    delete m_arr[i];
  }
  delete[] m_arr;
  m_arr = nullptr;
  m_size = 0;
}
