#include <iostream>
#include <vector>

/*
Reads as many integers as possible from standard input
*/
std::vector<int> get_ints()
{
    std::vector<int> ints;
    for (int x; std::cin >> x;)
        ints.push_back(x);
    return ints;
}
