// ====================================================
//HW#: HW3P1 llist
//Your name: Parth Kapur
//Complier:  g++
//File type: llist implementation file
//=====================================================


using namespace std;


#include<iostream>
#include"llist.h"




//Purpose: Initialize Front and Rear to be NULL and Count = 0.
// This does not create any node.  The new list is empty.
llist::llist()
{
  Front = NULL;
  Rear = NULL;
  Count = 0;
}




// Purpose: DeleteFront is called until no more elements in list. Destroys all nodes.

llist::~llist()
{
  el_t delElm;


  while(!isEmpty()) // If LL is not empty
    {
      deleteFront(delElm); // DeleteFront called with delElm as parameter
    }


  cout << "\nCalling llist destructor" << endl; //Notifies that destructor is called
}

/*
Purpose: Return true if Front and Rear are both pointing
 to NULL and Count is 0, throwing error exception
 otherwise returns false
*/
bool llist::isEmpty()
{
  // Count is empty
  if(Count == 0)
    return true;  // Link list is empty
  else
    return false; // Something in link list
}

/*
Purpose: If list empty then it shows its empty,
 otherwise, it prints all elements in list
 horizontally starting from first element
*/
void llist::displayAll()
{
  if(isEmpty()) // Special case: if the list is empty, display [ empty ]
    {
      cout << "\n[ empty ]" << endl;
    }
  else
    { // Regular: displays each element of the list
      //  horizontally starting from Front in [ ].
      Node *Prt;


      Prt = Front; // Prt is pointing to first in list


      cout << "\nThe List: " << endl;


      while(Prt != NULL) // Print pointer is not last in list
        {
          cout << Prt -> Elem << " ";
          Prt = Prt -> Next; // = Prt; // Prt pointer goes to next in list
        }
    }
}
/*

Purpose: If nothing in list, call addFront for it creates one
 node otherwise the last pointers next points to a new node
  which enters the new number then sets that pointers next to NULL
Parameter:  NewNum - Element that will be entered in list
*/
void llist::addRear(el_t NewNum)
{
  // Node* newNode = new Node(); // Create new node
  //newNode -> Elem = NewNum;   // New node's element is pointing to new number




  if(isEmpty())  // Link list is empty
    {
      Rear = new Node;
      Front = Rear;
      Front -> Elem = NewNum;
      Rear -> Elem = NewNum;
      Rear -> Next = NULL;
      Count++;


    }  // Call function as it is the same operation
  else  // Regular Case: > 1 node in the list
    {
      Rear -> Next = new Node;  // Last pointer next points to new node

      Rear = Rear -> Next;
      Rear -> Elem = NewNum;
      Rear -> Next = NULL;
      Count++;                  // Increment numbers of nodes in list
    }


}

/*
Purpose: If nothing in list create node otherwise
 create a node and have it in front of list before
 entering the new number into node
Parameters: NewNum - Element that will be entered in list
*/
void llist::addFront(el_t NewNum)
{
  //Node* newNode = new Node(); // Create new node
  //newNode -> Elem = NewNum;   // New node's element is pointing to new number
  if(isEmpty()) // Nothing in link list create first node
    {

      Node *P;
      P = new Node;
      Front = P;
      Rear = P;
      Front->Elem = NewNum;
      Rear->Elem = NewNum;
      Rear->Next = NULL;
      Count++;

    }
  else

    {
      Node *x;
      x = new Node;
      x->Next = Front;
      Front = x;
      Front->Elem = NewNum;
      Count++;
    }
}

/*
Purpose: If list is empty then throw underflow,
 else if there is one node then delete that node
 otherwise set new pointer to second in list
 delete first then set front to the second
Parameter: OldNum - Number that will be deleted from list
*/
void llist::deleteFront(el_t& OldNum)
{
  if(isEmpty()) // Error Case: If list is empty nothing to delete
    throw Underflow();
  else if(Count == 1) //special case: Only one node in list
    {
      OldNum = Front -> Elem;
      delete Front;
      Front = NULL;    // Front points to NULL
      Rear = NULL;     // Rear points to NULL


      Count--;         // Node is taken out of list
    }
  else // Regular case: > 1 Node in list
    {
      OldNum = Front -> Elem; // OldNum reference to the first list's element
      Node *Second;
      Second = Front -> Next; // Points at next in the list
      delete Front;           // Deletes


      Front = Second;         // Second in list is now first in list

      Count--;         // Node is taken out of list
    }


}
//Purpose: If nothing in list throw error exception, if only one
// element in the list call delete front since its the same, other 

void llist::deleteRear(el_t& OldNum)
{
if(isEmpty()) // Error case: if empty, throw Underflow
throw Underflow();
else if(Count == 1) // Special case: If only one node
deleteFront(OldNum); // Calling function since same condition
else // Regular Case: Give back Rear's elem to OldNum then remove cell
    {
      OldNum = Rear -> Elem; // Rear's element is now in OldNum
      Node *snd2Lst; // Pointer for second to last
      snd2Lst = Front;


      while(snd2Lst -> Next -> Next != NULL) // Until second to last countinue
        snd2Lst = snd2Lst -> Next; // Goes on to next element in list


      delete Rear;          // Deleted cell
      Rear = snd2Lst;       // Rear pointing to second to last
      Rear -> Next = NULL;  // Rear next pointing to NULL

      Count--; // One less in the list
    }
}


/*Purpose: If I is not in list range it will return an error exception,
 if I is first in list then call call deletefront, if I is last in list
 call deleteRear other wise get pointer holders in between Ith node delete
 that node then reconnect the previous said nodes
Parameters: I - index number for list
OldNum - Number that will be taken out of node*/

void llist::deleteIth(int I, el_t& OldNum)
{
  if(I > Count || I < 1) // Error case: If Ith is not in list size
    throw OutOfRange();
  else if(I == 1)       // Special case: If Ith is the first in the list
    deleteFront(OldNum);
  else if(I == Count)   // Special case: If Ith is the last in the list
    deleteRear(OldNum);
  else // Regular case: deletes Ith node
    {
      Node *PreHold; // Holder pointer before deleted node
      Node *Del;     // Pointer that will delete node
      // Both are pointng to first node in list
      PreHold = Front;
      Del = Front;


      // Moves pointer to the previous node that will be deleted
      for(int pH = 1; pH < I - 1; pH++)
        PreHold = PreHold -> Next;


      // Moves pointer to node that will be deleted
      for(int del = 1; del < I; del++)
        Del = Del -> Next;


      Node *Hold; // Holder pointer for node in front of deleted pointer


      OldNum = Del -> Elem; // Takes out number from cell
      Hold = Del -> Next;   //
      delete Del; // Deleted the cell
      Del = NULL; // Points at nothing
      PreHold -> Next = Hold; // The leftover nodes get reconnected


      Count--;  // Node taken out of list
    }
}
/*
Purpose: Error case: If I is an illegal value throw OutOfRange.
-  Special cases: this should simply call addFront
    when I is 1 or addRear when I is Count + 1
-  Regular: add right before the Ith node. Cout if updated.
Parameters: I - index number for list
            newNum - Number that will be put into node
*/
void llist::addbeforeIth(int I, el_t newNum)
{
  if(I > Count + 1 || I < 1)  // Error case: If I is illegal value, throw OutOfRange
    throw OutOfRange();
  else if(I == 1)         // Special: Call addFront if I is first in list
    addFront(newNum);
  else if(I == Count + 1) // Special: Call addRear if I is last in list
    addRear(newNum);
  else
    { // Regular: add right before the Ith node. Cout if updated


      Node *before; // Pointer before inserted node
      Node *after;  // Poniter after inserted node


      // Both point to first in list
      before = Front;
      after = Front;


      // Increment to before ith position
      for(int b = 1; b <= I - 2; b++)
        before = before -> Next;


      // Increment to after ith position
      for(int a = 1; a <= I - 1; a++)
        after = after -> Next;


      Node *Ith; // Create pointer
      Ith = new Node; // Create Node
      Ith -> Elem = newNum; // Put element
      before -> Next = Ith; // Before next points to Ith
      Ith -> Next = after;  // Ith points to after


      Count++;  // One more node in the list
    }


}
