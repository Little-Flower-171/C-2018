# C++ Training Lesson 7 -- Arrays

## Issue

Write a program that prints a sequence of decimals in reverse order.

### Sample input

```
1.41 2.72 3.14
```

### Sample output

```
3.14 2.72 1.41
```

In this situation, input-and-processing does not make sense anymore.
You just have no way but storing these numbers.
But since it is impossible to declare *n* variables, how to store them?

## `std::vector`

`std::vector` is a **template** (neither a type nor an object) provided by the standard library.
It encapsulates **dynamic-size array**s.

In the context of C++,
an **array** is a **container** that stores *n* **homogeneous** **element**s,
**index**ed from 0 to *n*-1,
where *n* is called the **size** of the array.

A **static-size array** is one whose size is known at compile time;
by contrast, a **dynamic-size array** is one whose size is known at run time.

`std::vector` can be expanded and contracted; i.e. its size can be modified.

(Note: there are other ways to store an array in C++; by now let's skip that.)

`std::vector` is quite different from other types provided by the standard library (such as `std::string`),
since it is a **template**, i.e. you can provide **arguments** in order to generate types.
Template arguments are specified in angle brackets.

`std::vector` accepts one **type** as template argument.
The type can be anything, such as `int`, `std::string`, or `std::vector<int>`.
For example, `std::vector<double>` is an array of `double`s.

(Note: `std::vector` optionally accepts a second argument; by now let's skip that.)

## Back to the issue

```C++
#include <iostream>
#include <vector> //for std::vector

int main()
{
    std::vector<double> numbers; //numbers is initially empty
    for (double x; std::cin >> x;) {
        numbers.push_back(x);
    }

    for (int i = numbers.size(); i--;) { //?
        std::cout << numbers[i] << " ";
    }
}
```














