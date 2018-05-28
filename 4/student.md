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

















