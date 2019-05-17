//INSTRUCTION
//Look for ** to complete all of them
//The output should match my assingment sheet
//DO not forget to Tab on each line

//=========================================================
//HW#: HW3P2 slist
//Your name: Parth Kapur
//Complier:  g++
//File type: client program (tester)
//===========================================================

using namespace std;

#include <iostream>
#include "slist.h"

//PURPOSE of the program: This program will test the functions of Linked List
// and be able to search for and replace elements in the Linked List.
int main()
{ slist L;  // the list 
  int foundPos; // to hold the found position 
  int counter = 1; // used to display test line number
  int result;
try
  {
    //  1)add to front once (element 4)
    cout << counter << endl; counter++;
    L.addFront(4);
    //  2)add to rear 3 times (elements 6,7,8)
    cout << counter << endl; counter++;
    L.addRear(6);
    L.addRear(7);
    L.addRear(8);
    //  3)displayAll    - 4 6 7 8
    cout << counter << endl; counter++;
    L.displayAll();
    //  4)search for 6, report the result  - found in pos 2
    cout << counter << endl; counter++;
    result = L.search(6);
    cout << "Result was found in: " << result << "\n";
    //  5)replace the 6 with 0 using the search result
    cout << counter << endl; counter++;
    L.replace(0, result);
    cout << "The List is Now Updated:";
    L.displayAll();
    //  6)search for 8 and report the result . found in pos 4
    cout << counter << endl; counter++;
    result = L.search(8);
    //  7)replace the 8 with 2 using the search result
    cout << counter << endl; counter++;
    L.replace(2, result);
    //  8)displayAll                       - 4 0 7 2
    cout << counter << endl; counter++;
    cout << "The List is Now Updated:";
    L.displayAll();
    //  9)search for 5 and report the result   - not found
    cout << counter << endl; counter++;
    if (result = L.search(5) == 0){
      cout << "ERROR: 5 is not found in the list";
    }
    else{
      cout << "Element was found at position \n" << result << endl;
    }
    // 10) replace postion 7 with 10
    cout << counter << endl; counter++;
    cout << "Replace 7th position with the 10th position" << endl;
    L.replace(10,7);
    }//end of try
 catch(llist::OutOfRange)
    { cerr << "ERROR: Bad position was given" << endl;}

}//end of program
