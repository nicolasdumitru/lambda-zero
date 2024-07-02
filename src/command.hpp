#pragma once

class command {
   private:
    inline void skipTo(char ch);
    inline void skipToNewline();
    inline void skipToArgs();
    inline void readArgs();

   public:
    static const int args_max_size = 50;
    int args_size = 0;
    short type;
    char args[args_max_size + 1];
    enum { set_game, clear_board, cputime, genmove, play, quit };
    void readFromStdin();
};
