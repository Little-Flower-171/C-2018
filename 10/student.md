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
    Date(int y, int m, int d); //check validity of date and initialize
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

However, a problem is still unresolved -- what if someone forgets to use `add_day()`? What if someone decides to modify the month directly? After all, we "forgot" to provide these features:

```C++
Date birthday{1960, 12, 31};
++birthday.d;                //invalid date

Date today{1970, 2, 3};
today.m = 14;                //invalid date
```

As long as we expose the implementation details to the user, someone (intentionally or accidently) messes things up -- they create invalid dates. Such invalid objects become time-bombs -- they lead to runtime errors or logic errors. Therefore, the implementation details of `Date` should be inaccessible by the user, except via public functions. We improve the class:

```C++
//simple Date class (with control over access)
class Date {
    int y, m, d;               //year, month, day
public:
    Date(int y, int m, int d); //checks validity and initialize
    void add_day(int n);       //add n days to date
    int month() { return m; }
    int day  () { return d; }
    int year () { return y; }
};
```

To use it:

```C++
Date birthday{1970, 12, 30};
birthday.m = 14;
std::cout << birthday.month() << "\n"; //we provide read-only access to m
```

"Valid date" is a special case of **valid value** or **valid state**. We should try to keep the object valid when we design a type -- we hide the representation, provide a constructor that creates valid objects, and the design of all member functions follow the pattern of "accepting valid objects and generating valid objects."

The rule used to judge validity is called **invariant**. If we cannot specify a variant, we may have to deal with plain data, in which case, `struct` can be used.

### Defining member functions

We have already studied `Date`, both from the view of an interface-designer and a user. However, we have to implement them sooner or later. First, we reorganize the `Date` class declaration, in which, following the most common style, we place the public interface at the top:

```C++
//simple Date class (some people are used to putting the implementation details at the end)
class Date {
public:
    Date(int y, int m, int d); //constructor: checks validity and initialize
    void add_day(int n);       //add n days to the date
    int month();
    //...
private:
    int y, m, d;               //year, month, day
};
```

The reason why people prefer placing the public interface at the top is that most people are more interested in interface. Theoretically, users need not know the implementation details of the class; they merely learn the interface. The compiler does not care the order of functions and data members; any order is okay.

When we are defining a member out of class, we need to tell of which class the member is. This can be done with the **scope resolution operator** `::`:

```C++
Date::Date(int yy, int mm, int dd) //constructor
    :y{yy}, m{mm}, d{dd}           //initialize the members
{
}

void Date::add_day(int n)
{
    //...
}

int month()   //ouch -- "Date::" missing
{
    return m; //error: m is not declared in this scope
}
```

`:y{yy}, m{mm}, d{dd}` is the syntax for member initialization, called **member initializer list**. You can also write like this:

```C++
Date::Date(int yy, int mm, int dd)
{
    y = yy;
    m = mm;
    d = dd;
}
```

However, in principle, the latter first default-initializes the members, and then assigns to them. The difference between these two fragments is similar to that between

```C++
int x;    //define x first
//...
x = 2;    //then assign to it
```

and 

```C++
int x{2}; //define and initialize to 2
```

We can also define the member functions inside the class:

```C++
//simple Date class (some people are used to putting the implementation details at the end)
class Date {
public:
    Date(int yy, int mm, int dd)
        :y{yy}, m{mm}, d{dd}
    {
        //...
    }
    void add_day(int n)
    {
        //...
    }
    int month() { return m; }
    //...
private:
    int y, m, d; //year, month, day
};
```

This makes the class declaration large and "messy". Moreover, this does not put emphasis on interface but rather implementation details. Therefore, we should avoid defining long functions inside the class declaration. However, simple and short functions like `month()` are better to be put inside the class declaration. In-class functions are automatically inline.

Note that `month()` can access `m` which is declared after it. The rule "a name must be declared before used" can be compromised in a class.

## Enumerations

Enumerations are a very simple kind of user-defined type that specifies a set of values denoted by **enumerator**s. For example:

```C++
enum class Month {
    jan = 1, feb, mar, apr, may, jun,
    jul    , aug, sep, oct, nov, dec
};
```

The "body" of the enumeration definition is simply a list of enumerators. We can access these enumerators with the scope resolution operator `::`.

You can specify a value for an enumerator or not. If you do not, its value is the previous enumerator plus 1. Hence, the definition is identical to:

```C++
enum class Month {
    jan = 1, feb = 2, mar = 3, apr = 4 , may = 5 , jun = 6 ,
    jul = 7, aug = 8, sep = 9, oct = 10, nov = 11, dec = 12
};
```

However, not only is the latter verbose but we are also likely to make mistakes. Apparently the compiler is better at such work.

By default, the first enumerator has value 0:

```C++
enum class Day {
    sunday, monday, tuesday, wednesday, thursday, friday, saturday
};
```

Here, the values of `Day::sunday` to `Day::saturday` are 0 to 6, respectively.

To use `Month`:

```C++
Month m = Month::feb;

Month m2 = feb;         //error: feb is not declared in this scope
m = 7;                  //error: cannot assign int to Month
int n = m;              //error: cannot assign Month to int

Month a = Month(7);     //ok: a == Month::jul
Month b = Month{7};     //ok: a == Month::jul since C++17
                        //compile-time error before C++17
Month aa = Month(7777); //ok: you are responsible for your own action
Month bb = Month{7777}; //compile-time error

//ditto
Month c(7);
Month d{7};
Month cc(7777);
Month dd{7777};

Month x = 7;            //compile-time error
Month y = {7};          //compile-time error
```

We can explicitly convert a `Month` to an `int`:

```C++
int a = int(Month::jan);              //ok: explicit cast
int b = static_cast<int>(Month::jan); //ok: very explicit cast
```

Or convert an `int` to a `Month`:

```C++
Month c = Month(1);              //ok: explicit cast
Month d = static_cast<Month>(1); //ok: very explicit cast
```

## Operator overloading

You can define almost all C++ operators on classes and enumerations. This is usually called **operator overloading**. With this mechanism, you can provide conventional expressions for user-defined types. For example, we can define an output operator for `Month`:

```C++
//special class to report error
struct Invalid_month {
    Month m;
};

std::ostream& operator<<(std::ostream& os, Month m)
{
    switch (m) {
    case Month::jan: os << "January"  ; break;
    case Month::feb: os << "February" ; break;
    case Month::mar: os << "March"    ; break;
    case Month::apr: os << "April"    ; break;
    case Month::may: os << "May"      ; break;
    case Month::jun: os << "June"     ; break;
    case Month::jul: os << "July"     ; break;
    case Month::aug: os << "August"   ; break;
    case Month::sep: os << "September"; break;
    case Month::oct: os << "October"  ; break;
    case Month::nov: os << "November" ; break;
    case Month::dec: os << "December" ; break;
    default: throw Invalid_month{m}; //throw an exception that contains the invalid month
    }
    return os; //for chaining
}
```

*Why do we accept a `std::ostream&` as first parameter and return a `std::ostream`?*

You can define almost all C++ operators -- `+`, `-`, `*`, `/`, `%`, `[]`, `()`, `^`, `!`, `&`, `<`, `<=`, `>`, `>=`, etc. You cannot define new operators like `**` or `$=`. And you must accept an adequate number of operands. You can define a unary `-` or a binary `+`, but cannot define a unary `<=` or a binary `!`.

An overloaded operator must operate on at least one user-defined-type object:

```C++
int operator+(int, int);               //error: cannot modify the language itself
Vec operator+(const Vec&, const Vec&); //ok
Vec operator+(const Vec&, int);        //ok
```

Overloaded operators should keep their original meaning -- `+` for addition, `*` for multiplication, `[]` for element access, `()` for application, etc. However, this is only advice; it is not a C++ rule.

Surprisingly, instead of `+`, `-`, `*` and `/`, the most frequently-overloaded operators are `=`, `==`, `!=`, `<`, `[]` and `()`.

## Class interface



































