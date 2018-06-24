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




































