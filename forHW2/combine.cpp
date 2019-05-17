#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void displayVector(vector<int> & vec)
{
	cout << "[";

	for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << " ";
	}

	cout << "]" << endl;
}

void combine(vector<int>& A, vector<int>& B, vector<int>& R)
{
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	while (!A.empty() && !B.empty())
	{
		if (A.back() < B.back())
		{
			R.push_back(A.back());
			A.pop_back();
		}

		else
		{
			R.push_back(B.back());
			B.pop_back();
		}

		cout << " - comparison!" << endl;
	}

	if (!A.empty())
	{
		while (!A.empty())
		{
			R.push_back(A.back()); // We are updating vector R.
			A.pop_back();
		}
	}

	else if (!B.empty())
	{
		while (!B.empty())
		{
			R.push_back(B.back()); // We are updating vector R.
			B.pop_back();
		}
	}
}


int main()
{

	vector<int> L1, L2, L3; // declaring three vectors called L1, L2, L3. L3 will be the combination of vector L1 and L2
	int userInput;
	int sizeOfVec;


	cout << "Please enter the size of Vector 1: ";
	cin >> sizeOfVec;
	cout << "Please type in integers in increasing order into L1 Vector." << endl;
	
	for (int i = 0; i < sizeOfVec; i++)
	{
		cout << " - element " << i + 1 << ": ";
		cin >> userInput;
		L1.push_back(userInput);
	}

	cout << "Contents of Vector 1: ";
	displayVector(L1);

	cout << endl;


	cout << "Please enter the size of Vector 2: ";
	cin >> sizeOfVec;

	cout << "Please type in integers in increasing order into L2 Vector." << endl;

	for (int i = 0; i < sizeOfVec; i++)
	{
		cout << " - element " << i + 1 << ": ";
		cin >> userInput;
		L2.push_back(userInput);
	}

	cout << "Contents of Vector 2: ";
	displayVector(L2);
	cout << endl;

	cout << "Now we will combine both Vector 1 (L1) and Vector 2 (L2)! " << endl;
	combine(L1, L2, L3);

	cout << "This is the result of Vector 3, which is a combination of Vector 1 (L1) and Vector 2 (L2)! " << endl;
	displayVector(L3);




	system("PAUSE");
	return 0;
}
