#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ncurses.h>

#include "manual_control.h"
#include "playing_field.h"

using namespace std;

void  manual_control::handle_input(playing_field& field, int symbol_input){
    
    switch(symbol_input) {
        case 'q':
            // выход из игры
            break;

        case 'r':
            field.random_draw_cells();
            break;

        case KEY_MOUSE: { 
            MEVENT event;
            if (getmouse(&event) == OK) {
                if (event.bstate & BUTTON1_PRESSED) {
                    int cell_y = event.y - 1;
                    int cell_x = event.x - 1;

                    field.change_cell_status(cell_y, cell_x);

                }
            }
            break;
        }

        default:
            // ничего не происходит
            break;
    }
}