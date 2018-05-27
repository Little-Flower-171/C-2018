// monster

/*
In fact, we need not store all these numbers;
as we read one number, we directly cope with it.
*/

#include <iostream>
int main()
{
    int n;
    std::cin >> n;
    
    int total = 0;
    for (int i=1; i<=n; ++i) { // i = [1..n]
        int enderman_n;
        std::cin >> enderman_n;
        total += enderman_n+1; // less verbose than total = total + enderman_n + 1;
    }
    
    std::cout << total << "\n";
}
