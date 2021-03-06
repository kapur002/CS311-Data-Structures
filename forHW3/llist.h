//INSTRUCTION:
//Llist class - header file template (by Yoshii) based on Notes-6A
//You must complete the ** parts and then complete llist.cpp
// Don't forget PURPOSE and PARAMETERS 
// =======================================================
// HW#: HW3P1 llist
// Your name: Parth Kapur
// Compiler:  g++ 
// File type: headher file 
//=======================================================

//----- Globally setting up the alias and struct  ----------------
typedef int el_t;  

//a list node is defined here as a struct Node
// I could have done class Node and add the data members under public
// but it would use too much space
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 protected:

  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes

  // PURPOSE:     Check if the list is empty by checking if both front and rear are NULL and that Count = 0.
  bool isEmpty();

  // PURPOSE:     Display all the elements in all the nodes.
  void displayAll();

  // PURPOSE:     add a new node with the element to the front of the list.
  // PARAMETERS:  The new element that we want to add to the front of the list.
  void addFront(el_t);

  // PURPOSE:     add an element to the rear of the list
  // PARAMETERS:  the element that we will add to the rear of the list
  void addRear(el_t);

  // PURPOSE:     delete the front node and elem
  // PARAMETERS:  The variable we will be passing the old elem to that will be deleted.
  void deleteFront(el_t&);

  // PURPOSE:     delete the rear elem and pass the elem back
  // PARAMETERS:  the variable that will receive the old elem
  void deleteRear(el_t&);

  // PURPOSE:     delete the designated elem/node.
  // PARAMETERS:  The node you wish deleted and the variable to receive the old elem.
  void deleteIth(int, el_t&);

  // PURPOSE:     To add an element before the designated element
  // PARAMETERS:  The designated elem and the variable we send the old number to
  void addbeforeIth(int, el_t);   
};
