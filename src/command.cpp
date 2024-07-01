#include <iostream>
#include "command"

void command::readFromStdin() {
    std::cin.getline(args, 50);
    std::cout << args;
}
