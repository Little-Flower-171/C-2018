# C++ Training Lesson 11 -- Declarations and Definitions

A **declaration** brings a new name to a **scope**. It specifies a type for a named entity (variable, function, etc.) and optionally initializes it (e.g. specify a value for a variable or a function body for function).

```C++
int a = 7;             //an int variable
const double cd = 8.7; //a double constant
double sqrt(double);   //a function taking a double and returning a double
std::vector<Token> v;  //a vector of Token's
```

A C++ name must be declared before used (outside a class).

## Declarations and Definitions

A **definition** is a declaration that defines the entity. It actually creates the entity itself (a plain declaration only declares the name).

```C++
int a = 7;                      //definition
std::vector<double> v{1, 2, 3}; //definition
double square(double x)         //definition
{
    return x*x;
}

double sqrt(double);            //declaration
extern int e;                   //declaration

int b;                          //definition
std::string s;                  //definition
```

You can declare an entity zero or more times, but you must define an entity once and only once.

```C++
extern int x; //declaration
int x = 7;    //definition
extern int x; //definition

double square(double a);                //declaration
double square(double x) { return x*x; } //definition
double square(double d);                //declaration

int a = 7; //definition
int a;     //error: multiple definitions

double sqrt(double d) { /*...*/ } //definition
double sqrt(double d) { /*...*/ } //error: multiple definitions
                                  //even if they are exactly equivalent
```

## Declare a variable or constant

A variable or constant declaration specifies the name and the type, and optionally initializes.

```C++
int a;                           //no initialization
double d = 7;                    //initialize with =
std::vector<int> v1(10);         //initialize with ()
std::vector<int> v2{1, 2, 3, 4}; //initialize with {}
```

If we do not initialize:

- If the object does not have a default constructor (e.g. `int`), the value is undefined;
- If the object has a default constructor (e.g. `std::string`), it is called.

## Headers

A **header** is file of declarations which is later `#include`d in **source**s. For example, to provide a factorial library:

```C++
//factorial.hpp

//pre-conditions: x <= 20
//post-conditions: return value == x!
int factorial(int x);
```

```C++
//factorial.cpp

int factorial(int x)
{
    int res = 1;
    for (int i = 1; i <= x; ++i) {
        res *= i;
    }
    return res;
}
```

To use this library, put `factorial.hpp` at the same folder as `user.cpp`, and compile `user.cpp` together with `factorial.cpp`:

```C++
//user.cpp

#include "factorial.hpp"

int main()
{
    int x = factorial(5);
}
```

    <some-compiler> user.cpp factorial.cpp

*Why use `#include "..."` rather than `#include <...>`?*

## Scope

Every name is declared in a **scope**. It is valid from its declaration to the end of scope.

```C++
void f()
{
    g();       //error: g not in scope
}
void g()
{
    f();       //ok
}
void h()
{
    int x = y; //error: y not in scope
    int y = x; //ok
    g();       //ok
}
```

A name is also valid in a nested scope of its scope. For example, the call to `f` is in the scope of `g`, which is a nested scope of the global scope. The global scope is not nested within any other scope.

C++ supports multiple kinds of scopes:

- Global scope;
- Namespace scope;
- Class scope;
- Local scope;
- Statement scope.

## Namespace

We use functions to organize code. Classes enable us to group functions, data and types together. But we lack a technique to group names together into a recognizable named entity. The C++ counterpart grouping declarations is **namespace**. For example, suppose Little Flower defined a function `move` to move a shape:

```C++
//somewhere in <utility>
namespace std {
    //do not study the declaration of std::move
    template <typename T>
    std::remove_reference_t<T>&& move(T&& t) noexcept;
}

//somewhere in "LF.hpp"
namespace Little_Flower {
    //do not study the declaration of Little_Flower::move
    void move(Shape& shape, Direction dir, Distance dis);
}
```

The user may use these functions like this:

```C++
#include <utility>
#include <vector>
#include "LF.hpp"

//...

std::vector<int> v2 = std::move(v);

//...

Little_Flower::move(circle, north, 10);

//...

//Little_Flower is too long
namespace LF = Little_Flower;
LF::move(ellipse, south, 5);
```

### `using` declaration and `using` directive

```C++
std::set<std::string, std::greater<std::string>, std::allocator<std::string>> s;
std::unordered_set<std::vector<std::string>, std::hash<std::vector<std::string>>, std::equal_to<std::vector<std::string>>, std::allocator<std::vector<std::string>>> u;
```

`std::` appeared 18 times. We can use `using` declarations to simplify it:

```C++
using std::set;
using std::string;
using std::greater;
using std::allocator;
using std::unordered_set;
using std::vector;
using std::hash;
using std::equal_to;

set<string, greater<string>, allocator<string>> s;
unordered_set<vector<string>, hash<vector<string>>, equal_to<vector<string>>, allocator<vector<string>>> u;
```

We can also use a `using` directive:

```C++
using namespace std;

set<string, greater<string>, allocator<string>> s;
unordered_set<vector<string>, hash<vector<string>>, equal_to<vector<string>>, allocator<vector<string>>> u;
```

However, this can bring some problems. For example:

```C++
using namespace std;

set<string, greater<string>, allocator<string>> s;
unordered_set<vector<string>, hash<vector<string>>, equal_to<vector<string>>, allocator<vector<string>>> u;

//...

void f()
{
    move(circle, west, 4); //ouch!
}
```

We intended to call `LF::move`, but accidentally referred to `std::move`. Global `using` directives had better be avoided; local ones are better, but stays evil.
