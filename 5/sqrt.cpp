#include <iostream>
#include <cmath> //for std::sqrt

int main()
{
    double num;

    for (;;) { //"forever"
        std::cout << "Number: ";
        std::cin >> num;

        //earlier than check of fail
        if (std::cin.eof()) {
            std::cout << "Bye.\n";
            return 0; //quit the main() function
        }
        //we must check cin first
        else if (std::cin.fail()) {
            std::cout << "This is not a number.\n";
            std::cin.clear(); //set state to goodbit
            while (std::cin.get() != '\n'); //note: semicolon here
                                            //what does this loop do?
            continue; //what is this?
        }
        //safe to read num
        else if (num < 0) {
            std::cout << "Imaginary numbers are not supported.\n";
            continue;
        }

        std::cout << "Square root: " << std::sqrt(num) << "\n";
        
    }
}
