//
//  binsearch.cpp
//  binarySearch
//
//  Created by Parth Kapur on 9/21/17.
//  Copyright © 2017 Parth Kapur. All rights reserved.
//

#include <stdio.h>
#include <cmath>
#include <iostream>
using namespace std;

#define MAX 10

/* This is the prototype function. Since it is a prototype, we do not need
 to declare the variable names for the data type.
*/
int binarySearch(int[], int, int, int);

int main()
{
    int array[MAX] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int userInput;
    int myfirst = 0;
    int mylast = MAX - 1;
    int resultloc;
    
    cout << "Please enter in the number you would like to search for: ";
    cin >> userInput;
    
    resultloc = binarySearch(array, myfirst, mylast, userInput);
    
    if (resultloc == -1)
    {
        cout << "Unable to find " << userInput << "!" << endl;
    }
    else
    {
      cout << userInput << " is found at position " << (resultloc+1) << " of the array." << endl;
    }
    
    return 0;
}

int binarySearch(int L[], int first, int last, int input)
{
    int middle;
    
    // We are dividing the mylastimum by 2 in order to find the middle. Note that the floor function will take
    // the result of that division and round down.
    middle = floor(last / 2);
    
    if(first < last)
    {
        int middle=(last + first)/2;
        
        if (L[middle] == input)
        {
            return middle;
        }
        
        else if (L[middle] > input)
        {
            return binarySearch(L,first,(middle-1), input);
        }
        else
        {
            return binarySearch(L,(middle+1),last, input);
        }
    }
    else if(L[first] == input)
    {
        return first;// found input
    }
    else
    {
       return -1;// input not found
    }
}
