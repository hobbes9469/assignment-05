## Recursion

### Notes

- The functions described below may all be placed in the same file.  You should
  use `main()` to test these functions, and make sure they work properly.


### Requirements

#### Euclid's Algorithm (GCD)

Euclid's algorithm is an efficient method for finding the GCD (greatest common
divisor) of two integers.  Recall that the GCD of two integers, `a` and `b`,
written `gcd(a,b)`, is the largest integer that evenly divides both `a` and
`b`.  Importantly, the `gcd` function has the following properties:

0. `gcd(a,0)` evaluates to `abs(a)`
0. `gcd(a,b)` is equivalent to `gcd(abs(a),abs(b))`
0. `gcd(a,b)` is equivalent to `gcd(a-b,b)` is equivalent to `gcd(a,b-a)`

Thus, for our purposes, we may describe a recursive form of the algorithm as
follows:

0. Normalize `a` and `b` by setting them equal to their absolute values.
0. If `a` or `b` is `0` then return whichever is nonzero.
0. If `a > b` then return `gcd(a-b,b)`
0. Otherwise return `gcd(a,b-a)`

We may also describe an iterative form of the algorithm:

0. Normalize `a` and `b` by setting them equal to their absolute values.
0. While `a` and `b` are both nonzero
    0. If `a > b` set `a -= b`
    0. Otherwise set `b -= a`
0. Return whichever of `a` or `b` is nonzero.

**Do the following:**

0. Write a function named `gcd_iterative` that takes two `int`s and returns
   their GCD as an `int`, using the iterative form of the algorithm described
   above.
0. Write a function named `gcd` that takes two `int`s and returns their GCD as
   an `int`, using the recursive form of the algorithm described above.

#### Fibonacci

The Fibonacci sequence is the sequence

```
1 1 2 3 5 8 13 21 ...
```

where the first two terms are `1` and `1` (or sometimes `0` and `1`) and each
successive term is the sum of the two terms before it.  More concisely:

```
F_1 = 1
F_2 = 1
F_n = F_(n-1) + F_(n-2)
```

**Do the following:**

0. Write a definition for a function with the prototype
   `int fibonacci_iterative(int n, int f1 = 1, int f2 = 1);`
   that iteratively calculates, then returns, the `n`th Fibonacci number.
0. Write a definition for a function with the prototype
   `int fibonacci(int n, int f1 = 1, int f2 = 1);`
   that recursively calculates, then returns, the `n`th Fibonacci number.

#### Roman Numerals

Remember [assignment-01](../../../assignment-01), where we talked about Roman
numerals? :) .  Here is a relatively compact iterative solution the assignment
that, instead of printing the result to standard output, returns the numeral as
a string.

```c++
string int_to_roman_iterative(int i) {
    const string numerals[] = {
        "M",  "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I",
    };
    const int values[] = {
        1000, 900,  500, 400,  100, 90,   50,  40,   10,  9,    5,   4,    1,
    };

    if (i < 0)
        return "ERROR: too small";
    if (i >= 4000)
        return "ERROR: too large";

    string ret = "";

    for (int a = 0; a < sizeof(values)/sizeof(int); a++) {
        if (i >= values[a]) {
            ret += numerals[a];
            i -= values[a];
        }
    }

    return ret;
}
```

**Do the following:**

0. Write a recursive version of this algorithm.

Feel free to base your code on the above, or on your original solution, or on
any other solution you wish (though, in the third case at least, you should
document the code you are referencing).

**Notes:**

- This is a good example of a *greedy* algorithm: we have a list of symbols
  (and compound symbols, such as "CM") and associated values, and we use as
  many of the largest as we possibly can before moving on to the next smaller
  symbol -- and we never go backwards and undo anything.  So (loosely) the
  algorithm takes as much as it can, as fast as it can, and never gives
  anything back -- like a pirate -- it's very greedy.


### Challenge

#### Integers to Words

Write a recursive function to turn `int`s into English.  That is, `111` should
become `one hundred eleven`, etc.

**Small Hints:**

- Note the use of `const` arrays in the function `int_to_roman` above.  A
  similar technique may be useful here.  E.g. if you have an array named `ones`
  such that `ones[1] == "one"`, it may save you quite a few `if` statements.

- Note the use of "extra" arguments with default values in the function
  `fibonacci` described above.  A similar technique may be useful here, and
  indeed often is in recursive functions.  E.g. perhaps you'd like to write a
  function that knows how to handle numbers up to `999`, and then extend it to
  handle numbers up to `999999` by passing the first 3 digits to itself along
  with an argument that tells it to append the string `" thousand"`, and then
  passing the last 3 digits to itself along with an argument that tells it to
  append `""`; larger numbers could be handled similarly.

#### Magic Number

Ponder this:

```
1 is 3
3 is 5
5 is 4
4 is the magic number!

7 is 5
5 is 4
4 is the magic number!

13 is 8
8 is 5
5 is 4
4 is the magic number!
```

Why is 4 the magic number?  Is 4 always the magic number?

Once you figure it out, write a recursive function that generates the above
example given the following:

```c++
cout << magic_number(1) << endl;
cout << magic_number(7) << endl;
cout << magic_number(13) << endl;
```


### Style

- Place your solution in a `solution--YOURNAME` subdirectory, or in the base
  directory.

- Document and format your code well and consistently.
- Wrap lines at 79 or 80 columns whenever possible.
- End your file with a blank line.
- Do *not* use `using namespace std;`.  You may get around typing `std::` in
  front of things or with, e.g., `using std::cout;`.

- Include your copyright and license information at the top of every file,
  followed by a brief description of the file's contents, e.g.

  ```c++
  /* ----------------------------------------------------------------------------
   * Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>
   * Released under the [MIT License] (http://opensource.org/licenses/MIT)
   * ------------------------------------------------------------------------- */

  /**
   * A short program to print "Hello World!" to standard output.
   */
  ```


-------------------------------------------------------------------------------
[![Creative Commons License](https://i.creativecommons.org/l/by/4.0/88x31.png)]
(http://creativecommons.org/licenses/by/4.0/)  
Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>  
This work is licensed under a [Creative Commons Attribution 4.0 International
License] (http://creativecommons.org/licenses/by/4.0/)  
Project located at <https://github.com/2015-fall-csuf-benblazak-cpsc-121>

