// HW#: HW3P3 
// Your Name: Parth Kapur
// Compiler: g++
// File Type: Extra credit client program


#include <iostream>
#include "slist.h"
using namespace std;

int main()
{
  slist l1;
  slist l2;
  
  int temp;// deleting elems
  int counter = 1; 
  
  cout << counter++ << " L1 is empty and L2 is empty";
  if (l1==l2)
    {
      cout << "\t\t\tTrue" << endl;
    }
  else
    {
      cout << "\t\t\tFalse" << endl;
    }

  cout << counter++ << " L1 is empty and L2 has 2 elements";
  l2.addRear(1);
  l2.addRear(2);
  if (l1 == l2)
    cout << "\t\tTrue" << endl;
  else
    cout << "\t\tFalse" << endl;
  
  //return false if l1 has two elems while l2 has none
  cout << counter++ << " L1 has 2 elements and L2 is empty";
  l2.deleteRear(temp);
  l2.deleteRear(temp);
  l1.addRear(1);
  l1.addRear(2);
  if (l1 == l2)
    cout << "\t\tTrue" << endl;
  else
    cout << "\t\tFalse" << endl;

  // this will return true if both have same amount of elems as well as same elems
  cout << counter++ << " L1 has 1, 2, 3 and L2 has 1, 2, 3";
  l2.addRear(1);
  l2.addRear(2);
  l2.addRear(3);
  l1.addRear(3);

  if (l1==l2)
    cout << "\t\tTrue" << endl;
  
  else
    cout << "\t\tFalse" << endl;
  
  // return false after removing one elem from l2
  cout << counter++ << " L1 has 1,2,3 and L2 has 1,2";
  l2.deleteRear(temp);
  if (l1 == l2)
    cout << "\t\t\tTrue" << endl;
  else
    cout << "\t\t\tFalse" << endl;
  
  // return false since l2 has 4 elements
  cout << counter++ << " L1 has 1, 2, 3 and L2 has 1, 2, 3, 4";
  l2.addRear(3);
  l2.addRear(4);
  if (l1==l2)
    cout << "\t\tTrue" << endl;
  else
    cout << "\t\tFalse" << endl;
  
  // return false if both have same amount of elements but they are different
  cout << counter++ << " L1 has 1, 2, 3 and L2 has 1, 2, 4";
  l2.deleteIth(2, temp);
  if (l1 == l2)
    cout << "\t\t\tTrue" << endl;
  else
    cout << "\t\tFalse" << endl;
}
