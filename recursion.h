//Matthew Kang

#include <string>
using std::string;

int absolute(int a);
//Function for absolute value.

int gcd_iterative(int a, int b);
//Takes two integers and returns their GCD.

int gcd(int a, int b);
//Does the same as the function above, but recursively.

int fibonacci_iterative(int n, int f1 = 1, int f2 = 1);
//Returns the nth Fibonacci number iteratively.

int fibonacci(int n, int f1 = 1, int f2 = 1);
//Does the same as the function above, but recursively.

string int_to_roman_iterative(int i);
//EXAMPLE PROGRAM from assignment 5.

string int_to_roman(int i);
//Recursive version of the int_to_roman_iterative program.
