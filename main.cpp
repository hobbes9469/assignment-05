//Matthew Kang

#include "recursion.h"

#include <iostream>
using std::cout;
using std::endl;



int absolute(int a) {
	if (a < 0)
		return -a;
	else
		return a;
}

int gcd_iterative(int a, int b) {
	a = absolute(a);
	b = absolute(b);
	while (a != 0 && b != 0)
	if (a > b)
		a -= b;
	else
		b -= a;
	return a + b;
}

int gcd(int a, int b) {
	a = absolute(a);
	b = absolute(b);
	if (a == 0 || b == 0)
		return a + b;
	if (a > b)
		return gcd(a - b, b);
	else
		return gcd(a, b - a);
}

int fibonacci_iterative(int n, int f1, int f2) {

	for (int a = 1; a < n - 1; a++) {
		int increase;
		increase = f1;
		f1 = f2;
		f2 += increase;
	}

	return f2;
}

int fibonacci(int n, int f1, int f2) {
	if (n == 1 || n == 2)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}

string int_to_roman_iterative(int i) {
	const string numerals[] = {
		"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I",
	};
	const int values[] = {
		1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1,
	};

	if (i < 0)
		return "ERROR: too small";
	if (i >= 4000)
		return "ERROR: too large";

	string ret = "";



	for (int a = 0; a < sizeof(values) / sizeof(int); a++) {
		while (i >= values[a]) {
			ret += numerals[a];
			i -= values[a];
		}
		//if (i >= values[a]) {			//another way
		//	ret += numerals[a];
		//	i -= values[a];
		//	a = 0;		//reset
		//}
	}

	return ret;
}

string int_to_roman(int i) {
	const string numerals[] = {
		"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I",
	};
	const int values[] = {
		1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1,
	};

	if (i < 0)
		return "ERROR: too small";
	if (i >= 4000)
		return "ERROR: too large";
	
	if (i == 0)
		return "";
	for (int a = 0; a < sizeof(values) / sizeof(int); a++) {
		if ((i - values[a]) >= 0){
			return numerals[a] + int_to_roman(i - values[a]);
		}
	}
	
	

	
}

int main() {				//SHORT MAIN TO TEST FUNCTIONS
	cout << "***GCD test***" << endl;
	cout << "--------------------" << endl;

	cout << "GCD iterative of 36 and 18: " << gcd_iterative(36, 18) << endl;
	cout << "GCD recursive of the same:  " << gcd(36, 18) << endl;
	cout << "GCD iterative of 92 and 64: " << gcd_iterative(92, 64) << endl;
	cout << "GCD recursive of the same:  " << gcd(92, 64) << endl;
	cout << endl;
	
	cout << "--------------------" << endl;
	cout << "***Fibonacci test***" << endl;
	cout << "--------------------" << endl;
	cout << "The first 10 Fibonacci numbers, using iteration: " << endl;
	for (int a = 1; a < 11; a++) {
		cout << fibonacci_iterative(a) << " ";
	}
	cout << endl;
	cout << "The first 10 Firbonacci numbers, using recursion: " << endl;
	for (int a = 1; a < 11; a++) {
		cout << fibonacci(a) << " ";
	}
	cout << endl;

	cout << "--------------------" << endl;
	cout << "***Roman numeral test***" << endl;
	cout << "--------------------" << endl;
	cout << "Roman numeral 123  (iteration): " << int_to_roman_iterative(123) << endl;
	cout << "Roman numeral 123  (recursive): " << int_to_roman(123) << endl;
	cout << "Roman numeral 3895 (iteration): " << int_to_roman_iterative(3895) << endl;
	cout << "Roman numeral 3895 (recursive): " << int_to_roman(3895) << endl;
	cout << "Roman numeral 19   (iteration): " << int_to_roman_iterative(19) << endl;
	cout << "Roman numeral 19   (recursive): " << int_to_roman(19) << endl;
	

	std::cin.get();
	return 0;
}
