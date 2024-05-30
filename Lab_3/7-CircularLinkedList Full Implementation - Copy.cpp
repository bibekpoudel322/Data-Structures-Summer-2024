#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

typedef string Elem;

class Node {
public:
    Elem data;
    Node* next;
    Node(const Elem& e) : data(e), next(nullptr) {}
};

class CircleList {
private:
    Node* cursor;

public:
    CircleList() : cursor(nullptr) {}

    ~CircleList() {
        while (!empty()) {
            remove();
        }
    }

    bool empty() const {
        return cursor == nullptr;
    }

    const Elem& front() const {
        if (empty()) throw runtime_error("Queue is empty");
        return cursor->next->data;
    }

    void add(const Elem& e) {
        Node* newNode = new Node(e);
        if (empty()) {
            newNode->next = newNode;
            cursor = newNode;
        } else {
            newNode->next = cursor->next;
            cursor->next = newNode;
        }
    }

    void remove() {
        if (empty()) throw runtime_error("Queue is empty");
        Node* old = cursor->next;
        if (old == cursor) {
            cursor = nullptr;
        } else {
            cursor->next = old->next;
        }
        delete old;
    }

    void advance() {
        cursor = cursor->next;
    }

    // This friend declaration allows LinkedQueue to access CircleList's private members.
    friend class LinkedQueue;
};

class LinkedQueue {
public:
    typedef string Elem; // queue element type

    LinkedQueue() : C(), n(0) {}

    int size() const {
        return n;
    }

    bool empty() const {
        return n == 0;
    }

    const Elem& front() const {
        if (empty()) throw runtime_error("Queue is empty");
        return C.front();
    }

    void enqueue(const Elem& e) {
        C.add(e);
        C.advance();
        n++;
    }

    void dequeue() {
        if (empty()) throw runtime_error("Queue is empty");
        C.remove();
        n--;
    }

private:
    CircleList C; // Circular list used as the underlying data structure for the queue.
    int n;       // Number of elements in the queue.
};

int main() {
    LinkedQueue queue;

    cout << "Is the queue empty? " << (queue.empty() ? "Yes" : "No") << endl;

    queue.enqueue("Apple");
    queue.enqueue("Banana");
    queue.enqueue("Cherry");

    cout << "Front of the queue: " << queue.front() << endl;

    queue.dequeue();

    cout << "Front of the queue after dequeue: " << queue.front() << endl;

    cout << "Queue size: " << queue.size() << endl;

    return 0;
}
