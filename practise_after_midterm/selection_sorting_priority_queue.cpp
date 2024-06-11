#include <iostream>
#include <list>
#include <fstream>
#include <string>    // for string manipulation
#include <vector>    // for dynamic arrays
#include <algorithm> // for algorithms like sorting
#include <cmath>     // for mathematical functions
#include <iomanip>   // for formatting output
using namespace std;
class mqueue
{
private:
    list<int> myqueue;
    int size;

public:
    mqueue() { size = 0; };
    bool empty()
    {
        return myqueue.empty();
    }
    void insert(int elem)
    {
        myqueue.push_back(elem);
    }
    int get_min()
    {
        if (empty())
        {
            throw logic_error("The queue is empty.");
        }
        int min = myqueue.front();
        for (auto it = myqueue.begin(); it != myqueue.end(); it++)
        {
            if (*it < min)
            {
                min = *it;
            }
        }
        return min;
    }
    void removemin()
    {
        if (empty())
        {
            throw logic_error("The queue is empty.");
        }
        auto it = myqueue.begin();
        while (*it != get_min())
        {
            it++;
        }
        myqueue.erase(it);
    }
};
list<int> sortedlist(list<int> &l)
{
    mqueue q;
    while (!l.empty())
    {
        q.insert(l.front());
        l.pop_front();
    }
    while (!q.empty())
    {
        l.push_back(q.get_min());
        q.removemin();
    }
    return l;
};
int main()
{
    list<int> unsortedList;
    unsortedList.push_back(5);
    unsortedList.push_back(3);
    unsortedList.push_back(7);
    unsortedList.push_back(1);
    unsortedList.push_back(9);
    unsortedList.push_back(2);
    unsortedList.push_back(4);
    unsortedList.push_back(6);
    unsortedList.push_back(8);
    cout << "UnSorted List: \n";
    for (int i : unsortedList)
    {
        cout << i << ",";
    }
    list<int> sorted_list = sortedlist(unsortedList);
    cout << "Sorted List: \n";
    for (int i : sorted_list)
    {
        cout << i << ",";
    }
    return 0;
}