#include <iostream>
#include "slist.h"

using namespace std;

/* This search function will accept a key and then 
   search to find it, and return the position of it
*/
slist::slist(){
  Front = Rear = NULL;
  Count = 0;
}

slist::slist(const slist& Original)
{
  this->Front = NULL;
  this->Rear = NULL;
  this->Count = 0;

  //  Creating an iterator
  Node *P;
  P = Original.Front;
  // Loop to run until the end of the list
  while (P != NULL)
    {
      addRear(P->Elem); // Add number to the end
      // Move to the next node
      P = P->Next;
    }
}

/*
  This is to search function will accept a key and then search to find it.
 */

int slist::search(el_t Key){
  Node *p = Front; // This will create a pointer p and start at the Front of
  // the linked list.

  int pos = 1; // This will initialize the starting position to 1.

  // So, within this while loop, it is searching through the linked list
  // and continually incrementing the position (counter) and 
  // resetting p to the next node (the node in front of p). If we find
  // the element that we are looking for, then we return the position
  // number that we found the element at. 
  while (pos <= Count){
    if (p->Elem == Key){
      return pos;
    }
    pos++; // Increment Position
    p = p->Next; // Increment temp Node.
  }
  if(p==NULL) // if NULL, then the element we are searching for does not exit
    {
      return 0;
    }
}

/*
  This function will search for a number in a linked list. If the number is
  found, then it will replace that number with another. 
 */

void slist::replace(el_t Elem, int I){
  if (I > Count || I < 1){
    throw OutOfRange();
  }

  Node* temp = Front; // we are starting the temporary node at the front
  int pos = 1;        // We are initializing the position

  while(pos != I){
    temp = temp->Next; // This will set the temp Node to the next node in LL.
    pos++; // We are incrementing our counter to tell - keeps position accurate
  }
  temp->Elem = Elem; // This will replace the Elem in the position
}

// OVERLOADED OPERATORS SECTION

slist& slist::operator=(const slist& OtherOne)
{
  el_t temp;
  
  if(&OtherOne != this){ // This will make sure the addresses are not the same
      while(!this->isEmpty())
	this->deleteRear(temp);
      Node *P;
      P = OtherOne.Front;
      while(P != NULL)
	{
	  this->addRear(P->Elem);
	  P = P->Next;  // Go to the next node in OtherOne
	}
    }
  return *this;       // return the result unconditionally
}

bool slist::operator==(const slist& OtherOne)
{
  if(OtherOne.Count != this->Count){
      return false;
    }
  else{
    Node *n1 = OtherOne.Front;
    Node *n2 = this->Front;
    while(n1 != NULL || n2 != NULL){
      if(n1->Elem != n2->Elem){
	return false;
      }
      n1 = n1->Next;
      n2 = n2->Next;
    }
    return true;
  }
}
