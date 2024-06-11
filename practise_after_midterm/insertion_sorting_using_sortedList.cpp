#include <iostream>
#include <list>
#include <fstream>
#include <string>    // for string manipulation
#include <vector>    // for dynamic arrays
#include <algorithm> // for algorithms like sorting
#include <cmath>     // for mathematical functions
#include <iomanip>   // for formatting output
using namespace std;
class myqueue
{
private:
    int size;
    list<int> q;

public:
    myqueue()
    {
        size = 0;
    }
    int get_size()
    {
        return size;
    }
    bool is_empty()
    {
        return size == 0;
    }
    void insert(int elem)
    {
        if (is_empty())
        {
            q.push_back(elem);
        }
        else
        {
            auto it = q.begin();
            while (it != q.end() && *it < elem)
            {
                it++;
            }
            q.insert(it, elem);
        }
        size++;
    }
    int get_min()
    {
        return q.front();
    }
    int remove_min()
    {
        q.pop_front();
        size--;
    }
    void display()
    {
        cout << "\n Elements in the queue : \n";
        for (auto i = q.begin(); i != q.end(); i++)
        {
            cout << *i << ",";
        }
    }
};
list<int> sortedlist(list<int> &l)
{
    myqueue q;
    while (!l.empty())
    {
        q.insert(l.front());
        l.pop_front();
    }
    while (!q.is_empty())
    {
        l.push_back(q.get_min());
        q.remove_min();
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