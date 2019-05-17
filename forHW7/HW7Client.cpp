

#include "dgraph.h"
#include <ctype.h>
#include <stdio.h>
#include <iostream>
using namespace std;


int main()
{
    char bsChar;
    slist ListOne; // This will hold copy of adjacent slists.
    int count = 1; // Counter
    char inpt; // This will hold the user input
    stack Stack; // Creating a Stack Object
    dgraph table; // Creating a D Graph Object
    
    
    table.fillTable();  // this will fill the table
    table.displayGraph(); // this will display the table
    
    table.visit(count, 'A'); // we will now visit A
    ListOne = table.findAdjacency('A'); // we will now copy the adjacent list
    while( !ListOne.isEmpty())
    {
        ListOne.deleteRear(bsChar); // this will pop from adjacenct slist
        Stack.push(bsChar); //this will push into stack
    }
    
    Stack.displayAll(); //display stack
    
    while(!Stack.isEmpty())
    {
        Stack.pop(bsChar);
        cout << bsChar <<" is now removed from stack.\n";
        if (!table.isMarked(bsChar)) // in the event the vertex is not visited
        {
            count++;
            table.visit(count, bsChar);
            cout<<" Now Visiting: "<<bsChar<<endl;
            ListOne = table.findAdjacency(bsChar); // we will copy adjacent list
            while( !ListOne.isEmpty())
            {
                ListOne.deleteRear(bsChar); // pop the adjacent list
                Stack.push(bsChar); //push into the stack
            }
            
            Stack.displayAll(); //display the stack
        }//end of if
    }//end of while
    table.displayGraph(); //display the table

 
  return 0;
}

