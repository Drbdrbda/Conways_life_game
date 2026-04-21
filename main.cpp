#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ncurses.h>

#include "playing_field.h"
#include "manual_control.h"

int main() {
    int max_y_window, max_x_window;

    initscr();

    cbreak();
    noecho();
    curs_set(0);
    mousemask(ALL_MOUSE_EVENTS, NULL);
    mouseinterval(0);  
    keypad(stdscr, TRUE);

    getmaxyx(stdscr, max_y_window, max_x_window);

    playing_field game(max_y_window - 2, max_x_window - 2);

    game.random_draw_cells();
    game.display();

    int symbol_input;

    while((symbol_input = getch()) != 'q') {
        manual_control control_input;
        control_input.handle_input(game, symbol_input);

        game.display();                
    }

    endwin();
    return 0;
}