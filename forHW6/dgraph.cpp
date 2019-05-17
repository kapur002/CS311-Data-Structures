// ====   For the dgraph.cpp file ====================================
// INSTRUCTION:
// Complete all the functions you listed in dgraph.h
// Comment the file completely using How to Comment file.
//=====================================

#include <iostream>
#include <fstream>
#include "dgraph.h"
#include <stdio.h>
#include <ctype.h>
#include <iomanip>
using namespace std; 

dgraph::dgraph()
{
  countUsed = 0;
  Gtable[countUsed].vertexName = '\0';
  Gtable[countUsed].visit = 0;
}    // initialize vertexName (blank) and visit numbers (0)
// initialize countUsed to be 0

dgraph::~dgraph()
{

}   // do we have to delete all nodes of slists in table??
// Question: If we do not do this, will the llist destructor
// be called automatically??? Try it.

// read from the input file table.txt and fill GTable
void dgraph::fillTable()
{

  ifstream fin ("table.txt", ios::in);
  char x;
  while ( fin >>  Gtable[countUsed].vertexName )
    {
      fin >>  Gtable[countUsed].outDegree;
      for (int i = 0; i <  Gtable[countUsed].outDegree; i++)
	{
	fin >> x;
      (Gtable[countUsed].adjacentOnes).addRear(x);
    }
  countUsed++;
}

fin.close();
}

// displays in an easy to read format
 void dgraph::displayGraph()
{
  cout << left << setw(15) << "Vertex" << left << setw(15) << "OutDegree" << left << setw(15)  << "Adjacent" << endl;
  for (int i = 0; i < countUsed; i++)
    {
      cout << left << setw(15);
      cout << Gtable[i].vertexName << left << setw(15) << endl;
      cout << Gtable[i].outDegree << setw(15);
      (Gtable[i].adjacentOnes).displayAll();
      cout << endl;
}

}

// returns the out degree of a given vertex - may throw BadVertex
int dgraph::findOutDegree(char vertex)
{
  for (int i = 0; i < countUsed; i++)
    {
      if(Gtable[i].vertexName == toupper(vertex))
	{
	  cout << Gtable[i].outDegree << endl;
	  return Gtable[i].outDegree;
	}
}
  throw BadVertex();
}

// returns the adjacency list of a given vertex - may throw BadVertexx
slist dgraph::findAdjacency(char vertex)
{
  for(int i = 0; i < countUsed; i++)
    {

      if(Gtable[i].vertexName == toupper(vertex))
	{
	  return Gtable[i].adjacentOnes;
	}
    }
  throw BadVertex();
}
