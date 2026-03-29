#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ncurses.h>
#include "playing_field.h"

int main() {
    int max_y_window, max_x_window;

    initscr();

    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);

    getmaxyx(stdscr, max_y_window, max_x_window);

    playing_field game(max_y_window - 2, max_x_window - 2);
    game.display();

    getch();

    endwin();
    return 0;
}