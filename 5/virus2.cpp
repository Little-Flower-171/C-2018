#include <iostream>

int main()
{
    int count = 0;
    for (char c; std::cin.get(c);) {
        switch (c) {
        default:
            std::cout << c;
            break;
        case 'a': case 'e': case 'i': case 'o': case 'u':
            std::cout << 'x'; ++count;
            break;
        case 'A': case 'E': case 'I': case 'O': case 'U':
            std::cout << 'X'; ++count;
            break;
        }
    }
    std::cout << "X rxplxcxd " << count << " vxwxl lxttxrs wxth x \"x\".\n"; //note the use of escape characters    
}
