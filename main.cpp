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
    nodelay(stdscr, TRUE);

    getmaxyx(stdscr, max_y_window, max_x_window);

    playing_field game(max_y_window - 2, max_x_window - 2);

    game.random_draw_cells();
    game.display();

    bool paused = false;

    while(true) {
        int input_key = getch();
        manual_control control_input;

        if (input_key == 'q') {
            break;
        }

        if (input_key == ' ') {
            paused = !paused;
        }

        if (input_key != ERR) {
            control_input.handle_input(game, input_key);
        }

        if (!paused) game.update();
        game.display();
        
        napms(100);
    }

    endwin();
    return 0;
}