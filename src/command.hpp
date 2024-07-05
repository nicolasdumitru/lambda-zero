#pragma once

class Command {
   private:
    inline void skipTo(char ch);
    inline void skipToNewline();
    inline void skipToArgs();
    inline void readArgs();

   public:
    static const int ARGS_MAX_SIZE = 50;
    enum { set_game, clear_board, cputime, genmove, play, quit };
    int args_size = 0;
    short type;
    char args[ARGS_MAX_SIZE + 1];
    void readFromStdin();
};
