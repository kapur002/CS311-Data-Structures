// CS311 Shortest Path Extra Credit dgaph2.h

#include <iostream>
using namespace std;

#include "slist.h"

const int MAX = 20;

// for each table entry
struct vertex
{
  char Name;
  int Out;
  int Visit; 
  slist Adj;
  int  DistTo; // new
  char From;   // new 
  char Kind;   // new
};


class dgraph
{
 private:
  vertex G[MAX];  // G is the table
  int count;      // how many slots of G are used
  
 public:
  dgraph();
  ~dgraph();
  void filltable();     // fill G reading from table.txt
  void displayTable();  
  slist findAdj(char);


  void makeTree(int);    // mark as T (Tree) the int entry 
  int findSmallest();    // find the smallest distTo F (Fringe) entry
  bool allTree();        // eveyrthing is T (tree)? 

  // *** add other utility functions below

}; 
