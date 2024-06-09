/*
 * @file lab6_heaps_bp2376.cpp
 * @author Bibek Poudel
 * @description Binary Heap Implementation in C++
 * @date 6/8/2024
 */
// starter_code_begins
#include <iostream>
#include <exception>
#include <math.h>
#include <ctime>
#include <vector>
#include <iomanip>
#include <sstream>
using namespace std;

class Heap
{
private:
	vector<int> array;

public:
	Heap();
	void insert(int key);
	int removeMin();
	int getMin();
	int parent(int k);
	int left(int k);
	int right(int k);
	void bubbleup(int k);
	void bubbledown(int k);
	void print();
	void sort();
};

void listCommands()
{
	cout << "-----------------------------------------------------------------" << endl;
	cout << "display            :Display the Heap" << endl
		 << "insert <key>       :Insert a new element in the Heap" << endl
		 << "getMin             :Get the element with Min. Key in the Heap" << endl
		 << "removeMin          :Remove the element with Min. Key from Heap" << endl
		 << "sort               :Sort the Heap" << endl
		 << "help               :Display the available commands" << endl
		 << "exit/quit          :Exit the program" << endl;
	cout << "-----------------------------------------------------------------" << endl;
}
//=============================================
void demo(Heap &myHeap)
{
	for (int i = 1; i <= 7; i++)
	{
		int n = rand() % 25;
		myHeap.insert(n);
	}
	myHeap.print();
}
//=============================================
int main()
{

	Heap myHeap;
	string user_input;
	string command;
	string argument;

	listCommands();

	while (true)
	{
		try
		{
			cout << ">";
			getline(cin, user_input);

			// parse userinput into command and parameter(s)
			stringstream sstr(user_input);
			getline(sstr, command, ' ');
			getline(sstr, argument);

			if (command == "display" or command == "d")
				myHeap.print();
			else if (command == "insert" or command == "i")
			{
				myHeap.insert(stoi(argument));
				myHeap.print();
			}
			else if (command == "getMin")
			{
				int min = myHeap.getMin();
				cout << "Min Key = " << min << endl;
			}
			else if (command == "removeMin" or command == "r")
			{
				cout << myHeap.removeMin() << " has been removed..!" << endl;
				myHeap.print();
			}
			else if (command == "sort")
			{
				myHeap.sort();
				myHeap.print();
			}
			else if (command == "help")
				listCommands();
			else if (command == "demo")
				demo(myHeap);
			else if (command == "exit" or command == "quit")
				break;
			else
				cout << "Invalid command !!!" << endl;
		}
		catch (exception &e)
		{
			cout << "Exception: " << e.what() << endl;
		}
	}
	return EXIT_SUCCESS;
}
//==================================================================
// This method prints a Heap in 2D format.
void Heap::print()
{
	if (array.size() > 1)
	{
		int levels = int(log2(array.size()));

		int *spaces = new int[levels + 1];
		spaces[levels] = 0;

		for (int j = levels - 1; j >= 0; j--)
		{
			spaces[j] = 2 * spaces[j + 1] + 1;
		}

		int level = 0;
		for (int i = 0; i < array.size() - 1; i++)
		{
			if (i == (pow(2, level) - 1))
			{
				cout << endl
					 << endl;

				for (int k = 0; k < spaces[level]; k++)
					cout << "   ";
				level++;
			}
			cout << std::left << setw(3) << array[i + 1];

			if (level > 1)
			{
				for (int k = 0; k < spaces[level - 2]; k++)
					cout << "   ";
			}
		}
		cout << endl;
		for (int i = 0; i < spaces[0] * log2(array.size() / 2) + 4; i++)
			cout << "__";

		cout << endl;
		delete[] spaces;
	}
}
// starter_code_ends
// Constructor
Heap::Heap()
{
	array.push_back(-1); // dummy element
}
// Insert an element in Heap keeping the Heap property intact
void Heap::insert(int key)
{
	array.push_back(key);		// insert at the end
	bubbleup(array.size() - 1); // bubble up the element
}
// Remove the minimum value from Heap keeping the Heap property intact
int Heap::removeMin()
{
	int min = array[1];					// store the min value
	array[1] = array[array.size() - 1]; // replace the root with the last element
	array.pop_back();					// remove the last element
	bubbledown(1);						// bubble down the root
	return min;							// return the min value
}
// Return (but don't remove) the minimum value from the Heap
int Heap::getMin()
{
	return array[1]; // return the root
}
// Returns the index of the parent of the node i
int Heap::parent(int k)
{
	return k / 2; // parent of k is k/2
}
// Returns the index of the left child of the node i
int Heap::left(int k)
{
	return 2 * k; // left child of k is 2*k
}
// Returns the index of the right child of the node i
int Heap::right(int k)
{
	return 2 * k + 1; // right child of k is 2*k+1
}

void Heap::bubbleup(int k)
{
	int p = parent(k);					 // parent of k
	while (k > 1 && array[p] > array[k]) // while k is not the root and parent is greater than k
	{
		swap(array[p], array[k]); // swap parent and k
		k = p;					  // move to parent
		p = parent(k);			  // update parent
	}
}

void Heap::bubbledown(int k)
{
	int l = left(k);									// left child of k
	int r = right(k);									// right child of k
	int smallest = k;									// assume k is the smallest
	if (l < array.size() && array[l] < array[k])		// if left child is smaller than k
		smallest = l;									// update smallest
	if (r < array.size() && array[r] < array[smallest]) // if right child is smaller than smallest
		smallest = r;									// update smallest
	if (smallest != k)									// if smallest is not k
	{
		swap(array[k], array[smallest]); // swap k and smallest
		bubbledown(smallest);			 // bubble down smallest
	}
}
//=====================================
// This method will sort the internal array/vector
// Hint: Leep extracting the min value from the heap and store them into an auxiliary array.
//       Copy the values from auxiliary array to the internal array/vector of heap
void Heap::sort()
{
	vector<int> aux;		 // auxiliary array
	aux.push_back(-1);		 // dummy element
	while (array.size() > 1) // while heap is not empty
	{
		aux.push_back(removeMin()); // remove min and store in aux
	}
	array = aux; // copy aux to array
}
//=============================================