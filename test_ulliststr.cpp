#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;
//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr list;

  //commands
  list.push_back("2");
  list.push_back("6");
  list.push_back("4");
  cout <<listfront()<<" "<< list.back()<<endl;

  list.pop_front();
  cout<<list.front();
  list.pop_back();
  cout<<list.back();

  return 0;
}
