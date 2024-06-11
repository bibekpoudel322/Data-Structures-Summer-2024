/*
 * @file Practise_lab_6.cpp
 * @author Bibek Poudel
 * @description Binary Heap Implementation in C++
 * @date 6/10/2024
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
    array.push_back(-1);
}
// Insert an element in Heap keeping the Heap property intact
void Heap::insert(int key)
{
    array.push_back(key);
    bubbleup(array.size() - 1);
}
// Remove the minimum value from Heap keeping the Heap property intact
int Heap::removeMin()
{
    if (array.size() < 1)
    {
        throw logic_error("Tree is emprty");
    }
    else
    {
        int min = array[1];
        array[1] = array[array.size() - 1];
        array.pop_back();
        bubbledown(1);
        return min;
    }
}
// Return (but don't remove) the minimum value from the Heap
int Heap::getMin()
{
    return array[1];
}
// Returns the index of the parent of the node i
int Heap::parent(int k)
{
    return k / 2;
}
// Returns the index of the left child of the node i
int Heap::left(int k)
{
    return 2 * k;
}
// Returns the index of the right child of the node i
int Heap::right(int k)
{
    return 2 * k + 1;
}

void Heap::bubbleup(int k)
{
    while (k > 1 && array[k] < array[parent(k)])
    {
        swap(array[k], array[parent(k)]); // bubble up
        k = parent(k);
    }
}

void Heap::bubbledown(int k)
{
    while ((left(k) > k || right(k)) > k && k < array.size())
    {
        if (left(k) <= array.size() && array[left(k)] < array[k])
        {
            swap(array[left(k)], array[k]);
            k = left(k);
        }
        else if (right(k) <= array.size() && array[right(k)] < array[k])
        {
            swap(array[right(k)], array[k]);
            k = right(k);
        }
    }
}
//=====================================
// This method will sort the internal array/vector
// Hint: Leep extracting the min value from the heap and store them into an auxiliary array.
//       Copy the values from auxiliary array to the internal array/vector of heap
void Heap::sort()
{
    // to-do
}
//=============================================