#ifndef NODE_H
#define NODE_H

class Node
{
public:
  Node(){
    m_entry = -1;
    m_rank = 0;
    m_parent = nullptr;
  };
  ~Node(){};

  int getEntry()const{
    return m_entry;
  }
  void setEntry(int entry){
    m_entry = entry;
  }

  int getRank()const{
    return m_rank;
  }
  void setRank(int rank){
    m_rank = rank;
  }

  Node* getParent()const{
    return m_parent;
  }
  void setParent(Node* parent){
    m_parent = parent;
  }

private:
  int m_entry;
  int m_rank;
  Node* m_parent;
};
#endif
