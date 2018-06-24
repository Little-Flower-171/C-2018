# C++ Training Lesson 10 -- Classes

## User-defined types

C++ provides a number of **built-in** types: `char`, `int`, `double`, etc. The programmer need not provide any declarations and the compiler knows about these types.

Non-built-in types are called **user-defined** types. This includes standard-library types (`std::string`, `std::vector`, `std::ostream`, etc.) and types created by ourselves (e.g. `Div_by_zero`). Like built-in types, many user-defined types support operations -- `std::vector` has `[]` and `size()`, `std::istream` has `>>` and `get()`... Standard-library types can be regarded as part of language, but they are usually classified into user-defined types, since they use the same language features and technologies that we use; *the creators of the standard library do not have any privileges.*

A type provides two aspects of help:

- **Representation**: a type "knows" how to represent the object's data;
- **Operation**: a type "knows" what operations can be performed on the object.

## Coding

Hence, we want to represent such ideas as a **data structure** and some **function**s. How to express it precisely?

C++ provides two kinds of user-defined types: **class**es and **enumeration**s. So far, classes are the most widely-used and the most important mechanism to describe a concept. A class is a (user-defined) type that specifies how objects of that type are represented, created, used, and destroyed. You probably should define a class for something if you consider it as an entity.

## Classes and members

A class consists of zero or more **member**s:

```C++
class X {
public:
    int m;        //member object
    int mf(int v) //member function 
    {
        int old = m;
        m = v;
        return old;
    }
};
```

A member is accessed with the dot operator (`.`):

```C++
X var;             //var is a variable of type X
var.m = 7;         //assign to the member m of var
int x = var.mf(9); //call the member function mf() of var
```

The type of a member determines the operations we can make on it. For example, we can read/write an `int` member, and we can call a member function.

Inside a member function, it is not necessary to use the dot operator; it can directly use the member's name, which means the corresponding member of the object that called the function. Thus, with respect to `var.mf(9)`, the `m` inside the definition of `mf` stands for `var.m`.

## Interface and implementation

We usually regard a class as **interface** and **implementation**. The interface is one part of the class declaration, which can be directly accessed by the user; the implementation is another part that can only be accessed indirectly via the interface. Hence, a class declaration is like this:

```C++
class X { //the class's name is X
public:
    //interface (can be accessed by anyone)
        //functions, types, data...
private:
    //implementation (can only be accessed by the class itself)
        //functions, types, data...
};
```

Class members are private by default -- the following code

```C++
class X {
    int mf(int);
};
```

is identical to

```C++
class X {
private:
    int mf(int);
};
```

Therefore, the following code is erroneous:

```C++
X x;             //variable x of type X
int y = x.mf(2); //error: mf is private
```

If a class consists only of data, there is no difference between interface and implementation. C++ provides a feature to simplify these classes -- **structure**. A structure is a class whose members are public by default:

```C++
struct X {
    int m;
};
```

is identical to

```C++
class X {
public:
    int m;
};
```

## Evolve a class

How to express dates (like 1954-08-14) in a C++ program?

### Structure and function

> How about year, month, day?

That is not the only answer, nor is it always the best answer, but for now it is enough. The first proposal is a simple structure:

```C++
//simple structure Date
struct Date {
    int y; //year
    int m; //month
    int d; //day
};

Date one_day; //a Date variable (named object)
```

A Date object (like `one_day`) consists of three `int` members: `y`, `m`, and `d`. The `Date` structure does not implicitly relate to any other data structure, nor can it do "magic".

What operations can we perform on it? Actually, we can do *any* operations, since we can access `Date` objects' members, and read/write them as we want. The difficulty is that this is not really convenient -- every time we want to do something with `Date` objects,  we have to read/write their members:

```C++
//set one_day to 2005-12-24
one_day.y = 2005;
one_day.d = 12;
one_day.m = 24;
```

This is verbose and likely to contain errors. Can you find out what is wrong?

Moreover, does the following make sense?

```C++
Date x;
x.y = -3;
x.m = 13;
x.d = 32;
```

What about this?

```C++
Date y;
y.y = 1900;
y.m = 2;
y.d = 29;
```

The latter seems to be much more meaningful than the former. But is 1900 a leap year? Are you sure?

A better approach is to design some **helper function**s to do some common operations for us. Hence, we do not repeat ourselves, nor do we make the same mistakes and keep searching for and resolving them. For almost any type, initialization and assignment are common operations. For `Date`, increment is another. Therefore, we write the following helper functions:

```C++
void init_day(Date& dd, int y, int m, int d)
{
    //checks whether (y, m, d) is a valid date
    //if it is, initialize dd with it
}
void add_day(Date& dd, int n)
{
    //add n days to dd
}
```

Try them:

```C++
void f()
{
    Date today;
    init_day(today, 12, 24, 2005); //ouch! (we wrote the date in wrong order)
    add_day(today, 1);
}
```

These operations (implemented as helper functions here) are useful. If we do not write a program once and for all, date-checking will be difficult and boring -- we may forget to check the date and thus get a buggy program. Every time we define a type, we need some operations on it. The number and kind of operation(s) depend on the type. So does the way we provide them (function, member function or operator). Nevertheless, if we decide to define a type, we should think of:

> What operations will we design for the type?

### Member function and constructor

We designed an initialization function for `Date`, which provides the date-checking feature. However, it is of no use without being used properly. For example, assuming we have defined the output operator `<<` for `Date` (by now let's skip how to):

```C++
void f()
{
    Date today;
    //...
    std::cout << today << "\n";   //use today
    //...
    init_day(today, 2008, 3, 31);
    //...
    Date tomorrow;
    tomorrow.y = today.y;
    tomorrow.m = today.m;
    tomorrow.d = today.d+1;       //add 1 day to today
    std::cout << tomorrow << "\n";
}
```

We forgot to immediately initialize `today` after we had constructed it, and "someone" used it before initialization. And "someone" thinks calling `add_day()` is a waste of time, or maybe he never heard about the function at all. Therefore, he constructed `tomorrow` by hand instead of calling `add_day()`. This program becomes buggy -- and the bug is *very* serious. For example, an uninitialized `Date` may lead to garbage output, and simply adding 1 to `d` becomes time bomb -- it effects an invalid date if `today` is the last day of the month. The most serious problem is that there does not seem to be any problems.

This fact urges us to look for better approaches -- we need an initialization function that *cannot* be forgotten by the programmer, and an operation unlikely to be neglected. We can use member functions:

```C++
//simple structure Date
//ensures initialization via constructor
//provides some convenience
struct Date {
    int y, m, d;               //year, month, day
    Date(int y, int m, int d); //check validation of date and initialize
    void add_day(int n);       //add n days to the date
};
```

The function `Date` is a **constructor** -- a special member function to initialize ("construct") the object. If a class's constructor requires arguments, then we have to provide them; if we forget, the compiler detects the error. C++ provides a special and convenient way to initialize:

```C++
Date my_birthday;                    //error: my_birthday not initialized
Date today{12, 24, 2007};            //runtime error
Date last{2000, 12, 31};             //correct
Date next = {2014, 2, 14};           //correct (long-winded)
Date christmas = Date{1976, 12, 24}; //correct (verbose style)
```

To use them:

```C++
last.add_day(1);
add_day(2);      //error: which date?
```

We must call a member function on a specific object with the dot operator `.`.

### Keep details private
