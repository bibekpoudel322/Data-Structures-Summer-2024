#include <iostream>

// Generic function using templates
template <typename T>
T maximum(T a, T b)
{
    return (a > b) ? a : b;
}

// Generic class using templates
template <typename T>
class Pair
{
private:
    T first;
    T second;

public:
    Pair(T f, T s) : first(f), second(s) {}

    T getFirst() const
    {
        return first;
    }

    T getSecond() const
    {
        return second;
    }
};

int main()
{
    // Using the generic function
    int intMax = maximum(5, 9);
    double doubleMax = maximum(3.14, 2.71);

    std::cout << "Maximum of 5 and 9: " << intMax << std::endl;
    std::cout << "Maximum of 3.14 and 2.71: " << doubleMax << std::endl;

    // Using the generic class
    Pair<int> intPair(10, 20);
    Pair<double> doublePair(3.5, 7.2);

    std::cout << "Int Pair: " << intPair.getFirst() << ", " << intPair.getSecond() << std::endl;
    std::cout << "Double Pair: " << doublePair.getFirst() << ", " << doublePair.getSecond() << std::endl;

    return 0;
}
