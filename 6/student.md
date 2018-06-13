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
`x -= a;` | `x = x-a;`
`x *= a;` | `x = x*a;`
`x /= a;` | `x = x/a;`
`x %= a;` | `x = x%a;`

where `x` is an appropriate object and `a` an appropriate value.

## Accumulation

**Accumulation** or refers to the operation to fold a sequence of values into one single value.

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

## Words

Word | Meaning | Pronunciation
--- | --- | ---
compound | 复合的 | BrE /ˈkɒmpaʊnd/ AmE /ˈkɑːmpaʊnd/ 
assignment | 赋值 | /əˈsaɪnmənt/
