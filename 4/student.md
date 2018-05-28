# C++ Training Lesson 4 -- Iteration and Selection

## Iteration

If you are asked to print the integers 1 to 10, each in a line,
you may do this:

```C++
std::cout << "1\n2\n\3n4\n5\n6\n7\n8\n9\n10\n";
```

Obviously, it is verbose.
Moreover, what if 1 to 100?
What if the number is input by the user?  
Apparently, a better way has to be used.

### `for` loops

Consider printing the numbers 1 to 10:

```C++
for (int i = 1; i <= 10; ++i) {
    std::cout << i << "\n";
}
```

It has the safe effect as:

```C++
int i = 1;
std::cout << i << "\n"; // i == 1
++i;
std::cout << i << "\n"; // i == 2
++i;
std::cout << i << "\n"; // i == 3
++i;
/*...*/
std::cout << i << "\n"; // i == 10
++i;
//now i == 11, no longer i <= 10, quit
```

To print the numbers 1 to *n* where *n* is input by the user:

```C++
int n;
std::cin >> n;

for (int i = 1; i <= n; ++i) {
    std::cout << i << "\n";
}
```

The aforementioned `for` loop works like this:

![for](https://github.com/Little-Flower-171/C-2018/blob/master/for.png)

*What do the following `for` loops print?*

```C++
for (int i = 0; i < n; ++i) {
    std::cout << i << "\n";
}
```

```C++
for (int i = 0; i < n; i += 2) {
    std::cout << i << "\n";
}
```

```C++
for (int i = n; --i > 0; ) {
    std::cout << i << "\n";
}
```

```C++
for (int i = 0; ; ++i) {
    std::cout << i << "\n";
}
```

```C++
for (int i; std::cin >> i; ) {
    std::cout << i << "\n";
}
```

There is also another form of `for` loop: **range-based `for` loops** since **C++11**. By now let's skip that.

### `while` loops and `do` loops

There are another two kinds of loops.  
Now let's print 1 to 10 with these two kinds of loops.

```C++
int i = 1;
while (i <= 10) {
    std::cout << i << "\n";
    ++i;
}
```

```C++
int i = 1;
do {
    std::cout << i << "\n";
    ++i;
} while (i <= 10); //note: here is a semicolon
```

The difference between a `while` loop and a `do` loop is that,
the former checks the condition before executing the first time,
while the latter does not.

## Selections

Now you are facing another issue -- the user inputs an integer from 1 to 5 and you output a word from `one` to `five`.

### `if` selections

```C++
int n; std::cin >> n;
     if (n == 1) std::cout << "one\n";
else if (n == 2) std::cout << "two\n";
else if (n == 3) std::cout << "three\n";
else if (n == 4) std::cout << "four\n";
else if (n == 5) std::cout << "five\n";
```

Note that if `n` is not 1 to 5, *none of the branches will be executed*.

The simplest form of `if` selection is:

```C++
if (/*...*/) {
    /*...*/
}
```

In case the condition is not met, *no code is executed*.

If, additionally, you output "???" in case the integer input is not 1 to 5,
you can do this:

```C++
     if (n == 1) std::cout << "one\n";
else if (n == 2) std::cout << "two\n";
/*...*/
else if (n == 5) std::cout << "five\n";
else             std::cout << "???\n";
```

In this case, the final branch will be executed
if `n` is not 1 to 5.

### `switch` selections

You can also code like this:

```C++
switch (n) {
case 1 : std::cout << "one\n"  ; break;
case 2 : std::cout << "two\n"  ; break;
case 3 : std::cout << "three\n"; break;
case 4 : std::cout << "four\n" ; break;
case 5 : std::cout << "five\n" ; break;
default: std::cout << "???\n"  ;
}
```

The `default` can be 

If you do not `break;` after a `case`,
the next `case` will then be executed after the current `case`.  
For example, consider printing
`small` for 1 to 5,
`large` for 6 to 10,
`???` for others:

```C++
switch (n) {
case 1: case 2: case 3: case 4: case 5:
    std::cout << "small\n";
    break;
case 6: case 7: case 8: case 9: case 10:
    std::cout << "large\n";
    break;
default:
    std::cout << "???\n";
}
```

Notes:
* `switch` can only be used to test one-to-many equality;
* `switch` can only be used with `int`, `bool` and `char` (by now);  
  in particular, `double` and `std::string` are not allowed.

However, when appropriate, not only is `switch` less verbose than `if else if`s,
but also *more efficient*.

TODO: examples
TODO: if and switch images













