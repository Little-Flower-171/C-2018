#include <iostream>

int main()
{
    int n; std::cin >> n;
    for (int i=0; i<n; ++i) {
        char c; std::cin.get(c);
        switch (c) {
        case 'a': case 'e': case 'i': case 'o': case 'u':
            std::cout << x; break;
        default:
            std::cout << c;
        }
    }
}
