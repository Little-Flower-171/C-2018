# C++ Training Lesson 12 -- References and `constexpr`

## References

**Reference**s are a C++ feature that allows users to declare a (new) name for an *existing* object. For example:

```C++
int x = 5;
int& r = x;

r = 6; //x == 6 && r == 6
++x;   //x == 7 && r == 7
```

Any use of `r` can be replaced by `i`.

### Pass-by-value and pass-by-reference

Suppose we are implementing a function that exchanges the values of two `int`s:

```C++
//buggy function
void swap(int a, int b)
{
    int t = a;
    a = b;
    b = t;
}
```

```C++
int a = 10, b = 20;
swap(a, b);
std::cout << a << " " << b << "\n"; //unfortunately, a is still 10 and b is 20
```

When this function is called, the argument is used to initialize the parameter which is a plain local variable. The following code:

```C++
int x = 10, y = 20;
swap(x, y);
```
is equivalent to:
```C++
int x = 10, y = 20;
{
    int a = x, b = y;
    int t = a;
    a = b;
    b = t;
}
```

This is called **pass-by-value**. To resolve this bug, we can **pass-by-reference**:

```C++
//buggy function
void swap(int& a, int& b)
{
    int t = a; //why not int&?
    a = b;
    b = t;
}
```

### `const` references

Suppose we wrote a function to print a vector of `double`s:

```C++
//pass-by-value
void print(std::vector<double> v)
{
    //...
}
```

which is applicable for all sizes of `vector`s:

```C++
void f(int x)
{
    std::vector<double> vd1(10);
    std::vector<double> vd2(1000000);
    std::vector<double> vd3(x);

    //...

    print(vd1); //copies 10 doubles
    print(vd2); //copies 1000000 doubles
    print(vd3); //copies an unknown number of doubles
}
```

To resolve this problem, we can pass a `const` reference:

```C++
//pass-by-reference
void print(const std::vector<double>& v)
{
    //...
}
```

## `constexpr`

Sometimes we want to do a computation at compile-time. We need to use functions in **constant expression**s. `constexpr` serves for this purpose.

```C++
constexpr double pi = 3.14159265359;
constexpr double area(double r)
{
    return pi * r * r;
}

constexpr double r = 5;
constexpr double a = area(5);
```

Here, `a` = &pi;*r*<sup>2</sup> = 25&pi; &approx; 78.5398163398.

A `constexpr` function behaves the same as plain functions, except in constant expressions, under which situation the computation is done at compile-time or an error report is output. 

C++ requires that `constexpr` functions must be "simple enough" for (conforming) compilers to evaluate. C++11 requires the function body contain exactly one `return` statement (as per `area`); since C++14, "simple" iterations and selections are allowed. A `constexpr` function must not have any **side effect**s -- it must not modify variables outside its function body. If a compiler fails to tell that a `constexpr` function is "simple enough" (according to the detailed rules of C++), this function is ill-formed.

Word | Meaning | Pronunciation
--- | --- | ---
applicable | 适用的 | /əˈplɪkəbl; ˈæplɪkəbl/
computation | 计算 | BrE /ˌkɒmpjuˈteɪʃn/ AmE /ˌkɑːmpjuˈteɪʃn/
conforming | 符合标准的 | BrE /kənˈfɔːmɪŋ/ AmE /kənˈfɔːrmɪŋ/
