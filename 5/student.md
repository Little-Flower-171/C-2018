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

`std::ios_base::iostate` is a **bitmask** type. *What is a bitmask type?*

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

If the state of it is not ``goodbit``, **any I/O operation on one stream is directly ignored.**
Don't get trapped by this!

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

`badbit` is set to indicate irrecoverable serious errors.

`eofbit` is set when EOF is reached:

```C++
std::cout << "Enter an integer: ";
int a;
std::cin >> a;
```

Executing: (input is marked **bold**)

`Enter an integer: `**`<EOF>`**

Trying to extract an integer,
`std::cin` saw EOF and set both `eofbit` and `failbit`.

## Loop input

### Issue 1

Given an article as input,
count the number of alphanumerics, spaces, punctuations and line feeds
(there are no other characters.)

We can iterate to read in every character and analyze it,
until EOF is reached. We do it like this (wrong:)

```C++
#include <iostream>
#include <cctype> // what is this?

int main()
{
    char c;
    int alnum = 0, space = 0, punct = 0, line_feed = 0;
    while (std::cin.good()) {
        std::cin >> c;
             if (c == '\n')       ++line_feed;
        else if (c == ' ' )       ++space;
        else if (std::isalnum(c)) ++alnum;
        else if (std::ispunct(c)) ++punct;
    }
    std::cout << alnum << " alphanumerics, "
              << space << " spaces, "
              << punct << " punctations, and "
              << line_feed << " line feeds\n";
}
```

Unfortunately, this does not work properly.
*What's wrong? How to fix?*

In fact, we usually write like this:

```C++
#include <iostream>
#include <cctype>

int main()
{
    int alnum = 0, space = 0, punct = 0, line_feed = 0;
    for (char c; std::cin.get(c);) { //what does it mean?
             if (c == '\n')       ++line_feed;
        else if (c == ' ' )       ++space;
        else if (std::isalnum(c)) ++alnum;
        else if (std::ispunct(c)) ++punct;
    }
    std::cout << alnum << " alphanumerics, "
              << space << " spaces, "
              << punct << " punctations, and "
              << line_feed << " line feeds\n";
}
```

### Issue 2

Given a number of data, read as many integers
(within the range of `int`)
as possible.
Then output the largest among them.
For example, given input

```
1 9 2 8 3 7 4 6 9.56 40
```

Output should be `9` (neither `9.56` nor `40`.)

Note that we can read until `std::cin.fail()`.

We can write like this:

```C++
#include <iostream>
#include <limits> //what is this?

int main()
{
    int max = std::numeric_limits<int>::min(); //why is max initially set to the minimum possible value?
    for (int x; std::cin >> x;) {
        if (x > max) max = x;
    }
    std::cout << "The maximum among these numbers is " << max << ".\n";
}
```

## Examples

### 1. Minceraft v2.0

[Minceraft](https://github.com/Little-Flower-171/C-2018/blob/master/4/student.md#2-virus-infected)
has been updated to v2.0.

Update log:

- It can process full text.
- In addition to replacing every lower-case vowel letter by a "x",
  it replaces every upper-case vowel letter by a "X".
- After doctoring, it reports how many letters it has replaced.

#### Program properties

- Program name: virus2
- Time limit: 1 second
- Memory limit: 512 megabytes

#### Input format

Text consisting of alphanumerics, spaces, punctations and line feeds.

#### Output format

Text doctored by Minceraft 2.0,
followed by statistics of the format

`X rxplxcxd `*`n`*` vxwxl lxttxrs wxth x "x".`

The statistical text itself is not considered doctored.

#### Sample input

```
I used to rule the world,
Chunks would load when I gave the world.
Now every night I go stow away,
Hide from the mobs I used to slay.
```

#### Sample output

```
X xsxd tx rxlx thx wxrld,
Chxnks wxxld lxxd whxn X gxvx thx wxrld.
Nxw xvxry nxght X gx stxw xwxy,
Hxdx frxm thx mxbs X xsxd tx slxy.
X rxplxcxd 38 vxwxl lxttxrs wxth x "x".
```

### 2. Square roots

Write a program that repeatedly calculates the square roots of given numbers.

#### Program properties

- Program name: sqrt
- Time limit: 1 second
- Memory limit: 512 megabytes

#### I/O format

Prompt `Number: ` and input a decimal (representable by `double`,)
give its principal square root (need not be very accurate.)
If input is negative or is of wrong format,
ignore the **whole line** and prompt again.
Process until EOF is reached.

#### Sample I/O

```
Number: 256
Square root: 16
Number: 2
Square root: 1.41421
Number: -256
Imaginary numbers are not supported.
Number: 0
Square root: 0
Number: two hundred and fifty-six
This is not a number.
Number: <EOF>
Bye.
```

#### Hint

The *standard library* provides a function `sqrt`. `#include <cmath>` to access it.

## Words

Word | Meaning | Pronunciation
--- | --- | ---
error | 错误 | /ˈerə(r)/
state | 状态 | /steɪt/
status | 状态 | /ˈsteɪtəs/ AmE also /ˈstætəs/
flag | 信号 | /flæɡ/
attribute | 属性 | /ˈætrɪbjuːt/
recover | 恢复 | /rɪˈkʌvə(r)/
bitmask | 位掩码 | BrE /bɪt mɑːsk/ AmE /bɪt mæsk/
call | 调用 | /kɔːl/
directive | 指示 | /dəˈrektɪv; dɪˈrektɪv; daɪˈrektɪv/
compile | 编译 | /kəmˈpaɪl/
separate | adj. 单独的 | /ˈseprət/
indicate | 指示 | /ˈɪndɪkeɪt/
punctuation | 标点 | /ˌpʌŋktʃuˈeɪʃn/
iterate | 迭代 | /ˈɪtəreɪt/
process | 处理 | BrE /ˈprəʊses/ AmE /ˈprɑːses; ˈproʊses/
statistics | 统计资料 | /stəˈtɪstɪks/
represent | 表示 | /ˌreprɪˈzent/
accurate | 精确的 | /ˈækjərət/
