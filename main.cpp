#include"Executive.h"
#include<string>
#include<iostream>

int main(int argc, char** argv)
{
  if(argc == 2 && std::string(argv[1]) == "-a")
  {
    Executive exec("input.txt");
    exec.runPartA();
  }
  else if(argc == 2 && std::string(argv[1]) == "-b")
  {
    Executive exec("data.txt");
    exec.runPartB();
  }
  else
  {
    std::cout<<"Please use -a or -b flag\n";
  }
  return 0;
}
