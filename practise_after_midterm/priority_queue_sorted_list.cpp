#include <iostream>
#include <list>
#include <fstream>
#include <string>    // for string manipulation
#include <vector>    // for dynamic arrays
#include <algorithm> // for algorithms like sorting
#include <cmath>     // for mathematical functions
#include <iomanip>   // for formatting output
using namespace std;
// Insertion sort using sorted list
class priority_queue_sorted_list
{
private:
    list<int> pq;

public:
    priority_queue_sorted_list() = default;
    void insert(int key)
    {
        if (pq.empty())
        {
            pq.push_back(key);
        }
        else
        {
            auto it = pq.begin();
            while (it != pq.end() && *it < key)
            {
                it++;
            }
            pq.insert(it, key);
        }
    }
    int get_min()
    {
        return pq.front();
    }
    int remove_min()
    {
        pq.pop_front();
    }
    bool is_empty()
    {
        return pq.empty();
    }
    ~priority_queue_sorted_list() = default;
};

int main()
{
    list<int> l1;
    priority_queue_sorted_list q;
    l1.push_back(3);
    l1.push_back(7);
    l1.push_back(1);
    l1.push_back(90);
    l1.push_back(311);
    l1.push_back(11);
    l1.push_back(2);
    l1.push_back(8);
    cout << "Unsorted Array: " << endl;
    while (!l1.empty())
    {
        q.insert(l1.front());
        cout << l1.front() << " ";
        l1.pop_front();
    }
    while (!q.is_empty())
    {
        l1.push_back(q.get_min());
        q.remove_min();
    }

    cout << "\nSorted array" << endl;
    for (auto i = l1.begin(); i != l1.end(); i++)
    {
        cout << *i << " ";
    }

    return 0;
}