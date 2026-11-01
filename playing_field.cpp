#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ncurses.h>
#include <random>
#include <algorithm>

#include "playing_field.h"
#include "cell.h"

using namespace std;

playing_field::playing_field(int height, int width) 
    : field_height(height), field_width(width) {
    
    current.assign(field_height, std::vector<cell>(field_width));
    next.assign(field_height, std::vector<cell>(field_width));
}

void playing_field::draw_frame() {
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

}   

void playing_field::random_draw_cells() {
    for (int y = 0; y < field_height; y++) {
        for (int x = 0; x < field_width; x++) {
            current[y][x].setCellStatus(false);
        }
    }

    std::random_device rd;
    std::mt19937 gen(rd());

    int max_clusters = std::min(10, (field_height * field_width) / 20);
    if (max_clusters < 3) max_clusters = 3;
    std::uniform_int_distribution<> clusters_dist(3, max_clusters);
    int cluster_count = clusters_dist(gen);

    std::uniform_int_distribution<> y_dist(0, field_height - 1);
    std::uniform_int_distribution<> x_dist(0, field_width - 1);
    std::uniform_int_distribution<> radius_dist(1, 3);
    std::bernoulli_distribution cell_chance(0.6);

    for (int c = 0; c < cluster_count; c++) {
        int cy = y_dist(gen);
        int cx = x_dist(gen);
        int radius = radius_dist(gen);

        current[cy][cx].setCellStatus(true);

        for (int y = cy - radius; y <= cy + radius; y++) {
            for (int x = cx - radius; x <= cx + radius; x++) {

                if (y < 0 || y >= field_height || x < 0 || x >= field_width) continue;

                if (y == cy && x == cx) continue;

                if (cell_chance(gen)) {
                    current[y][x].setCellStatus(true);
                }
            }
        }
    }
}

void playing_field::change_cell_status(int cell_y, int cell_x) {
    if (cell_y >= 0 && cell_y < field_height && cell_x >= 0 && cell_x < field_width) {
        bool status = current[cell_y][cell_x].getCellStatus();
        if (status == true) {
            current[cell_y][cell_x].setCellStatus(false);
        } else {
            current[cell_y][cell_x].setCellStatus(true);
        }

     }
}


bool playing_field::should_be_alive(bool isCurrentlyAlive, int neighbours) {
    if (isCurrentlyAlive) {
        return (neighbours == 2 || neighbours == 3);
    } else {
        return (neighbours == 3);
    }
}

int playing_field::counter_neighbours(int cell_y, int cell_x) {
    int counter_alive_cells = 0;
    
    for(int i = cell_y - 1; i <= cell_y + 1; i++) {
        for(int j = cell_x - 1; j <= cell_x + 1; j++) {
            if (i == cell_y && j == cell_x) continue;
            
            if (i >= 0 && i < field_height && j >= 0 && j < field_width) {
                if (current[i][j].getCellStatus() == true) {
                    counter_alive_cells++;
                }
            }
        }
    }
    
    return counter_alive_cells;
}

void playing_field::draw_cells() {
    for(int y = 0; y < field_height; y++) {
        for(int x = 0; x < field_width; x++) {
            mvaddch(y + 1, x + 1, current[y][x].getSymbol());

            refresh();
        }
    }
}

void playing_field::update() {
    for(int y = 0; y < field_height; y++) {
        for(int x = 0; x < field_width; x++) {
            int neighbours = counter_neighbours(y, x);
            bool currentState = current[y][x].getCellStatus();
            bool newState = should_be_alive(currentState, neighbours);
            
            next[y][x].setCellStatus(newState);
        }
    }
    
    for(int y = 0; y < field_height; y++) {
        for(int x = 0; x < field_width; x++) {
            current[y][x].setCellStatus(next[y][x].getCellStatus());
        }
    }
}

void playing_field::display() {
    clear();

    draw_frame();
    draw_cells();

    refresh();
}