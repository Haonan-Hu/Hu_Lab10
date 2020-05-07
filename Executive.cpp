#include "Executive.h"

Executive::Executive(std::string fileName)
{
  std::ifstream infile;
  int input;
  infile.open(fileName);
  if (infile.is_open())
  {
    while (infile >> input)
    {
      m_elements.push_back(input);
    }
    infile.close();
    std::cout << "\e[1mFile reading done, ready for next step:\e[0m\n";
    std::cout << "\e[1m..................................\e[0m\n\n";
  }
  else
    std::cout << "Unable to open file\n";
}

void Executive::run()
{
  for(;;)
  {
    int choice;
    std::cout << "\nPlease choose one of the following commands:\n";
    std::cout << "  1- MakeSet\n";
    std::cout << "  2- Union\n";
    std::cout << "  3- Find\n";
    std::cout << "  4- PathCompression\n";
    std::cout << "  5- PrintPath\n";
    std::cout << "  6- Exit\n\n";
    std::cout << "Please choose an option: \n";
    std::cin >> choice;
    if (choice == 1)
    {
      m_set.makeSet(m_elements);
      std::cout << "The disjoint sets have been constructed.\n";
      std::cout << "\e[1m..................................\e[0m\n\n";
    }
    if (choice == 2)
    {
      int temp1;
      int temp2;
      std::cout << "Enter the representative elements for the two sets which you wish to union:\n";
      std::cin >> temp1;
      std::cin >> temp2;
      m_set.unionSet(temp1, temp2);
      std::cout << "\e[1m..................................\e[0m\n\n";
    }
    if (choice == 3)
    {
      int temp;
      std::cout << "Enter the element you want to search:\n";
      std::cin >> temp;
      m_set.find(temp);
      std::cout << "\e[1m..................................\e[0m\n\n";
    }
    if (choice == 4)
    {
      int temp;
      std::cout << "Enter the element on whose set you would want to perform path compression\n";
      std::cin >> temp;
      if(m_set.checkDup(temp))
      {
        m_set.pathCompression(temp);
        std::cout << "Path compression has been done successfully.\n";
      }
      else
      {
        std::cout << "ath compression unsuccessfull.\n";
      }
      std::cout << "\e[1m..................................\e[0m\n\n";
    }
    if (choice == 5)
    {
      int temp;
      std::cout << "Enter the element you want to find the path for:\n";
      std::cin >> temp;
      try
      {
        m_set.printPath(temp);
      }
      catch(std::runtime_error& rte)
      {
        std::cout<< rte.what() << '\n';
      }
      std::cout << "\e[1m..................................\e[0m\n\n";
    }
    if (choice == 6)
    {
      std::cout << "Thanks for runing!\n";
      std::cout << "\e[1m..................................\e[0m\n\n";
      break;
    }
  }
}
