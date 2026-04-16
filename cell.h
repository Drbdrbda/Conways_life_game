#ifndef CELL_H
#define CELL_H

#include <ncurses.h>

class cell {
private:
    char alive_symbol = '■';
    char dead_symbol = ' ';

    bool is_alive = false;

public:
    cell() = default;

    bool getAlive() const { return is_alive; }
    void setAlive(bool status) { is_alive = status; }
    char getSymbol() const { return is_alive ? alive_symbol : dead_symbol; }
};

#endif