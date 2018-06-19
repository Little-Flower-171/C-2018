# C++ Training Lesson 8 -- Functions

## Functions

A function is a named sequence of **statement**s that optionally **return**s a result (called **return value**). The standard library provides a lot of useful functions (like `std::sqrt` and `std::move`), but we also need to write our own functions. For example:

```C++
int square(int x) //returns the square of x
{
    return x * x;
}
```

The function `square` takes one `int` **argument**, and returns an `int`. We can use this function like this:

```C++
std::cout << square(2) << "\n";     //outputs 4
int x = 233;
std::cout << square(x-200) << "\n"; //outputs 1089
```

We can choose whether to use the return value, but we have to provide the arguments properly:

```C++
square(2);              //possible warning: discarded return value
int v1 = square();      //error: argument missing
int v2 = square;        //error: parentheses missing
int v3 = square(1, 2);  //error: too many arguments
int v4 = square("two"); //error: "two" is a string, not an int
```

A **function body** is a **compound statement** that implements some specific function:

```C++
{
    return x * x;
}
```

The implementation of `square` is relatively simple -- it calculates the square of its argument and return the result.

The variable `x` is called a **parameter** or **formal argument**. In contrast, **argument** is the value provided during the call.

The following use of the function:

```C++
std::cout << square(1) << "\n";
```

can be understood like this:

```C++
//generated code
int x = 1;     //parameter initialized with argument
int ret = x*x; //function body

std::cout << ret << "\n";
```

A function may take no argument. It may also return nothing:

```C++
//no argument, no return value
void message()
{
    std::cout << "It was the creepers and skeletons
}
```

### Function declaration

All the information needed to call the function is shown in the first line of the definition. For example, according to

```C++
int square(int x)
```

we can call `square`:

```C++
int x = square(44);
```

We do not really need to know how `square` is implemented in order to call it. We merely need to know what arguments it takes and what it returns. C++ provides a way to show this information without specifying the function definition -- **function declaration**.

```C++
int square(int); //declare the function square
```

Note that the function declaration ends with a semicolon.

To use a function, declare it or `#include` the header containing its **prototype**, and the definition of the function can be placed anywhere else in the program. The separation of prototype and definition is essential to large programs -- we use prototypes to keep the code simple, so that we can concentrate on a specific part.

### Pass-by-value

Note that the parameter is merely a variable; it does not differ from any other variable:

```C++
//buggy function
void incr(int x)
{
    ++x;
}
```

This is called **pass-by-value**. Suppose we use it like this:

```C++
int x = 5;
incr(x);
std::cout << x << "\n"; //unfortunately, x is still 5
```

If this had managed to increment `x`, what effect would `incr(1+1)` have had?

(There are also ways to **pass-by-reference**. By now let's skip that.)

## Example

### 1. Factorial

You are providing a mathematical library and you find the following specification:

> ```
> long long fact(int x);
> ```
> *Requires:* `0 <= x && x <= 20`.
> *Returns:* the factorial of `x`.

Implement this function.

#### Program properties

- Program name: fact

#### Notes

You can assume the requisitions are met.

### 2. Input

TODO
