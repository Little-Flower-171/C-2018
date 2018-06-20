# C++ Training Lesson 9 -- Errors

## Errors

When writing programs, errors are unavoidable. There are many kinds of errors:

- **Compile-time error**s: errors detected by the compiler, including:
    - Syntax errors;
    - Type errors.
- **Link-time error**s: errors detected by the linker.
- **Runtime error**s: errors occurred during execution, including:
    - Errors detected by the computer (hardware or operating system);
    - Errors detected by libraries (such as the standard library);
    - Errors detected by user's code.
- **Logic error**s: errors leading to incorrect results, detected by the programmer.

### Compile-time errors

The compiler is the first to detect errors.

For example, given the following function:

```C++
//calculates the reciprocal of x
double reciprocal(double x);
```

#### Syntax errors

What if we call it like this?

```C++
double s1 = reciprocal(7;   //error: ")" missing
double s2 = reciprocal(7)   //error: ";" missing
Double s3 = reciprocal(7);  //error: Double is not a type
double s4 = reciprocal('7); //error: "'" missing
```

Each line contains a syntax error, i.e. it does not follow the syntax rules of C++. Therefore, the compiler rejects them.

However, it is not always easy to understand the error report. The compiler typically scans for more information to determine the error. Hence, even a subtle error (something that you do not even believe you made it) leads to complicated report from the compiler; the compiler may also point to other lines of the program. You should check the preceding a few lines if you do not find any error on the line the compiler reports. Take `s3` for example. Instead of

> You misspelled `double`, the `d` should be in lower case

The compiler reports:

> 'Double' was not declared in this scope

Hopefully, you will soon get used to these reports. In fact, this "incomprehensible" information can be interpreted into:

> There is something wrong with 'Double'

It is not really difficult to find the problem.

#### Type errors

TODO

### Link-time errors

Suppose there is a program:

```C++
//calculates the area of rectangle
int area(int length, int width);

int main()
{
    int x = area(2, 3);
}
```

There is a link-time error -- the function is not defined.

### Runtime errors

```C++
int x = reciprocal(1);
int y = x-1;
int z = reciprocal(x);
```

A runtime error occurs since 
