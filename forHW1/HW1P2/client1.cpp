//INSTRUCTION
//Look for ** to complete this program 
//The output should match my hw1stackDemo.out 

//=========================================================
//HW#: HW1P1 stack
//Your name: Parth Kapur
//Complier:  g++
//File type: client program
//===========================================================



#include <iostream>
#include <stdlib.h>
#include <string>
#include "vstack.h"

using namespace std;


//Purpose of the program: The purpose of the program is to provide a calculator for postfix expressions, so that a user does not have to manually calculate postfix expressions and instead can enter in the postfix expressions here

//Algorithm: The user should enter in an expression. That expression is then pushed onto the stack. If the expression is a number, it is pushed. If it is an operator, two elements should be popped from the stack and 
// evaluated with the operator, then that result should be pushed back into the stack. This should continue until the entire postfix expression is evaluated. If there is not two elements in the stack to be evaluated with the operator
// then there should be an output for incomplete expression. If the postfix expression is too lengthy, then throw the exception overflow. 
int main()
{
	stack postfixstack;  // integer stack
	string expression;   // user entered expression

	cout << "type a postfix expression: ";
	cin >> expression;

	int i = 0;  // character position within expression
	char item;  // one char out of the expression

	int box1;  // receive things from pop
	int box2;  // receive things from pop
	int result; // the last result of the stack will go here

	while (expression[i] != '\0')
	{
		try
		{
			item = expression[i];  // current char
								   
								   
		    //2.  if it is an operand (number), 
			//    push it (you might get Overflow exception)
			if ((item >= '0') && (item <= '9'))
			{
				postfixstack.push((el_t)(item - '0'));
				postfixstack.displayAll();
			} // end of if
	  
	  //3.  else if it is an operator,
	  //    pop the two operands (you might get Underflow exception), and
	  //	apply the operator to the two operands, and
	  //    push the result.
			else if ( (item == '+') || (item == '-') || (item == '*'))
			{
				postfixstack.pop(box1);
				postfixstack.displayAll();
				cout << endl;

				postfixstack.pop(box2);
				postfixstack.displayAll();
				cout << "----------------";

				if ((box1 <= 0 && box1 >= 9) || (box2 <= 0 && box2 >= 9)) // this condition will check if we are NOT working with operands
				{
					throw "Invalid Operand"; //if atleast one is not an operand, we display an error message at the screen
				}

				else
				{
					if (item == '-')
					{
						result = box2 - box1;
					}
					// ** also do the + and * cases
					else if (item == '+')
					{
						result = box2 + box1;
					}
					else if (item == '*')
					{
						result = box2 * box1;
					}

				}
				//cases for different operators follow:
				
				 
				// ** Finally push the result

				postfixstack.push(result);

				cout << endl;
	    }

			else { throw "invalid item"; }

	} // this closes try
      
      // Catch exceptions and report problems and quit the program now. 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow) 
		{
		  cerr << "Expression too long" << endl;
		  exit(1);
		}
      catch (stack::Underflow) // for too few operands
		{
		  cerr << "Too few operands" << endl;
		  exit(1);
		}
      catch (char const* errorcode) // for invalid item
		{
		  cerr << errorcode << endl;
		  exit(1);
		}
     
	  i++;  // go back to the loop after incrementing i
      
    }// end of while
  
  // After the loop successfully completes: 
  // The result will be at the top of the stack. Pop it and show it.
	postfixstack.topElem(result);

	cout << "Result = " << result << endl;

  // If anything is left on the stack, an incomplete expression was found.
  // Inform the user.
	if (postfixstack.isEmpty())
	{
		cout << "postfixexpression complete!" << endl;
	}
	else
	{
		cout << "incomplete expression" << endl;
	}


	system("PAUSE");
	return 0;

}// end of the program
