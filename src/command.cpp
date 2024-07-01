#include <iostream>
using std::cin;
#include "command"

inline void command::skipTo(char sep) {
    char ch = cin.get();
    while (ch != sep)
        ch = cin.get();
}

inline void command::skipToNewline() {
    skipTo('\n');
}

inline void command::skipToArgs() {
    skipTo(' ');
}

inline void command::readArgs() {
    args_size = 0;
    args[args_size] = cin.get();
    while (args[args_size] != '\n') {
        args_size++;
        args[args_size] = cin.get();
    }
    args[args_size] = '\0';
}

void command::readFromStdin() {
    // very minimal Pentobi GTP command processing
    char ch1, ch2;
    ch1 = cin.get();
    switch (ch1) {
    case 's': // `set_game Blokus Duo`
        type = set_game;
        skipToNewline();
        break;
    case 'c': // `clear_board` or `cputime`
        ch2 = cin.get();
        switch (ch2) {
        case 'l': type = clear_board; break;
        case 'p': type = cputime; break;
        }
        skipToNewline();
        break;
    case 'g': // `genmove [wb]`
        type = genmove;
        skipToArgs();
        readArgs();
        break;
    case 'p': // `play [wb] ...`
        type = play;
        skipToArgs();
        readArgs();
        break;
    case 'q': // `quit`
        type = quit;
        break;
    }
}
