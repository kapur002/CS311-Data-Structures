
// =======================================================
// HW#: HW1P2 stack
// Your name: Parth Kapur
// Compiler:  g++ 
// File type: headher file 
//=======================================================

#include <vector>
#include <iostream>
#include <string>

using namespace std;

//----- Globally setting up the alias ----------------

typedef int el_t;      // the el_t type is ** for now
                      // el_t is unknown to the client
//-------------------------------------------------------

class stack
{ 
  
 private: // to be hidden from the client
	 vector<el_t> el;      // el is  a vector of el_t's


  
 public:
   // the rest will be exactly the same as HW1P1. Therefore
   // the client should not have to change at all.
    
    // Note that no parameter variables are given
    
    // exception handling classes
    class Overflow{};   // thrown when the stack overflows
    class Underflow{};  // thrown when the stack underflows
    
    stack();   // constructor to create an object
    ~stack();  // destructor  to destroy an object
    
    // PURPOSE: if not full, enters an element at the top;
    //          otherwise throws an exception - Overflow
    // PARAMETER: pass the element to be pushed
    void push(el_t);
    
    // PURPOSE: if not empty, removes and gives back the top element;
    //          otherwise throws an exception - Underflow
    // PARAMETER: provide variable to receive the popped element (pass by ref)
    void pop(el_t&);
    
    // PURPOSE: if not empty, gives the top element without removing it;
    //          otherwise, throws an exception - Underflow
    
    // PARAMETER: The parameter is pass by reference, meaning that the function is passing the address of the memory location where
    // the data type is stored. This is done for two reasons, either the value is very large or to return multiple elements via
    // pass-by-reference since a function, by definition, only can return a single data type (or void).
    void topElem(el_t&);
    
    // ** Must add good comments for each function - See Notes1B
    
    //PURPOSE: The boolean function returns true if the stack is empty, else the boolean function will return a false value;
    bool isEmpty();
    //PURPOSE: The boolean function returns true is the stack is full, else the boolean function will return a false value.
    bool isFull();
    //PURPOSE: displayAll calls the function isEmpty() and if it is true, it will display empty. Otherwise, it displays the elements vertically.
    void displayAll();
    //PURPOSE: clearIt pops all elements from the stack to make it empty if it is not empty yet.
    void clearIt();
};
