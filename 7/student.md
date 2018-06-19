# C++ Training Lesson 7 -- Arrays

## Issue

Write a program that prints a sequence of decimals in reverse order.

### Sample input

```
1.41 2.72 3.14
```

### Sample output

```
3.14 2.72 1.41
```

In this situation, input-and-processing does not make sense anymore.
You just have no way but storing these numbers.
But since it is impossible to declare *n* variables, how to store them?

## `std::vector`

`std::vector` is a **template** (neither a type nor an object) provided by the standard library.
It encapsulates **dynamic-size array**s.

In the context of C++,
an **array** is a **container** that stores *n* **homogeneous** **element**s,
**index**ed from 0 to *n*-1,
where *n* is called the **size** of the array.

A **static-size array** is one whose size is known at compile time;
by contrast, a **dynamic-size array** is one whose size is known at run time.

`std::vector` can be expanded and contracted; i.e. its size can be modified.

(Note: there are other ways to store an array in C++; by now let's skip that.)

`std::vector` is quite different from other types provided by the standard library (such as `std::string`),
since it is a **template**, i.e. you can provide **arguments** in order to generate types.
Template arguments are specified in angle brackets.

`std::vector` accepts one **type** as template argument.
The type can be anything, such as `int`, `std::string`, or `std::vector<int>`.
For example, `std::vector<double>` is an array of `double`s.

(Note: `std::vector` optionally accepts a second argument; by now let's skip that.)

### Constructing

There are many ways to construct a `std::vector`:

- You can construct an empty `std::vector`:

```C++
std::vector<int> vec1; //vec1 is empty
```

- You can specify its size at construction:

```C++
std::vector<int> vec2(10); //vec2 has 10 elements
                           //each element has value zero
std::vector<int> vec3(10, 233); //vec3 has 10 elements
                                //each element has value 233
```

- You can specify its elements:

```C++
std::vector<int> vec4{10, 20, 30, 40}; //vec4 has 4 elements:
                                       //10, 20, 30, 40 respectively
```

When you specify the size, use parentheses;
otherwise, use braces.
For example:

```C++
std::vector<int> vec5(10, 20); //vec5 has 10 elements
                               //each element has value 20
std::vector<int> vec6{10, 20}; //vec6 has 2 elements
                               //10 and 20 respectively
```

`std::vector`s of the same type can be copied or moved:

```C++
std::vector<int> vec7 = vec5; //vec7 has 10 elements, each has value 20
                              //so does vec5
std::vector<int> vec8 = std::move(vec6); //vec8 has 2 elements, 10 and 20 respectively
                                         //vec6 is empty now
```

Moving is much more efficient than copying if there are a lot of elements.

To access `std::move`, include the header `<utility>`.

### Assigning

A `std::vector` can be assigned another `std::vector` or a list of elements using operator `=`:

```C++
vec7 = vec3; //vec7 now has 10 elements, each has value 233
             //so does vec3
vec8 = std::move(vec4); //vec8 now has 4 elements, 10, 20, 30, and 40
                        //vec4 is now empty
vec4 = {100, 200, 300, 400}; //vec4 has new elements
                             //vec8 is unaffected
```

You can also use the `assign` function:

```C++
vec7.assign(10, 20);   //vec7 now has 10 elements, each has value 20
vec8.assign({10, 20}); //vec8 now has 2 elements, 10 and 20
```

Note: assignment is different from construction. *How are they different?*

### Accessing the elements

You can use brackets `[]` to access individual elements:

```C++
std::cout << vec7[0]; //outputs 20
std::cin  >> vec7[1]; //inputs a number and store it into vec7's element #1
```

Note: elements are indexed from 0 to *n*-1 rather than 1 to *n*,
where *n* is the size of the vector.
If you provide a position out of the container,
**undefined behavior** takes place.

There are two convenience functions: (assuming `vec` is an appropriate vector)

Convenience function | Equivalent to
--- | ---
`vec.front()` | `vec[0]`
`vec.back()` | `vec[vec.size() - 1]`

If `vec` is empty, **undefined behavior** takes place.

### Appending to the end

To add an element to the end:

```C++
vec.push_back(v); //add v to the end of vec
vec.emplace_back(v1, v2, ...); //same as vec.push_back(T{v1, v2, ...}) where T is the type of element
```

To remove the last element:

```C++
vec.pop_back(); //remove the last element
```

### Iterating over

You can use a **range-based `for` loop** to iterate over a `std::vector`:

```C++
for (int x : vec)
    std::cout << x << "\n";
```

### Other operations

Operation | Effect
--- | ---
`vec.size()` | returns the size of `vec`
`vec.empty()` | returns `vec.size() == 0` (a `bool` value)
`vec.clear()` | clear the contents
`vec.resize(n)` | if `vec.size() > n`, reduce `vec` to its first `n` elements; if `vec.size() < n`, add `n - vec.size()` **default-constructed** elements
`vec.resize(n, v)` | if `vec.size() > n`, reduce `vec` to its first `n` elements; if `vec.size() < n`, add `n - vec.size()` elements, each of value `v`

## Back to the issue

```C++
#include <iostream>
#include <vector> //for std::vector

int main()
{
    std::vector<double> numbers; //numbers is initially empty
    for (double x; std::cin >> x;) {
        numbers.push_back(x);
    }

    for (int i = numbers.size(); i--;) { //?
        std::cout << numbers[i] << " ";
    }
}
```

## Example

### 1. Database

Little Flower has a lot of data. Write a program for him to use as database.

The database first gets the data.
Then, *m* queries are performed.

#### Program properties

- Program name: database

#### Input format

Line # | Content
--- | ---
1 | A single integer *n*
2 | Space-separated integers *a*<sub>1</sub>, *a*<sub>2</sub>, *a*<sub>3</sub>, ..., *a*<sub>*n*</sub>
3 to *m*+2 | A single integer *i*

#### Output format

Line # | Content
--- | ---
1 to *m* | A single integer *a*<sub>*i*</sub>

#### Ranges

1 ≤ *m* ≤ 100,000
1 ≤ *i* ≤ *n* ≤ 100,000
0 ≤ *a*<sub>*i*</sub> ≤ 100 for 1 ≤ *i* ≤ *n*

#### Sample input

```
5
23333 32333 33233 33323 33332
3
2
3
3
```

#### Sample output

```
32333
33233
33233
```

### 2. Prime number

Given a natural number *n*, print all the primes not greater than *n*.

#### Input format

A single integer *n*.

#### Output format

All prime numbers not greater than *n*, each within a line.

#### Ranges

1 ≤ *n* ≤ 1,000,000

#### Sample input

```
15
```

#### Sample output

```
2
3
5
7
11
13
```

## Words

Word | Meaning | Pronunciation
--- | --- | ---
array | 数组 | /əˈreɪ/
reverse | 相反 | BrE /rɪˈvɜːs/ AmE /rɪˈvɜːrs/
declare | 声明 | BrE /dɪˈkleə(r)/ AmE /dɪˈkler/
vector | 向量 | /ˈvektə(r)/
template | 模(mú)板 | /ˈtempleɪt/
encapsulate | 封装 | /ɪnˈkæpsjuleɪt/
dynamic | 动态的 | /daɪˈnæmɪk/
container | 容器 | /kənˈteɪnə(r)/
element | 元素 | /ˈelɪmənt/
index | 编号 | /ˈɪndeks/
static | 静态的 | /ˈstætɪk/
expand | 扩大 | /ɪkˈspænd/
contract | 缩小 | /kənˈtrækt/
modify | 修改 | BrE /ˈmɒdɪfaɪ/ AmE /ˈmɑːdɪfaɪ/
specify | 说明 | /ˈspesɪfaɪ/
angle bracket | 尖角括号 | /ˈæŋɡl ˈbrækɪt/
optional | 可选的 | BrE /ˈɒpʃənl/ AmE /ˈɑːpʃənl/
construct | 构造 | /kənˈstrʌkt/
parenthesis | （圆）括号（单数） | /pəˈrenθəsɪs/
parentheses | （圆）括号（复数） | /pəˈrenθəsiːz/
brace | 花括号 | /breɪs/
copy | 复制 | BrE /ˈkɒpi/ AmE /ˈkɑːpi/
move | 移动 | /muːv/
header | 头文件 | /ˈhedə(r)/
utility | 实用程序 | /juːˈtɪləti/
assign | 赋值 | /əˈsaɪn/
list | 列表 | /lɪst/
bracket | 方括号 | /ˈbrækɪt/
individual | 单独的 | /ˌɪndɪˈvɪdʒuəl/
position | 位置 | /pəˈzɪʃn/
define | 定义 | /dɪˈfaɪn/
behavior | 行为 | /bɪˈheɪvjə(r)/
append | 追加 | /əˈpend/
emplace | 放置 | /ɪmˈpleɪs/
remove | 移除 | /rɪˈmuːv/
operation | 操作 | BrE /ˌɒpəˈreɪʃn/ AmE /ˌɑːpəˈreɪʃn/
clear | 清除 | BrE /klɪə(r)/ AmE /klɪr/
reduce | 缩小 | BrE /rɪˈdjuːs/ AmE /rɪˈduːs/
add | 增加 | /æd/
database | 数据库 | /ˈdeɪtəbeɪs/ AmE also /ˈdætəbeɪs/
query | 查询 | BrE /ˈkwɪəri/ AmE /ˈkwɪri/
perform | 执行 | BrE /pəˈfɔːm/ AmE /pərˈfɔːrm/
