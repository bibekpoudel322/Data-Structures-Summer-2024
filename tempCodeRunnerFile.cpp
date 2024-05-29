// Test case 1: Simple infix expression with addition and subtraction
string infix1 = "2 + 3 - 4";
// Expected postfix: "23+4-"

// Test case 2: Infix expression with multiplication and division
string infix2 = "5 * (4 + 2) / 3";
// Expected postfix: "542+*3/"

// Test case 3: Infix expression with exponentiation
string infix3 = "2 ^ 3 ^ 2";
// Expected postfix: "232^^"

// Test case 4: Infix expression with parentheses
string infix4 = "(2 + 3) * 4";
// Expected postfix: "23+4*"

// Test case 5: Infix expression with multiple operators and parentheses
string infix5 = "2 + 3 * (4 - 1)";
// Expected postfix: "2341-*+"