# C++ Training Lesson 1 -- Review

## Examples

### 1. Welcome to C++

Little Flower the newbie is learning C++. Let's welcome him by writing a program that prints a welcome message. 

#### Output

```
Welcome to C++!
```

### 2. Let's do some math

Little Flower wants to do some math.
He wants to know the sum, difference, product and ratio of two numbers *a* and *b*.
Write a program that accepts two numbers and calculates these properties. 

#### Input format

| Line # | Content                                                                    |
| ------ | -------------------------------------------------------------------------- |
| 1      | Two integers *a* and *b* separated by a single space (1 ≤ *a*,*b* ≤ 10000) |

#### Output format

| Line # | Content                                        |
| ------ | ---------------------------------------------- |
| 1      | A single integer *s* such that *s* = *a* + *b* |

#### Sample input

```
233 666
```

#### Sample output

```
899
```

#### Notes
1. All integers are in decimal form without leading zeroes. 
2. Each line, whether in input or output, never ends with a space. Input and output shall both end with a single line feed character. 

### 3. Number of monsters

Little Flower's base on Mars is attacked by endermen and creepers. 
They are split into *n* teams. 
For 1 ≤ *i* ≤ *n*, the *i*<sup>th</sup> team consists of one creeper and *a*<sub>*i*</sub> endermen. 
Write a program to help him calculate the total number of monsters. 

#### Input format

| Line # | Content                                                                                                                                                            |
| ------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| 1      | A single integer *n* (1 ≤ *n* ≤ 1000)                                                                                                                              |
| 2      | *n* integers *a*<sub>1</sub>, *a*<sub>2</sub>, *a*<sub>3</sub>, ..., *a*<sub>*n*</sub> separated by a single space (for 1 ≤ *i* ≤ *n*, 0 ≤ *a*<sub>*i*</sub> ≤ 10) |

#### Output format

| Line # | Content                                        |
| ------ | ---------------------------------------------- |
| 1      | A single integer, the total number of monsters |

#### Sample input

```
5
1 2 3 4 5
```

#### Sample output

```
20
```
