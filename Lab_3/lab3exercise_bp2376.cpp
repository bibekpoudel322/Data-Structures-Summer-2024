/**
 * @file lab3exercise_bp2376.cpp
 * @author Bibek Poudel
 * @description This program convert an Infix expression to PostFix and then evaluate it
 * @date 5/29/2024
 */
// starter_code_begins
#include <iostream>
#include <string>
#include <exception>
#include <math.h>
#include <ctype.h>

using namespace std;

//=============MyStack Class ================
template <typename T>
class MyStack
{
private:
	T *array;
	int n; // number of current elements in the MyStack
	int N; // Array Size (Capacity)
public:
	MyStack(int N = 50); // we set default capacity of stack as 50
	~MyStack();
	void push(T); // Push an elemet in the stack
	void pop();	  // pop/remove the element at the tos
	T &top();	  // return reference of the top element
	int size();	  // return current size of MyStack
	bool empty(); // returns true if the stack is Empty
};
//=============================================
bool isOperator(char);				// Function that checks if the input char is an operator
bool isgeq(char, char);				// Helper function that compare two operators  and return True if the presedence of first operator is greater than or equal to the second operator
int convertOpToInt(char);			// Function that converts operators into int so their precdence can be compared
string infix2postfix(string);		// Function that converts an infix notaiton into a postfix notation (lab4)
float evaluate(string postfix);		// Function that will evaluate a PostfixExpression and return the result
bool isBalanced(string expression); // Funciton that will check for balanced parentheses
//==========================================
int main()
{

	while (true)
	{
		string infix; // Infix expression
		cout << "Enter an Infix Expression: ";
		cin >> infix;
		try
		{
			if (infix == "exit")
				break;

			else if (!isBalanced(infix))
			{
				cout << "Expression is not Balanced " << endl;
				continue;
			}

			string postfix = infix2postfix(infix); // Postfix Expression
			cout << "The postfix form is: " << postfix << endl;
			float ans = evaluate(postfix);		 // evaluate the postfix Expresion
			cout << infix << "=" << ans << endl; // print the final answer
		}
		catch (exception &e)
		{
			cout << "Exception: " << e.what() << endl;
		}
	}

	return EXIT_SUCCESS;
}
//==========================================
// Function that checks if a given char is a valid operator or not.
bool isOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
		return true;
	else
		return false;
}
//==========================================
// Function that converts operators into an integer so its precdence can be checked
int convertOpToInt(char ch)
{
	if (ch == '+' || ch == '-')
		return 1;
	if (ch == '*' || ch == '/')
		return 2;
	if (ch == '^')
		return 3;
	return 0;
}
// Helper method that compare two operators and return true if first operator
// has greater or equal predence than the second operator
bool isgeq(char opA, char opB)
{
	return (convertOpToInt(opA) >= convertOpToInt(opB));
}
// starter_code_ends
//===============================================================================
//  == Define the methods of My Stack and other functions below this line.
//===============================================================================
template <typename T>
MyStack<T>::MyStack(int N)
{
	this->N = N;	  // Set the capacity of the stack
	array = new T[N]; // Create an array of size N
	n = 0;			  // Initialize the number of elements in the stack to 0
}
template <typename T>
MyStack<T>::~MyStack()
{
	delete[] array; // Deallocate the memory
}
template <typename T>
void MyStack<T>::push(T elem) // Push an element in the stack
{
	if (n == N)
		throw logic_error("Stack Overflow"); // Check if the stack is full
	array[n++] = elem;						 // Add the element to the stack
}
template <typename T>
void MyStack<T>::pop()
{
	if (n == 0) // Check if the stack is empty
		throw logic_error("Stack Underflow");
	n--; // Remove the element from the stack
}
template <typename T>
T &MyStack<T>::top()
{
	if (n == 0)								 // Check if the stack is empty
		throw logic_error("Stack is Empty"); // Throw an exception if the stack is empty
	return array[n - 1];					 // Return the top element of the stack
}
template <typename T>
int MyStack<T>::size() // Return the number of elements in the stack
{
	return n;
}
template <typename T>
bool MyStack<T>::empty()
{
	return n == 0; // Return true if the stack is empty
}

bool isBalanced(string expression)
{
	MyStack<char> stack(expression.size());		// Create a stack to store the parentheses
	for (int i = 0; i < expression.size(); i++) // Iterate through the expression
	{
		if (expression[i] == '(')	   // If an opening parenthesis is found, push it to the stack
			stack.push(expression[i]); // Push the opening parenthesis to the stack
		else if (expression[i] == ')') // If a closing parenthesis is found
		{
			if (stack.empty()) // If the stack is empty, return false
				return false;  //	Return false if the stack is empty
			stack.pop();	   // Pop the opening parenthesis from the stack
		}
	}
	return stack.empty(); // Return true if the stack is empty
}

string infix2postfix(string infix)
{
	string postfix = "";			   // Initialize an empty string to store the postfix expression
	MyStack<char> stack(infix.size()); // Create a stack to store operators and parentheses

	// Scan Infix expression from left to right
	for (char c : infix)
	{
		if (!isBalanced(infix))
		{
			throw runtime_error("Unbalanced parentheses");
		}

		char currentChar = c;

		// If the scanned character is an operand, add it to the postfix expression
		if (isdigit(currentChar))
			postfix += currentChar;
		// If '(' is found, push it to the stack
		else if (currentChar == '(')
			stack.push(currentChar);
		// If an operator is found
		else if (isOperator(currentChar))
		{
			// a. Pop from the stack and add each operator from the top of the stack with the same or higher precedence until '(' or an operator with lower precedence is found or the stack is empty
			while (!stack.empty() && stack.top() != '(' && isgeq(stack.top(), currentChar))
			{
				postfix += stack.top();
				stack.pop();
			}
			// b. Push the operator to the stack
			stack.push(currentChar);
		}
		// If ')' is found
		else if (currentChar == ')')
		{
			// a. Pop from the stack and add each operator from the top of the stack until '(' is found
			while (!stack.empty() && stack.top() != '(')
			{
				postfix += stack.top();
				stack.pop();
			}
			// Pop '(' from the stack
			if (!stack.empty())
			{
				stack.pop();
			}
			else
			{
				throw runtime_error("Unbalanced parentheses");
			}
		}
	}

	// Repeat all remaining operators from the stack to the postfix
	while (!stack.empty())
	{
		if (stack.top() == '(')
			throw runtime_error("Unbalanced parentheses");
		postfix += stack.top();
		stack.pop();
	}

	return postfix;
}

float evaluate(string postfix) // Evaluate the postfix expression
{
	MyStack<float> stack(postfix.size());	 // Create a stack to store the operands
	for (int i = 0; i < postfix.size(); i++) // Iterate through the postfix expression
	{
		char currentChar = postfix[i];	   // Get the current character
		if (isalnum(currentChar))		   // If the character is an operand, push it to the stack
			stack.push(currentChar - '0'); // Push the operand to the stack
		else if (isOperator(currentChar))  // If the character is an operator
		{
			float operand2 = stack.top(); // Pop the top two operands from the stack
			stack.pop();				  // Pop the top operand from the stack
			float operand1 = stack.top(); // Pop the top operand from the stack
			stack.pop();				  //	Pop the top operand from the stack
			float result;				  // Perform the operation based on the operator
			switch (currentChar)		  // Perform the operation based on the operator
			{
			case '+':
				result = operand1 + operand2; // Perform addition
				break;
			case '-':
				result = operand1 - operand2; // Perform subtraction
				break;
			case '*':
				result = operand1 * operand2; // Perform multiplication
				break;
			case '/':
				if (operand2 == 0)							 // Check for division by zero
					throw runtime_error("Division by Zero"); // Throw an exception if division by zero is attempted
				result = operand1 / operand2;				 // Perform division
				break;
			case '^':
				result = pow(operand1, operand2); // Perform exponentiation
				break;
			}
			stack.push(result); // Push the result back to the stack
		}
	}
	return stack.top(); // Return the final result
}
