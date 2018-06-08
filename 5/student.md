# C++ Training Lesson 5 -- Loop Input and I/O Errors

## I/O errors

Each stream object (`std::cout`, `std::cin`, `std::cerr`, or something created by you) holds an **I/O state** 
-- the stream status flag.  
It is an **attribute** of the object -- it can be **read** or **set**.

The state is of type ``std::ios_base::iostate``.  
There are several possible values of it:

Value | Explanation
--- | ---
``std::ios_base::goodbit`` | no error 
``std::ios_base::badbit`` | irrecoverable stream error 
``std::ios_base::failbit`` | input/output operation failed (formatting or extraction error) 
``std::ios_base::eofbit`` | associated input sequence has reached end-of-file 

It can be read by calling the function ``rdstate`` (short for **r**ea**d** **state**)
and set by calling the function ``setstate``:

```C++
std::ios_base::iostate s = std::cin.rdstate(); // s is the current state of std::cin
std::cin.setstate(std::ios_base::goodbit); // std::cin is now of state goodbit
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
compiles.)
