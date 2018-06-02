#include <iostream>

int main()
{
    int a, b;
    std::cin >> a >> b;
    
    int total = 0;
    for (int i = 1; i < a*a*b; ++i) {
        if (i%a == 0 && i%b == a) 
            ++total;
    }
    
    std::cout << total << "\n";
}
