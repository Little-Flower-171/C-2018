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

After syntax errors are eliminated, the compiler starts to detect type errors.

```C++
double x0 = reciprocle(7);       //error: reciprocle not declared
double x1 = reciprocal(7, 2);    //error: too many arguments
double x2 = reciprocal("seven"); //error: types not match
```

Let's take a look at these errors:

1. `reciprocle(7)`: we misspelled the word `reciprocal`. Thus the compiler thinks that we want to call the function `reciprocle`. (Does the compiler have other "ideas"? No. It does not know what you really want to do.)
    - If there is no function `reciprocle`, you get an error that `reciprocle` is not defined;
    - If there is a function `reciprocle` and it accepts 7 as argument, you are in trouble -- the program compiles, but it does not produce desirable result. This is a more advanced error.
2. `reciprocal(7, 2)`: a wrong number of arguments are provided. According to the rules of C++, you must provide arguments of the right number, types, and order.
3. `reciprocal("seven")`: you may expect the compiler to recognize `seven` as 7, but it does not. We must not provide a string if a function expects a `int`. Remind that the compiler will not try to guess your intention. If it had tried, what do you think `reciprocal("7")` or `reciprocal("Minecraft")` means?

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

At the same time, the definition must be of consistent types with the declaration:

```C++
//calculates the area of rectangle
int area(int length, int width);

int main()
{
    int x = area(2, 3);
}

//calculates the area of rectangle
double area(double x, double y) //not "our" area
{
    return x * y;
}
```

### Runtime errors

If your program does not contain any compile-time or link-time errors, it executes. Now the fun really starts -- nobody can help you with runtime errors. It may be difficult to determine the error. For example:

```C++
double x = reciprocal(1);
double y = reciprocal(x)-1;
double z = reciprocal(y);
```

Let's take a look at the initialization of `z`. There does not seem to be any errors. But can you find what is wrong?

These errors may happen if you or your clients do not find and resolve them soon enough. Most people are sensitive to these "fatal" errors, since they do not know the very details but merely "something went wrong". This information does not help much in resolving the problem. Hence, people become angry and keep complaining about the provider of the program all the time.

Back to the code, we find that the error is due to **invalid argument**s. We have two solutions:

- Let the user of `reciprocal` handle invalid arguments;
- Let `reciprocal` itself handle invalid arguments.

In fact, the more general case is: the pre-condition is not met.

#### Let the caller handle

If `reciprocal` is provided by a library which we cannot access, this solution is taken.

It is quite easy to protect the call `reciprocal(y)`:

```C++
if (y == 0) /*report error*/;
double z = reciprocal(y);
```

(By now let's skip how to report the error.)

However, the code becomes awkward if we protect all the calls:

```C++
if (1 == 0) /*report error*/;
double x = reciprocal(1);
if (x == 0) /*report error*/;
double y = reciprocal(x)-1;
if (y == 0) /*report error*/;
double z = reciprocal(y);
```

We can move the check to the function `reciprocal`.

#### Let the function handle

It is easy to check the argument inside the function `reciprocal`:

```C++
double reciprocal(double x)
{
    if (x == 0) /*report error*/;
    return 1/x;
}
```

We no longer need to check the argument every time we call `reciprocal`. But why do people not always check the arguments in their functions?

- We cannot edit the function;
- The function does not know how to handle the error;
- The function does not know when it is called;
- Doing so leads to inefficiency.

However, you are suggested to check the arguments inside your function unless you have sufficient reasons.

## Report the error

How to report the error? Apparently simply `/*report error*/` is undesirable.

C++ provides an error-handling mechanism: **exception**.

In order that the error detected not be unintentionally discarded, **exception**s are designed to seperate error detection (by the function) and error handling (by the caller). Errors are annoying, but exceptions make them easier to deal with.

The basic idea of exceptions is: if a function detects an error that cannot be handled by itself, it does not **return** normally but **throw**s an exception to indicate the error; any (direct or indirect) caller can **catch** the exception and handle it.

### Invalid arguments

```C++
//a special class to report the error
class Div_by_zero {};

//calculates the reciprocal of x
double reciprocal(double x)
{
    if (x == 0)
        throw Div_by_zero{};
    return 1/x;
}

int main()
try {
    double x = reciprocal(1);
    double y = reciprocal(x)-1;
    double z = reciprocal(y);
} catch (Div_by_zero) {
    std::cerr << "Error: attempting to calculate 1/0\n";
    return 1; //returning a non-zero number indicates error
}
```

If `x != 0`, we calculate the reciprocal and return it; otherwise, we exit the function `reciprocal` and throw an exception. The exception is caught and handled in the `main` function.

`Div_by_zero` is a new type defined by ourselves. `Div_by_zero{}` stands for "create an object of type `Div_by_zero` according to the default." Therefore, `throw Div_by_zero{}` means: create a `Div_by_zero` object and throw it.

If the caller cannot handle the error either, it can choose not to catch the exception. Hence, the exception seeks for further handling. For example:

```C++
//calculates the average speed to travel the same distance at the speed of x and y
double average_speed(double x, double y)
{
    double xtime = reciprocal(x);
    double ytime = reciprocal(y);
    return reciprocal(xtime + ytime);
}
```

### Range errors

TODO
