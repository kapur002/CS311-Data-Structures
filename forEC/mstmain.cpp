// CS311 MST Extra Credit

#include <iostream>
using namespace std;

#include "dgraph2.h"

int main()
{
  dgraph T;
  
  T.filltable();

  T.makeTree(0);    // 0th entry is marked as Tree
  T.displayTable();
  char a;  // user input
  while (!T.allTree())   // until all are in Tree
    { 
      T.makeTree(T.findSmallest());
      T.displayTable();
      cout << "cont?"; cin >> a;
    }
}
