# C++ Training Lesson 3 -- Input-stream Objects

## Input-stream objects

To use an input-stream object (`std::cin`), use the **operator** `>>` to **extract** data from the stream:

```C++
int x;
std::cin >> x;
```

You can extract more than one term and these terms can be of different types
(note that they have to be homogeneous in some other programming languages):

```C++
int a;
double b;
std::cin >> a >> b;
```

For different types of data, `>>` behaves differently; by default:

It first discards any whitespaces received (including spaces, line feeds, and tabulators);
then,
* For `char`s, it extracts one character;
* For `std::string`s, it extracts all characters before receiving another whitespace;
* For `int`s and `double`s, it extracts a number in decimal representation;
* For `bool`s, it extracts a single `0` or `1`, storing `false` and `true` respectively;

Note that it does not discard any more whitespaces after it has extracted the data.

Additionally, the *standard library* provides two functions:

```C++
char c;
std::cin.get(c); // extracts the current character, even if it is whitespace
```

and

```C++
std::string s;
std::getline(std::cin, s); // extracts the whole line;
                           // i.e. all characters before encountering line feed
```

The latter can also be written as

```C++
getline(std::cin, s); // omit outermost "std::"
```

provided that *at least one of the **argument**s is from the namespace `std`*.

`>>` must receive a target (e.g. a **variable**) to which data can be written.

```C++
int x; std::cin >> x; //OK
//std::cin >> 233; error, data can be written to nowhere
//std::cin >> (x+233); ditto
```

There are also ways to change the input style; by now let's skip that.

You can make a prompt with `std::cout`:

```C++
std::cout << "How old are you? "; //note: no line feed
int age;
std::cin >> age;
```

## Examples

### 1. Simple calculator

Little Flower accidentally dropped his calculator and broke it.
Please write a simple calculator for him as a workaround.  
The simple calculator can calculate
additions, subtractions, multiplications and divisions.

#### Program properties
* Program name: *scalc*
* Time limit: 1 second
* Memory limit: 512 megabytes

#### Input format

Line # | Content
--- | ---
1 | an expression of the form `a + b`, `a - b`, `a * b`, or `a / b`, representing addition, subtraction, multiplication, and division, respectively, where `a` and `b` are integers and 1 ≤ *a*, *b* ≤ 10000

`a / b` is guaranteed to be an integer.

#### Output format

Line # | Content
--- | ---
1 | a single integer, the result of the input expression

#### Sample input

```
1 + 2
```

#### Sample output

```
3
```

#### Hints

1. The operator can be read as a `char`.
2. You can use the following to parse the operator:

```C++
if (op == '+') {
    // addition
} else if (op == '-') {
    // subtraction
} else if (op == '*') {
    // multiplication
} else if (op == '/') {
    // division
}
```

## Words

Word | Meaning | Pronunciation
--- | --- | ---
extract | 提取 | /ɪkˈstrækt/
homogeneous | 同构的 | BrE /ˌhɒməˈdʒiːniəs/ AmE /ˌhoʊməˈdʒiːniəs/
discard | 丢弃 | BrE /dɪsˈkɑːd/ AmE /dɪsˈkɑːrd/
whitespace | 空白符 | /ˈwaɪtspeɪs/
tabulator | Tab键 | /ˈtæbjuleɪtə(r)/
function | 函数 | /ˈfʌŋkʃn/
prompt | 提示；提醒 | BrE /prɒmpt/ AmE /prɑːmpt/
workaround | 变通方法 | BrE /ˈwɜːkəraʊnd/ AmE /ˈwɜːrkəraʊnd/
guarantee | 保证 | /ˌɡærənˈtiː/
hint | 提示；窍门 | /hɪnt/
parse | 分析 | BrE /pɑːz/ AmE /pɑːrs/
