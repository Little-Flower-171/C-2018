#include <iostream>
#include <string>

int main()
{
    std::string str;
    getline(std::cin, str);

    std::reverse(str.begin(), str.end()); //what does it mean?
    
    std::cout << str << "\n";
}
