#include <iostream>
#include <vector>
using namespace std;

class BinaryTree
{
private:
    vector<int> tree;

    int getLevelNumber(int index)
    {
        return tree[index];
    }

public:
    BinaryTree(int size)
    {
        tree.resize(size + 1, -1); // Initialize the tree with size + 1 for 1-based indexing
    }

    void setRoot(int value)
    {
        tree[1] = value;
    }

    void setLeftChild(int parentIndex, int value)
    {
        int leftChildIndex = 2 * parentIndex;
        if (leftChildIndex < tree.size())
        {
            tree[leftChildIndex] = value;
        }
        else
        {
            cout << "Index out of bounds" << endl;
        }
    }

    void setRightChild(int parentIndex, int value)
    {
        int rightChildIndex = 2 * parentIndex + 1;
        if (rightChildIndex < tree.size())
        {
            tree[rightChildIndex] = value;
        }
        else
        {
            cout << "Index out of bounds" << endl;
        }
    }

    void display()
    {
        for (int i = 1; i < tree.size(); ++i)
        {
            if (tree[i] != -1)
            {
                cout << "Node " << i << ": " << tree[i] << endl;
            }
        }
    }
};

int main()
{
    BinaryTree bt(7); // Tree size based on the number of nodes
    bt.setRoot(1);
    bt.setLeftChild(1, 2);
    bt.setRightChild(1, 3);
    bt.setLeftChild(2, 4);
    bt.setRightChild(2, 5);
    bt.setLeftChild(3, 6);
    bt.setRightChild(3, 7);

    cout << "Binary Tree:" << endl;
    bt.display();

    return 0;
}
