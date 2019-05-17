//INSTRUCTION:
//Use the provided text to help create llist.cpp
//based on Yoshii  CS311  Notes-6A

//- Make sure PURPOSE and PARAMETER comments are given
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//EMACS HINT:
//  control-K cuts and control-Y pastes
//  Esc X replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Parth Kapur
//Complier:  G++
//File type: llist implementation file
//=====================================================

using namespace std;

#include<iostream>
#include "llist.h"

llist::llist() 
{
  Front = Rear = NULL;
  Count = 0;
}

llist::~llist() 
{
  cout << "Calling the llist deconstructor";
  el_t oldNum;
  while(!isEmpty()) 
    {     
      deleteFront(oldNum);
    }
}

bool llist::isEmpty() 
{
  return Front == NULL && Rear == NULL && Count == 0; 

}

void llist::displayAll() 
{
  if (isEmpty()) 
    cout << "[ empty ]" << endl;
  else {         
    Node *P = Front;       
    while (P != NULL) {    
      cout << "[" << P->Elem << "] ";
      P = P->Next;         
    }
    cout << endl;
  }
}

void llist::addFront(el_t NewNum) 
{
  if (Front == NULL) 
    {    
      Front = new Node;  
      Front->Elem = NewNum;
      Front->Next = NULL;  
      Rear = Front;       
    }
  else 
    {
      Node *x;        
      x = new Node;
      x->Next = Front;   
      Front = x;         
      Front->Elem = NewNum; 
    }
  Count++;
}

void llist::addRear(el_t NewNum) 
{
  if (Front == NULL) 
    {       
      Front = new Node;       
      Rear = Front;          
    }
  else 
    {                   
      Rear->Next = new Node; 
      Rear = Rear->Next;     
    }
  Rear->Elem = NewNum;     
  Rear->Next = NULL;       
  Count++;
}

void llist::deleteFront(el_t& OldNum) 
{
  if (isEmpty())   
    throw Underflow();
  else if (Count == 1) 
    {  
      OldNum = Front->Elem;  
      delete Front;       
      Front = NULL;       
      Rear = NULL;        
      Count--;            
    }
  else
    {      
      OldNum = Front->Elem;  
      Node *Second;      
      Second = Front->Next;      
      delete Front;  
      Front = Second;   
      Count--;
    }
}

void llist::deleteRear(el_t& OldNum) 
{
  if (isEmpty())     
    throw Underflow();
  else if (Count == 1) 
    {      
      OldNum = Rear->Elem; 
      delete Rear;         
      Front = NULL;       
      Rear = NULL;
      Count--;
    }
  else 
    {      
      OldNum = Rear->Elem;    
      Node *p = Front;        
      while (p->Next != Rear)  
	p = p->Next;        
      delete Rear;    
      Rear = p;       
      Rear->Next = NULL;  
      Count--;        
    }
}

void llist::deleteIth(int I, el_t& OldNum) 
{
  if (I > Count || I < 1)    
    throw OutOfRange();
  else if (I == 1)        
    deleteFront(OldNum);
  else if (I == Count)    
    deleteRear(OldNum);
  else 
    {      
      Node *P = Front;   
      Node *PToDelete = Front->Next;  
      for (int K = 1; K <= I-1; K++) 
	{   
	  P = P->Next;
	  PToDelete = PToDelete->Next;
	}
      P->Next = PToDelete->Next;  
      OldNum = PToDelete->Elem;  
      delete PToDelete;       
      Count--;      
    }
}

void llist::addbeforeIth(int I, el_t newNum)
{
	if (I > Count + 1 || I < 1)
		throw OutOfRange();
	else if (I == 1)
		addFront(newNum);
	else if (I == Count + 1)
		addRear(newNum);
	else {
		Node *P = Front;
		for (int K = 1; K <= I - 1; K++)
		{
			P = P->Next;
		}
		Node *temp = P->Next;
		P->Next = new Node;
		P->Next->Next = temp;
		P->Next->Elem = newNum;
		Count++;
	}
}
