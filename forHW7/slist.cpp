// ====================================================
//HW#: HW3P2 slist
//Your name: Parth Kapur
//Complier:  g++
//File type: Implementation file
//=====================================================



#include <iostream>
#include "slist.h"
using namespace std;

//Purpose: Initialize Front and Rear to be NULL and Count = 0.
// This does not create any node.  The new list is empty.
slist::slist()
{
  Front = NULL;
  Rear = NULL;
  Count = 0;
}




/*
Purpose: search through the list to see if any node contains the key.
 If so, return its position (>=1). Otherwise, return 0.
Parameter: key - sees if position is ready to replace
*/
int slist::search(el_t Key)
{
  if(isEmpty()) // Error Caae: List does not exist
    throw Underflow();
  else // Something is in the list
    {
      Node *Ptr; //  pointer
      int pos = 1;


      Ptr = Front; // Irdtr is pointing to where front is


      while(Ptr -> Next != NULL) // While not end of list
        {
          if(Ptr -> Elem == Key) // If Elem in list matches key
            return pos;             // Return position number
          else
            Ptr = Ptr -> Next; // Next in list
	  pos++;                 // Increment position
        }


      pos = 0;    // Position re-int to 0 since not found
      return pos; // Returns 0 as position
    }


}

/*
Purpose: Replaces a node element with another
Parameter: Elem - new number input into list
           I - position # elem will be replaced
*/
void slist::replace(el_t Elem,  int I)
{
  if(I < 1 || I > Count) // Error Case: Not in range of list
    throw OutOfRange();
  else
    {
      Node* Ptr = Front; // Iterador pointer
      el_t OldElem;  // Old element will be placed here
      int pos = 1; // Position iredator


      // Increment pointer and count until it reaches replace node
      while(pos != I)
        {
          pos++;          // Counter updated
          Ptr = Ptr -> Next; // Next in list
        }


      deleteIth(I, OldElem); // delete Elem from list
      addbeforeIth(I, Elem); // Input new Elem in list
    }


}
/*
Purpose: Copy Constructor which gets Originals pointer and
 builds an identical list based on the original
Parameter: Original - Object of original list
*/
slist::slist(const slist& Original)
{
  Node* P; // Created Pointer
  P = Original.Front; // Orignal's front is now P


  while(P != NULL)    // While P hasn't reached NULL
    {
      this -> addRear(P -> Elem); // add an Element to the rear of list
      P = P -> Next; // Go to the next list
    }
}
/*

Purpose: Should check to see if list copying into exists
 so it clears, then builds another list copying from
 OtherOne list
Parameter: OtherOne - Original list
*/
slist& slist::operator=(const slist& OtherOne)
{
  el_t Del; // Called Elem that may be deleted if this has elements


  //First make sure this-> and OtherOne are not same object
  // Do this by comparing pointers "address" to objects
  if(&OtherOne != this)
    {
      // this-> object has to be emptied
      while(!this -> isEmpty())
        this -> deleteRear(Del);


      // this -> object has to be bulit up by allocating new cells
      Node* P; // local pointer for OtherOne
      P = OtherOne.Front;


      while(P != NULL)
        {
          this -> addRear(P -> Elem); // P eleement is added to this ->
          P = P -> Next;              // Go to next node in OtherOne
        }
    } // end of if


  return *this; // return result unconditionally (address)
}
