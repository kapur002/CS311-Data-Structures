//INSTRUCTION
//Look for **. (do control-S)
//Update the comments using the HOW TO COMMENT file,
//  complete exception handling and
//  finish ClearIt to make this complete - Yoshii (CS311)
// When done, compile stack.cpp to make sure there are no syntax errors.

//=========================================================
//HW#: HW1P1 stack
//Your name: Parth Kapur
//Complier:  g++
//File type: stack implementation file
//=========================================================

using namespace std;
#include <iostream>
#include "stack.h"

//PURPOSE:  Constructor must initialize top to be -1 to begin with.
stack::stack()
{ top = -1; // indicate an empty stack }
}

//PURPOSE:  Destructor does not have to do anything since this is a static array.
stack::~stack()
{} // nothing to do

//PURPOSE:  checks top and returns true if empty, false otherwise.
// If top is equal to -1, the stack is empty.
bool stack::isEmpty()
{ if (top == -1) // if top is -1, it means the stack is empty.
    return true;
  else
    return false; }

//PURPOSE: checks top and returns true if full, false otherwise.
// If the top of the stack equals max-1, the stack is full.
bool stack::isFull()
{ if (top == MAX-1 )// if top is set to max size, then it is full
    return true;
  else
    return false; }

//PURPOSE: calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el after incrementing top.
//PARAMETER: pass the element (elem) to be pushed
void stack::push(el_t elem)
{ if (isFull()) // if stack is full, then throws an overflow exception

    throw Overflow();
  else // otherwise top gets incremented, and the element is added to the top.

    top++;
  el[top] = elem;
}

//PURPOSE: calls isEmpty and if true, throws an exception (Underflow)
//  Otherwise, removes an element from el and gives it back.
//PARAMETER: provide a holder (elem) for the element popped (pass by ref)
void stack::pop(el_t& elem)
{ if (isEmpty())

    throw Underflow();
  else
    elem = el[top];
  top--;
}
// PURPOSE: calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
//PARAMETER: provide a holder (elem) for the element (pass by ref)
void stack::topElem(el_t& elem)
{
  if (isEmpty()) //if the stack is empty, then throws an underflow exception

    throw Underflow();

  else // otherwise the top element gets set to the element.
    elem = el[top];
}

//PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
//          Otherwise, diplays the elements vertically.
void stack::displayAll()
{
  if (isEmpty()) //display empty stack
    {
      cout << "[ empty ]" << endl;
    }
  else for (int i = top; i>=0; i--) // otherwise, if not empty
    {
      cout << el[i] << endl; // display the elements of the array
    }
  cout << "--------------" << endl;
}
//PURPOSE: pops all elements from the stack to make it empty if it is not empty yet.
void stack::clearIt()
{

  el_t elem; //local variable , will be used to pop element.
  if (!isEmpty()) // if some elements are still in the stack, then pop it
    pop(elem);

  else // otherwise throws an underflow, stating the stack is empty.

    throw Underflow();


  //If stack is not empty, then pop all elements in it to make it empty.



}
