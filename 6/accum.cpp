#include <iostream>
#include <algorithm>

int main()
{
    int x;
    std::cin >> x;
    if (!std::cin) {
        std::cout << "sum: 0\n"
                  << "product: 1\n";
        return 0;
    }

    int sum     = x,
        product = x,
        maximum = x,
        minimum = x;
    while (std::cin >> x) {
        sum += x;
        product *= x;
        maximum = std::max(maximum, x);
        minimum = std::min(minimum, x);
    }

    std::cout << "sum: "     << sum     << "\n"
              << "product: " << product << "\n"
              << "maximum: " << maximum << "\n"
              << "minimum: " << minimum << "\n";
}
