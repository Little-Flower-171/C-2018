# C++ Training Lesson 5 -- Loop Input and I/O Errors

## I/O errors

Each stream object (`std::cout`, `std::cin`, `std::cerr`, or something created by you) holds an **I/O state** 
-- the stream status flag.  
It is an **attribute** of the object -- it can be **read** or **set**.

The state is of type ``std::ios_base::iostate``.  
There are several possible values of it:

Value | Explanation
--- | ---
``std::ios_base::goodbit`` | no error (the default)
``std::ios_base::badbit`` | irrecoverable stream error
``std::ios_base::failbit`` | input/output operation failed (formatting or extraction error)
``std::ios_base::eofbit`` | associated input sequence has reached end-of-file

*What is end-of-file (EOF)?*

When ``eofbit`` is set, ``failbit`` is set together;
however, when ``failbit`` is set, ``eofbit`` does not have to be set together.

It can be read by calling the function ``rdstate`` (short for **r**ea**d** **state**)
and set by calling the function ``setstate``:

```C++
std::ios_base::iostate s = std::cin.rdstate(); // s is the current state of std::cin
std::cin.setstate(std::ios_base::goodbit); // std::cin is now of state goodbit
```

``std::ios_base::iostate`` can be used in `switch`:

```C++
switch (std::cin.rdstate()) {
case std::ios_base::goodbit:
    std::cout << "Nothing happened.\n"; break;
case std::ios_base::badbit:
    std::cout << "Something SERIOUSLY went wrong.\n"; break;
case std::ios_base::eofbit:
    std::cout << "There is nothing to extract.\n"; break;
case std::ios_base::failbit:
    std::cout << "Something went wrong.\n"; break;
}
```

There are also some convenience functions:

```C++
if ( std::cin.good() ) // true if std::cin.rdstate() == std::ios_base::goodbit
    /*...*/;
if ( std::cin.eof()  ) // true if std::cin encountered EOF
    /*...*/;
if ( std::cin.fail() ) // true if std::cin encountered an error (failbit or badbit is set)
    /*...*/;
if ( std::cin.bad()  ) // true if std::cin encountered an irrecoverable error (badbit is set)
    /*...*/;
if (  std::cin )       // identical to std::cin.good()
    /*...*/;
if ( !std::cin )       // identical to std::cin.fail()
    /*...*/;

std::cin.clear(); // identical to std::cin.setstate(std::ios_base::goodbit);
```

(Note: You many think preceding everything with ``std::ios_base::`` is verbose,
but you cannot use a `using`-directive
since ``ios_base`` is not a namespace, and neither nonsense like
```C++
using namespace std::ios_base; // error: ios_base is not a namespace
```
nor
```C++
using namespace std;      // works
using namespace ios_base; // error: ios_base is not a namespace
```
compiles. Also, as you will know, there are far more longer names.)

Each object has a separate state.
For example, after ``std::cin`` met something wrong, you can still use ``std::cout`` normally;
after ``std::cout`` failed to output, you can still use ``std::cerr`` to report error,
which is far less likely to fail.

If the state of it is not ``goodbit``, **any I/O operation on one stream becomes a no-op.**
Don't get trapped by this!

### ``failbit``

``failbit`` is set by operators ``<<`` and ``>>`` to indicate format error:

```C++
std::cout << "Hello, how old are you? ";
int age;
std::cin >> age;
```

Executing: (input is marked **bold**)

``Hello, how old are you?``**``That is my privacy!``**

Trying to extract an integer,
`std::cin` saw `T` and set `failbit`.

{{TODO}}
