#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ncurses.h>
#include <random>
#include "playing_field.h"

using namespace std;

playing_field::playing_field(int height, int width) 
    : field_height(height), field_width(width) {
    
    current.assign(field_height, std::vector<cell>(field_width));
    next.assign(field_height, std::vector<cell>(field_width));
}

void playing_field::set_cells() {
    random_device cells_random;
    mt19937 gen(cells_random());
    bernoulli_distribution chance(0.01);

    for(int y = 0; y < field_height; y++) {
        for(int x = 0; x < field_width; x++) {
            current[y][x].setAlive(chance(gen));
            char symbol = current[y][x].getSymbol();
            mvaddch(y + 1, x + 1, symbol);
        }
    }
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

    set_cells();
    
    refresh();
}