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

It has the same effect as:

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

![for](https://github.com/Little-Flower-171/C-2018/blob/master/4/for.png)

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

It works like this:

![for](https://github.com/Little-Flower-171/C-2018/blob/master/4/if.png)

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

*What are the effects of the following `if` selections?*

```
int x; std::cin >> x;
if (std::cin) std::cout << "Good\n";
```

```
int x;
if (std::cin >> x)
    std::cout << "Good!\n";
```

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

which works like this:

![for](https://github.com/Little-Flower-171/C-2018/blob/master/4/switch.png)

The `default` can be omitted, in which case no code will be executed if *n* is not 1 to 5.

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
but also *more efficient*. *Why?*

## Examples

### 1. Little Flower's numbers

Given positive integers *a* and *b*, a positive integer

* that is a multiple of *a*,
* that gives a remainder of *a* when divided by *b*, and
* that is lower than *a*<sup>2</sup> &sdot; *b*

is called a *Little Flower's number*.

Write a program about this.

#### Program properties

* Program name: *lfnum*
* Time limit: 1 second
* Memory limit: 512 megabytes

#### Input format

Line # | Content
--- | ---
1 | two positive integers *a* and *b* separated by a single space (*a* < *b* ≤ 100)

#### Output format

Line # | Content
--- | ---
1 | the total number of *little Flower's number*s |

#### Sample input

```
2 3
```

#### Sample output

```
2
```

#### Hints

You can `for` over all numbers lower than *a*<sup>2</sup> &sdot; *b*
using `if` to determine whether the number is a *Little Flower's number*.

### 2. Virus infected

Little Flower's virtual machine is infected by a virus called "Minceraft" (not "Minecraft").
Minceraft replaces every lower-case vowel letter (a, e, i, o, or u) by a "x".

Your task is to write a mini-Minceraft.

#### Program properties

* Program name: virus
* Time limit: 1 second
* Memory limit: 512 megabytes

#### Input format

Line # | Content
--- | ---
1 | *n*, the length of text (1 ≤ *n* ≤ 50)
2 | a string of length *n*, consisting of only alphanumerics and spaces

#### Output format

Line # | Content
--- | ---
1 | Doctored text

#### Sample input

```
42
Zai yi ci de hui dao zhe shu xi de shi jie
```

#### Sample output

```
Zxx yx cx dx hxx dxx zhx shx xx dx shx jxx
```

#### Notes

Both

```C++
char c;
std::cin >> c;
```

and

```C++
std::string s;
std::cin >> s;
```

skips the spaces; use the following instead:

```C++
char c;
std::cin.get(c); // reads spaces
```

```C++
std::string s;
std::getline(std::cin, s); // reads a line
//   getline(std::cin, s); // also ok
```

#### Hints

1. You do not actually need to store the entire text.
2. If your program prints one less character than desired,
   remember this: (from [here](https://github.com/Little-Flower-171/C-2018/blob/master/3/student.md#input-stream-objects))
   
   > Note that it does not discard any more whitespaces after it has extracted the data.

## Words

Word | Meaning | Pronunciation
--- | --- | ---
iteration | 迭代 | /ˌɪtəˈreɪʃn/
selection | 选择 | /sɪˈlekʃn/
verbose | 冗长的 | BrE /vɜːˈbəʊs/ AmE /vɜːrˈboʊs/
loop | 循环 | /luːp/
effect | 效果 | /ɪˈfekt/
range | 范围 | /reɪndʒ/
base | 基于 | /beɪs/
semicolon | 分号（字符） | BrE /ˌsemiˈkəʊlən/ AmE /ˈsemikoʊlən/
condition | 条件 | /kənˈdɪʃn/
branch | 分支 | BrE /brɑːntʃ/ AmE /bræntʃ/
switch | 开关 | /swɪtʃ/
case | 情况 | /keɪs/
equality | 相等性 | BrE /iˈkwɒləti/ AmE /iˈkwɑːləti/
efficient | 高效的 | /ɪˈfɪʃnt/
virus | 病毒 | /ˈvaɪrəs/
alphanumeric | 字母或数字 | BrE /ˌælfənjuːˈmerɪk/ AmE /ˌælfənuːˈmerɪk/
doctor | 篡(cuɑ̀n)改 | BrE /ˈdɒktə(r)/ AmE /ˈdɑːktər/
store | 存储 | /stɔː(r)/
