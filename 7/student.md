# C++ Training Lesson 7 -- Arrays

## `std::vector`

Suppose you are asked to write a program that gets *n* numbers and prints them in inverse order.
In this situation, input-and-processing does not make sense anymore.
You just have no way but storing these numbers.
But since it is impossible to declare *n* variables, how to store them?

The answer is **to use `std::vector`**.

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
