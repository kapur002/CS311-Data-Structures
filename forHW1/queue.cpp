//INSTRUCTION
//Look for **
//Fill in the function body
//When done, compile queue.cpp to make sure it has no syntax errors

//=========================================================
//HW#: HW1P1 queue
//Your name: Parth Kapur
//Complier:  g++
//File type: queue.cpp
//===========================================================

using namespace std;
#include <iostream>
#include "queue.h"  

// constructor 
queue::queue()
{
    // Since we are initializing the queue, the front of the queue should be 0.
    front = 0;
    // Likewise, since we are initializing the queue, the count of the queue should be 0 since there are
    // no elements in it.
    count = 0;
    // The rear should be -1, as it should always be behind the initial starting position, which in this case is
    // 0, since we are initializing the queue.
    rear = -1;
}

//destructor 
queue::~queue()
{
    // Nothing to do - memory will automatically be deallocated.
}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
    if (front == 0 && rear == -1) // Rear should only be -1 if the array is empty. Front can be 0 but still have something in it, therefore we have 
		// a biconditional check
    {
        return true;
    }
    else
    {
        return false;
    }
}

// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull()
{
	// Self explanatory - if the count of the array exceeds MAX_SIZE, the array is full.
    if (count == (MAX_SIZE-1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t newElem)
{
    if (isFull()) // If it is full, we want to throw an exception called overFlow
        {
            throw overFlow();
        }
    
    else
    {
        rear = (rear + 1) % MAX_SIZE; // Why this formula? Well, we want the rear to increase.
        
        /* However, in the event that the queue becomes full, the rear should be reset.
         Thus, the queue, in a way is circular (where the front and the tail meet).
         So, for example, if the MAX_SIZE is 9...and the previous rear value was 8
         Plugging into the formula: (8 + 1) % MAX_SIZE would get us 0. */
        el[rear] = newElem;
        count++;
    }
    
}

// PURPOSE: if empty, throw Underflow
// if not empty, removes the front element to give it back 
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue::remove(el_t& removedElem)
{
    
    // If the queue is empty, we will throw underFlow. After all, we do not want to attempt deleting from an empty queue.
    if (isEmpty())
    {
        throw underFlow();
    }
    
    else
    {
        // removedElem will serve as a holder for the element removed.
        removedElem = el[front];
        // We want to clear the original position by representing it with empty quotes, else the already deleted character will hang around in the buffer
        el[front] = " ";
        // Why this algorithm, you ask?
        /*
         It is the same concept as moving the rear in the add function. We want to move the front up, thereby
         "erasing" the content of what is currently the front of the line. We include % MAX_SIZE because
         a queue based array is circular (the end will meet the beginning), so front will only be 0 when front + 1 == MAX_SIZE.
         */
        front = ((front + 1) % MAX_SIZE);
        count--;
    }
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& theElem)
{
    if (isEmpty())
    {
        throw underFlow();
    }
    else
    {
        // Notice that since the function is void, we cannot return a data type. Therefore, we can return data
        // by using a pass-by-reference. Remember, that pass-by-reference can return data because whatever is changed
        // on the pass-by-reference, will also reflect in the variable that is used in the main program function call.
        theElem = el[front];
    }
}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize()
{
    // Notice that in this function, we want to return the CURRENT size of the queue, not the MAXIMUM SIZE
    // Remember that we have been incrementing and decrementing an integer variable called count in the add
    // and remove functions. So, since this function is int data return type, all we need to do is return count.
    // This will work because count is also an integer based variable.
    
    return count;
}



// PURPOSE: display everything in the queue horizontally from front to rear
// enclosed in []
// if empty, displays [ empty ]
void queue::displayAll()
{
	if (isEmpty())
		cout << "[empty]" << endl;

	else if (count == 1)
	{
		// If there is only one element in the queue, then we will just print the front.
		cout << "[ " << el[front] << " ]" << endl;
	}

	else
	{
		
		// Otherwise, we print the front, then write a for loop that will go through the array based queue
		// and cout all the other elements.
		cout << "front->[" << el[front] << " ";

		for (int i = 0; i < count - 2; i++)
			cout << el[(front + 1 + i) % MAX_SIZE] << " ";

		cout << el[rear] << "]<-rear" << endl;
		cout << "-----------------------------------------------------------------------------------------------"  << endl;
	}
} 


// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//doing remove followed by add.
void queue::goToBack()
{// ** comment a local variable
    
    // If the queue is empty, throw underFlow exception.
    if (isEmpty())
    {
        throw underFlow();
    }
    
    // No need to go to the back if the front and the rear are the same.
    else if (count > 1)
    {
        el_t element;
		remove(element);
		add(element);
    }
}





