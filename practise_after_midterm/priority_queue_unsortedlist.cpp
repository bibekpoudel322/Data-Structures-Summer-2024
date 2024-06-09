#include <iostream>
#include <list>
#include <fstream>
#include <string>    // for string manipulation
#include <vector>    // for dynamic arrays
#include <algorithm> // for algorithms like sorting
#include <cmath>     // for mathematical functions
#include <iomanip>   // for formatting output
using namespace std;
// Priority Queue with a list
class PriorityQueue
{
private:
    list<int> PQ;
    list<int> sorted;

public:
    PriorityQueue() = default;
    void insert(int key)
    {
        PQ.push_back(key);
    };
    void removeMin()
    {
        int min = *getMin();
        PQ.erase(getMin());
    };
    list<int>::iterator getMin()
    {
        if (PQ.empty())
        {
            throw runtime_error("Priority Queue is empty");
        }
        auto minIt = PQ.begin();
        for (auto it = PQ.begin(); it != PQ.end(); ++it)
        {
            if (*it < *minIt)
            {
                minIt = it;
            }
        }
        return minIt;
    }
    bool empty()
    {
        return PQ.empty();
    };
    void print()
    {
        for (auto it = PQ.begin(); it != PQ.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    };
    void sort()
    {
    }
};

int main()
{
    PriorityQueue pq;
    list<int> temp;
    temp.push_back(1);
    temp.push_back(6);
    temp.push_back(3);
    temp.push_back(5);
    temp.push_back(4);
    temp.push_back(2);
    temp.push_back(7);
    while (!temp.empty())
    {
        pq.insert(temp.front());
        temp.pop_front();
    }
    while (!pq.empty())
    {
        temp.push_back(*pq.getMin());
        pq.removeMin();
    }
    cout << "Selection sort :" << endl;
    for (auto it = temp.begin(); it != temp.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}
