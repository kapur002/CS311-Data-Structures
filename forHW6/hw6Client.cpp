// ====   For the HW6 Client file ====================================
//INSTRUCTION: Complete this file and comment using How to Comment file.


#include <iostream>
#include "dgraph.h"
#include <ctype.h>
#include <stdio.h>
using namespace std;


int main()
{

  dgraph table;
  char vertex;
  char VertOutDeg;
  slist L1;
  string choice;


  table.fillTable();
  table.displayGraph();

  cout << "Would you like to enter a vertex degree? Type \"No\" to exit. ";
  cin >> choice;

  while (choice != "No")
    {
      try{
	cout << "Enter a vertex degree: ";
	cin >> vertex;

	VertOutDeg = table.findOutDegree(vertex);
	cout << VertOutDeg << endl;
      }
	catch(dgraph::BadVertex) {cerr << "Invalid vertex. \n"; }
	cout << "Would you like to enter a vertex degree again? Type \"No\" to exit. ";
	cin >> choice; 
}

      cout << "Would  you like to enter an adjacent value again? Type \"No\" to exit. ";
      cin >> choice;

      while (choice != "No")
	{
	  try{
	    cout << "Enter a vertex adjacency. ";
	    cin >> vertex;
	    L1 = table.findAdjacency(vertex);
	    L1.displayAll();
	    cout << endl;
	  }

	  catch(dgraph::BadVertex){cerr << "Invalid vertex. \n";}
	  cout << "Would you like to enter an adjacent value again? Type \"No\" to exit. ";
	  cin >> choice;
}

    }
