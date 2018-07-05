# C++ Training Lesson 13 -- Vectors and Free Store

In the following lessons, we are going to try to implement `std::vector` by ourselves, and seize the chance to learn some technologies and C++ features.

## The very first version

```C++
vector<double> vec(4);
vec[0] = 20.3;
vec[1] = 37.5;
vec[2] = 41.8;
vec[3] = 60.1;
```

Apparently, it needs a data member for its size, and another data member for its elements. But how to represent a variable-size data set? (*Why not use `std::vector`?*)

In fact, this data member should point to a set of elements, so it can point to another set of elements when there are more elements. It may be something like the first element's address. In C++, a data type that holds an address is a **pointer**.

Hence, we can define our very first version:

```C++
//a highly simplified double vector
class vector {
    int sz;        //size
    double* elem;  //pointer to first element
public:
    vector(int s); //ctor: allocate elements of double
                   //have elem point to them
                   //store s in sz
    int size() const { return sz; }
};
```

## Pointers

Anything we store has an **address**. We can store and operate on addresses. An object that stores an address is a **pointer**. For example, the type used to store addresses of `int`s is called "pointer to `int`" or "`int` pointer":

```C++
int var = 17;
int* ptr = &var; //ptr stores var's address
```

The **address-of** operator `&` is used to obtain an object's address. Its result type is "pointer to the corresponding type".

Every type has its own pointer type:

```C++
double e = 2.72;
double* pd = &e; //double pointer
int* pi = &e;    //error: cannot convert from "double*" to "int*"
```

We can use the **dereference** operator `*` to access the pointed-to object:

```C++
char c = 'x';
char* p = &c;
*p = 'a';
std::cout << *p << "\n"; //outputs a
std::cout << *c << "\n"; //also outputs a
```

We can output a pointer:

```C++
int a = 1;
int* p = &a;
std::cout << p << "\n";  //prints a's address

double b;
std::cout << &b << "\n"; //prints b's address
```

The output format depends on the system. Note that a pointer is not an integer although it can be printed as an integer:

```C++
int x = p;     //error: cannot convert int* to int
int* y = 1024; //error: cannot convert int to int*
```

## `sizeof` operator

We can use `sizeof` operator to obtain the size of a certain type:

```C++
void print_sizes(char c, int i, int* p)
{
    std::cout << "The size of char is " << sizeof(char) << " which is equal to " << sizeof c << "\n";
    std::cout << "The size of int is " << sizeof(int) << " which is equal to " << sizeof i << "\n";
    std::cout << "The size of int* is " << sizeof(int*) << " which is equal to " << sizeof p << "\n";
}
```

The size of a type is not the same in all C++ implementations.

How much memory does a `vector` occupy? Try this:

```C++
std::vector<int> v(1000);
std::cout << "The size of std::vector<int>(1000) is " << sizeof v << "\n";
```

The output may be like this:

    the size of std::vector<int>(1000) is 20

Apparently, `sizeof` does not count the elements.

## Free store and pointer

When you write a C++ program, the memory available is split into:

- Code storage: memory for your code;
- Static storage: memory for your global variables;
- Stack storage: memory for your functions to store its parameters and local variables;
- Free store: the remaining memory for other usage.

The C++ operator `new` turns **free store** into available state:

```C++
double* p = new double[4];
```

The pointer `p` points to *the first element* (rather than the whole array), hence a `double*`.

### Allocation

The operator `new` **allocate**s memory from free store. It can allocate memory for a single element or a sequence of elements:

```C++
int* pi = new int;    //allocates an int
int* qi = new int[n]; //allocates an array of n ints

double* pd = new double{3.0}; //allocates a double and initialize
double* qd = new double[4]{1, 2, 3, 4}; //allocates an array of 4 doubles and initialize
```

Note that the number of elements can be given at runtime.

### Dereference the pointer

The **dereference operator** `*`, as well as the **subscript operator** `[]`, can be used on a pointer:

```C++
double* p = new double[4]{0.1, 0.2, 0.4, 0.8};

double x = *p;   //x == 0.1
double y = p[2]; //y == 0.4

*p = 1;          //{1, 0.2, 0.4, 0.8}
p[2] = 5;        //{1, 0.2, 5, 0.8}
```

### Initialization

As usual, the value of an uninitialized object is undefined.

```C++
int* p;                           //p is undefined
int* q = new double;              //*q is undefined
int* r = new double{5.5};         //good
int* s = new double[5];           //p[0], p[1], p[2], p[3], and p[4] are all undefined
int* t = new double[]{0,1,2,3,4}; //good
//identical to int* t = new double[5]{0,1,2,3,4};
```

### Null pointer

A **null pointer** is one that points to nothing.

```C++
double* p = nullptr; //null pointer
```

Dereferencing a null pointer is undefined behavior. We can check the validity of the pointer:

```C++
if (p != nullptr) /*...*/; //is p valid?
if (p) /*...*/;            //same, less verbose
```

### Deallocation

It is a good idea to return memory to free store after use. This memory can be used for new allocation requests.

```C++
double* calc(int res_size, int max)
{
    double* p = new double[max];
    double* res = new double[res_size];
    //calculate...
    delete[] p;
    return res;
}

double* a = calc(100, 1000);
//use...
delete[] a;

double* b = calc(100, 1000);
//use...
b = nullptr; //memory leak
```

## Destructors

We can allocate enough memory for elements and use a pointer to access them:

```C++
class vector {
    int sz;
    double* elem;
public:
    vector(int s)
        :sz{s}, elem{new double[s]{}} //allocate memory and initialize elem
    {
    }
};
```

(Note that the elements are initialized to their default value `0.0`.)

Unfortunately, this version of `vector` gives rise to memory leak. It `new`s elements in the constructor, but never `delete`s them.

A **destructor** is implicitly called when an object is destroyed. The **constructor** ensures that objects are properly created and initialized; in contrast, the **destructor** ensures that objects are properly cleaned and destroyed.

(Note: here, "create" and "destroy" are antonyms, whereas "initialize" and "clean" are antonyms.)

```C++
class vector {
    int sz;
    double* elem;
public:
    vector(int s)                     //constructor
        :sz{s}, elem{new double[s]{}} //initializes
    {
    }

    ~vector()                         //destructor
    {
        delete[] elem;                //cleans
    }
};
```

We can use it like this:

```C++
void f(int n)
{
    double* p = new double[n];
    vector v(n);

    //use p and v ...

    delete[] p;
    //v is automatically destroyed
}
```

Destructors are a great way to manage resources that are first acquired and later released.

### Generated destructors

If a member has a destructor, it is called during the destruction of the object:

```C++
struct Customer {
    std::string name;
    //...
};

int f()
{
    Customer fred{"Fred"};
    
    //...

    return 0;
} //fred.name is automatically destructed
```

## Words

Word | Meaning | Pronunciation
--- | --- | ---
free store | 自由存储 | /friː stɔː(r)/
address | 地址 | BrE /əˈdres/ AmE /ˈædres/
pointer | 指针 | /ˈpɔɪntə(r)/
allocate | v. 分配 | /ˈæləkeɪt/
dereference | 解引用；间接访问 | /ˌdiːˈrefrəns/
stack | 栈(zhɑ̀n) | /stæk/
null | 无值的；无效的 | /nʌl/
deallocation | n. 释放 | /ˌdiːæləˈkeɪʃn/
allocation | n. 分配 | /ˌæləˈkeɪʃn/
leak | 泄露 | /liːk/
destructor | 析构函数 | /dɪˈstrʌktə(r)/
resource | 资源 | BrE /rɪˈsɔːs; rɪˈzɔːs/ AmE /ˈriːsɔːrs; rɪˈsɔːrs/
acquire | 获取 | /əˈkwaɪə(r)/
release | 释放 | /rɪˈliːs/
destruction | 析构 | /dɪˈstrʌkʃn/
