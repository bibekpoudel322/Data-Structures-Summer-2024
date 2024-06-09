#include <iostream>
#include <list>

int main()
{
    // Create an empty list of floating-point numbers
    std::list<float> myList;

    // Check if the list is empty
    if (myList.empty())
    {
        std::cout << "The list is empty." << std::endl;
    }

    // Add elements to the back of the list
    myList.push_back(3.14);
    myList.push_back(2.71);
    myList.push_back(1.618);

    // Add elements to the front of the list
    myList.push_front(42.0);
    myList.push_front(7.77);

    // Display the elements in the list
    std::cout << "Elements in the list:" << std::endl;
    for (const float &value : myList)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Check the size of the list
    std::cout << "Size of the list: " << myList.size() << std::endl;

    // Access the first and last elements
    std::cout << "First element: " << myList.front() << std::endl;
    std::cout << "Last element: " << myList.back() << std::endl;

    // Remove elements from the list
    myList.pop_front(); // Remove the first element
    myList.pop_back();  // Remove the last element

    // Display the updated list
    std::cout << "Updated list:" << std::endl;
    for (const float &value : myList)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
