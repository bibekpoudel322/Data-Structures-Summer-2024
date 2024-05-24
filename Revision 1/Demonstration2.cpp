#include <iostream>

// Function to increment a number by a specified value
void incrementByReference(const int &num, int value)
{
    num += value; // This line would cause a compilation error because num is const
    std::cout << "Inside function - Value of num: " << num << std::endl;
    std::cout << "Inside function - Value of value: " << value << std::endl;
}

int main()
{
    int x = 5;

    std::cout << "Before increment: " << x << std::endl;

    // Call the function with x passed by reference
    incrementByReference(x, 3);

    std::cout << "After function call: " << x << std::endl;

    return 0;
}
