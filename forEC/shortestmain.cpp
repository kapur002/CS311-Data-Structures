// CS311 Shortest Path Extra Credit

#include <iostream>
using namespace std;

#include "dgraph2.h"

int main()
{
  dgraph T;
  
  T.filltable();

  T.makeTree(0);  // 0th entry is now in Tree
  T.displayTable();
  char a;  // user input
  while (!T.allTree())   // Until all are in Tree
    { 
      T.makeTree(T.findSmallest());
      T.displayTable();
      cout << "cont?"; cin >> a;
    }
}
