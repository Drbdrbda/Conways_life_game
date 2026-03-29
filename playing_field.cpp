#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ncurses.h>
#include "playing_field.h"

using namespace std;

playing_field::playing_field(int height, int width) 
    : field_height(height), field_width(width) {
    
    current.resize(field_height, std::vector<bool>(field_width, false));
    next.resize(field_height, std::vector<bool>(field_width, false));
}

void playing_field::display() {
    clear();

    mvaddch(0, 0, '+');
    mvaddch(field_height + 1, 0, '+');
    mvaddch(0, field_width + 1, '+');
    mvaddch(field_height + 1, field_width + 1, '+');

    for(int x = 1; x <= field_width; x++) {
        mvaddch(0, x, '-');
        mvaddch(field_height + 1, x, '-');

    }

    for(int y = 1; y <= field_height; y++) {
        mvaddch(y, 0, '|');
        mvaddch(y, field_width + 1, '|');

    }
    
    refresh();
}