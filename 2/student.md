# C++ Training Lesson 2 -- I/O Streams

## Text

The kind of program we are learning to write is called a **console application**.
It can be executed in a **console**.

It manages three standard **streams**: the **standard input stream**, **standard output stream**, and the **standard error stream**.  
In the context of C++, a stream is a sequence of characters.  
There are two kinds of streams: **input stream** and **output stream**.  
A program typically reads stuff from left for an input stream, and writes stuff to right for an output stream.
The standard error stream is typically used to report error.  
The concept of stream does not bound to standard streams;
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

```
std::cout << "Hello world!\n";
```

You can insert more than one term and these terms can be of different **type**s:

```
std::cout << 'L' << "ittle Flower consists of " << 12 << " characters and is " << 1.5 << " times that of Minecraft." << '\n';
```

For different types of data, `<<` behaves differently; by default:

* For `char`s and `std::string`s, it directly inserts the character(s);
* For `int`s and `double`s (for decimals), it uses decimal representation;
* For `bool`s, it converts `false` and `true` to `0` and `1` respectively.

There are also ways to change the display style; by now let's skip that.

