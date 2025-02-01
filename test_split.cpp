/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/
#include <iostream>

#include "split.h"
using namespace std;

int main(int argc, char* argv[])
{
  // Node* body8 = new Node(200, nullptr);
  // Node* body7 = new Node(180, body8);
  // Node* body6 = new Node(171, body7);
  // Node* body5 = new Node(8, body6);

  // Node* body3 = new Node(7, body5);
   //Node* body2 = new Node(5, nullptr);
  //Node* tail= new Node(22, body2);
  Node* body = new Node(8, nullptr);
  Node* head= new Node(7, body);

  Node* odds = nullptr;
  Node* evens = nullptr;

  Node* current = head;
  while (current != nullptr){
    cout << current->value<<endl;
    current = current->next;
  }
 
  split(head, odds, evens);
  
  cout<<endl;
  while (evens != nullptr){
    cout << evens->value<<endl;
    current = evens->next;
    delete evens;
    evens = current;

  }

  cout<<endl;
  while (odds != nullptr){
    cout << odds->value<<endl;
    current = odds->next;
    delete odds;
    odds = current;
  }

}
