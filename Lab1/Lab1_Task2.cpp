// Task-2: Functions and Arrays(0.4Points)Write a C++ program that creates a dynamic array. The array size should be taken as  input  from  the  user  through  the  terminal.  Once  created,  the  array  should  be populated  with  random  values  in  the  range  of  0-100  (both  inclusive).  Complete  the function called 'findMinMax()'that identifies the minimumand maximumvalues from the array and returns those values to the main function by updating parameters passed by reference. The starter code lab1_2.cpp is available on Brightspace.Hints:Use  the  'new'  operator  to  allocate  memory  for  the  array  in  the  heap dynamically. Don't forget to delete the dynamically allocated memory at the end of the program.The output of the program should look like the following:Note: Comments  are  a  crucial  part  of  any  program.  You  should  always  write comments in your code. Comments worth 10% of your grade. Please do not modify the function headers given in the starter code. Upload onecpp filefor each task i.e.lab1_1.cpp for task 1 and lab1_2.cpp for task.
//============================================================================
// Name         : lab1_2
// Author       : Bibek Poudel
// Version      :
// Date Created :5/23/2024
// Date Modified:
// Description  : Find the minimum and the maximum values in an Array using a
//				  function (findMinMax) that takes the array, its size and
//				  two variables min and max by reference.
//============================================================================
#include <iostream>
#include <cstdlib>
using namespace std;

void findMinMax(int[], int, int &, int &); // function declaration

int main(void)
{
    // Declare variables
    int arraySize;
    // Prompt user to enter the size of the dynamic array
    cout << "Enter the size of the array : " << endl;
    cin >> arraySize;
    // Create a dynamic array
    int *ourarray = new int[arraySize];
    // Populate the array with random values
    for (int i = 0; i < arraySize; i++)
    {
        ourarray[i] = rand() % 101;
    }
    // Call the function findMinMax()
    int min, max;
    findMinMax(ourarray, arraySize, min, max);
    // Print the values of array followed by min and max values
    cout << "Array values are: ";
    for (int i = 0; i < arraySize; i++)
    {
        cout << ourarray[i] << " ";
    }
    cout << endl;
    cout << "Minimum value is: " << min << endl;
    cout << "Maximum value is: " << max << endl;
    // Do Necessary cleanup, e.g. delete dynamically allocated memory.
    delete[] ourarray;
    // Exit the program
    return EXIT_SUCCESS;
}

// Function Definition
void findMinMax(int array[], int arraySize, int &min, int &max)
{
    // define function body.
    min = array[0];
    max = array[0];
    for (int i = 1; i < arraySize; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
        if (array[i] > max)
        {
            max = array[i];
        }
    }
}
