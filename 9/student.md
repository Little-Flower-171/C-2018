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

The compiler is the first to detect errors. For example, given the following function:

```C++
//calculates a rectangle's area
int area(int length, int width);
```

#### Syntax errors

What happens if we call `area` like this:

```C++
int s1 = area(7;   //error: ")" missing
int s2 = area(7)   //error: ";" missing
Int s3 = area(7);  //error: Int is not a type
int s4 = area('7); //error: "'" missing
```

Every line has a syntax error, i.e. they do not follow the syntactic rules of C++. Therefore, the compiler rejects them.
