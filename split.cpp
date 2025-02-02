/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */
void Helper(Node* in, Node*& oddsHead, Node*& oddsTail, Node*& evensHead, Node*& evensTail){
if (in == nullptr){
  //   if(evens != nullptr){
  //     evens->next = nullptr;
  //  }
  //   if(odds != nullptr){
  //     odds->next = nullptr;
  //   }
  //   return;
  // }
  return;
}
  Node* next = in->next;
  in->next = nullptr;

  if(in->value % 2 != 0){
    if(oddsHead == nullptr){
      oddsHead = in;
      oddsTail = in;
     
    }
    else{
      oddsTail->next=in;
      oddsTail=in;
    }
    }else{
    if(evensHead == nullptr){
      evensHead = in;
      evensTail = in;
    }
    else{
      evensTail->next = in;
      evensTail = in;
      
    }
  }


  Helper(next, oddsHead, oddsTail, evensHead, evensTail);
}
void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
  // if (in == nullptr){
  //   if(evens != nullptr){
  //     evens->next = nullptr;
  //  }
  //   if(odds != nullptr){
  //     odds->next = nullptr;
  //   }
  //   return;
  // }
  Node* oddsTail = nullptr;
  Node* evensTail = nullptr;

  odds = nullptr;
  evens= nullptr;

  // if(in->value % 2 != 0){
  //   if(odds == nullptr){
  //     odds = in;
  //    split(in->next, odds->next, evens);
  //   }
  //   else{
  //     odds->next=in;
  //     odds = odds->next;
  //     split(in->next, odds->next, evens);
  //   }
    //odds = odds->next;
  
  // else{
  //   if(evens == nullptr){
  //     evens = in;
  //     split(in->next, odds, evens);
  //   }
  //   else{
  //     evens->next = in;
  //     evens = evens->next;
  //     split(in->next, odds, evens->next);
  //   }
  //   //evens=evens->next;
    
  // }
  Helper(in, odds, oddsTail, evens, evensTail);
  //Node* nextNode = in->next;
  in = nullptr;
  
  //split(nextNode, odds, evens);
  //bout jump off bc of this logic
}