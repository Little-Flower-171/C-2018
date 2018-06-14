# C++ Training Lesson 6 -- Compound Assignment

## Compound assignment

The following code:

```C++
x = x+5;
```

can be simplified into:

```C++
x += 5;
```

provided that ```x``` is an appropriate object.

There are similar **compound assignment operators** for arithmetical operations:

Compound assignment | Equivalent to
--- | ---
`x -= a;` | `x = x-a;`
`x *= a;` | `x = x*a;`
`x /= a;` | `x = x/a;`
`x %= a;` | `x = x%a;`

where `x` is an appropriate object and `a` an appropriate value.

Compound assignments are less verbose than plain ones,
and, sometimes *more efficient*.

## Accumulation

**Accumulation** refers to the operation to fold a sequence of values into one single value.

Let's take a look at the most common kinds of accumulations --
calculating the sum:

```C++
int sum = 0;
for (int x; std::cin >> x;) {
    sum += x;
}
```

as well as the product:

```C++
int product = 1; //why not 0?
for (int x; std::cin >> x;) {
    product *= x;
}
```

## Examples

### 1. Number accumulator

Calculate the sum, product, maximum and minimum of given numbers.

#### Program properties

- Program name: accum
- Time limit: 1 second
- Memory limit: 512 megabytes

#### I/O format

Until EOF or failure:

Input an integer *a*<sub>*i*</sub> (1 ≤ *a*<sub>*i*</sub> ≤ 100 for 1 ≤ *i* ≤ *n*),
where *i* is from 1 to *n*, the number of numbers input.

After EOF or failure:

Output

```
sum: <sum>
product: <product>
maximum: <maximum>
minimum: <minimum>
```

Where

- `<sum>` is *a*<sub>1</sub> + *a*<sub>2</sub> + *a*<sub>3</sub> + ... + *a*<sub>*n*</sub>
- `<product>` is *a*<sub>1</sub> ⋅ *a*<sub>2</sub> ⋅ *a*<sub>3</sub> ⋅ ... ⋅ *a*<sub>*n*</sub>
- `<maximum>` is max(*a*<sub>1</sub>, *a*<sub>2</sub>, *a*<sub>3</sub>, ..., *a*<sub>*n*</sub>)
- `<minimum>` is min(*a*<sub>1</sub>, *a*<sub>2</sub>, *a*<sub>3</sub>, ..., *a*<sub>*n*</sub>)

All the four are guaranteed to be under 10<sup>9</sup>.

If *n* = 0, sum is 0 and product is 1, and there does not exist maximum or minimum.

#### Sample Input

```
1
2
```

#### Sample Output

```
sum: 3
product: 2
maximum: 2
minimum: 1
```

### 2. Text reverser

Given a string consisting of no more than 255 characters,
including alphanumerics, spaces, and punctuations,
output its reverse.

#### Program properties

- Program name: rev
- Time limit: 1 second
- Memory limit: 512 megabytes

#### Sample input

```
Spread your wings across the universe, it's your time to, it's your time to fly.
```

#### Sample output

```
.ylf ot emit ruoy s'ti ,ot emit ruoy s'ti ,esrevinu eht ssorca sgniw ruoy daerpS
```

## Words

Word | Meaning | Pronunciation
--- | --- | ---
compound | 复合的 | BrE /ˈkɒmpaʊnd/ AmE /ˈkɑːmpaʊnd/ 
assignment | 赋值 | /əˈsaɪnmənt/
arithmetical | 算术的 | /ˌærɪθˈmetɪkl/
equivalent | 等价的 | /ɪˈkwɪvələnt/
accumulation | 积累 | /əˌkjuːmjəˈleɪʃn/
