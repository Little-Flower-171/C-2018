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

# TODO: other things

Note that the parameter is merely a variable; it does not differ from any other variable:

```C++
//buggy function
void incr(int x)
{
    ++x;
}
```

Suppose we use it like this:

```C++
int x = 5;
incr(x);
std::cout << x << "\n"; //unfortunately, x is still 5
```

If this had managed to increment `x`, what effect would `incr(1+1)` have had?
