#include"Executive.h"
#include<string>
#include<iostream>

int main(int argc, char* argv[])
{
  if(argc == 2)
  {
    Executive exec(argv[1]);
    exec.run();
  }
  else
  {
    std::cout<<"File does not exist\n";
  }
  return 0;
}
