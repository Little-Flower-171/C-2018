# C++ Training Lesson 2 -- I/O Streams

## Text

The kind of program we are learning to write is called a **console application**.
It can be executed in a **console**.

It manages three standard **streams**: the **standard input stream**, **standard output stream**, and the **standard error stream**.  
In the context of C++, a stream is a sequence of characters.  
There are two kinds of streams: **input stream** and **output stream**.  
A program typically reads stuff from left for an input stream, and writes stuff to right for an output stream.
The standard error stream is typically used to report error.  
A stream is not necessarily a standard stream;
for example, files and strings can also be regarded as streams.

Think about this: *is the standard error stream an input or output stream?*

## Coding

The C++ standard library provides three **objects** in the namespace `std` -- `cout`, `cin`, and `cerr`,
to access the standard output, input, and error streams respectively.  
These names are easy to memorize since they are just abbreviations for
standard **c**haracter **out**put,
**c**haracter **in**put,
and **c**haracter **err**or streams.

Note that these objects are defined by the **C++ standard library** rather than the ~~C++ Core Language~~,
so they are defined in the namespace `std` and you need to access them with a `std::` prefix.

To use an output-stream object (`std::cout` or `std::cerr`), use the **operator** `<<` to **insert** data to the stream:

```C++
std::cout << "Hello world!\n";
```

You can insert more than one term and these terms can be of different **type**s:

```C++
std::cout << 'L' << "ittle Flower consists of " << 12 << " characters and is " << 1.5 << " times that of Minecraft." << '\n';
```

For different types of data, `<<` behaves differently; by default:

* For `char`s and `std::string`s, it directly inserts the character(s);
* For `int`s and `double`s (for decimals), it uses decimal representation;
* For `bool`s, it converts `false` and `true` to `0` and `1` respectively.

If `<<` receives a **variable** or an **expression**,
it prints the **value** of that variable or the **result** of that expression,
rather than its ~~name~~:

```C++
int x = 233;
std::cout <<  x  << "\n"; //prints 233
std::cout << "x" << "\n"; //prints x
```

There are also ways to change the display style; by now let's skip that.

## Examples

### 1. Reciprocals

Little Flower is playing with his calculator. Write a program to reproduce its message. 

#### Program properties

* Program name: **reciprocal**
* Time limit: 1 second
* Memory limit: 512 megabytes

#### Output

On standard output stream:
```
1/2 = 0.5
1/1 = 1
1/0 =
```

Then, on standard error stream:
```
The denominator is 0!
Is your brain impaired, Little Flower?
```

## Words

Word | Meaning | Pronunciation
--- | --- | ---
stream | 流 | /stri:m/
console | 控制台 | BrE /ˈkɒnsəʊl/ AmE /ˈkɑːnsoʊl/
application | 应用程序 | /ˌæplɪˈkeɪʃn/
execute | 执行 | /ˈeksɪkjuːt/
manage | 管理 | /ˈmænɪdʒ/
standard | 标准 | BrE /ˈstændəd/ AmE /ˈstændərd/
sequence | 序列 | /ˈsiːkwəns/
file | 文件 | /faɪl/
string | 字符串 | /strɪŋ/
code | 代码 | BrE /kəʊd/ AmE /koʊd/
library | 库 | BrE /ˈlaɪbrəri; ˈlaɪbri/ AmE /ˈlaɪbreri/
object | 对象 | BrE /ˈɒbdʒɪkt/ AmE /ˈɑːbdʒekt; ˈɑːbdʒɪkt/
access | 访问 | /ˈækses/
operator | 运算符 | BrE /ˈɒpəreɪtə(r)/ AmE /ˈɑːpəreɪtər/
insert | 插入 | BrE /ɪnˈsɜːt/ AmE /ɪnˈsɜːrt/
data | 数据 | /ˈdeɪtə/ BrE also /ˈdɑːtə/ AmE also /ˈdætə/
term | 项 | BrE /tɜːm/ AmE /tɜːrm/
type | 类型 | /taɪp/
default | 默认 | /dɪˈfɔːlt; ˈdiːfɔːlt/
representation | 表示形式 | /ˌreprɪzenˈteɪʃn/
convert | 转换 | BrE /kənˈvɜːt/ AmE /kənˈvɜːrt/
variable | 变量 | BrE /ˈveəriəbl/ AmE /ˈveriəbl; ˈværiəbl/
expression | 表达式 | /ɪkˈspreʃn/
print | 打印 | /prɪnt/
value | 值 | /ˈvæljuː/
result | 结果 | /rɪˈzʌlt/
display | 显示 | /dɪˈspleɪ/
style | 样式 | /staɪl/
reproduce | 再现 | BrE /ˌriːprəˈdjuːs/ AmE /ˌriːprəˈduːs/

