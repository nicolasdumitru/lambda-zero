#include <iostream>
#include "command"

int main() {
    command cmd;
    std::cout << "command line:\n";
    cmd.readFromStdin();
    std::cout << cmd.type << " args:\n\"" << cmd.args << "\"";
    return 0;
}
