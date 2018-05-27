// scalc

#include <iostream>
int main()
{
    int a, b;
    char op;
    std::cin >> a >> op >> b;
    
    if (op == '+') {
        std::cout << (a+b) << "\n";
    } else if (op == '-') {
        std::cout << (a-b) << "\n";
    } else if (op == '*') {
        std::cout << (a*b) << "\n";
    } else if (op == '/') {
        std::cout << (a/b) << "\n";
    }
}
