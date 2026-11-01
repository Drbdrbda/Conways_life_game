#ifndef PLAYING_FIELD_H
#define PLAYING_FIELD_H

#include <vector>
#include "cell.h"

class playing_field {
private:
    const int field_height;
    const int field_width;
    std::vector<std::vector<cell>> current;
    std::vector<std::vector<cell>> next;

    void draw_frame();
    void draw_cells();

public:
    playing_field(int height, int width);
    void update(); 
    void display();
    void random_draw_cells();
    void change_cell_status(int cell_y, int cell_x);
    bool should_be_alive(bool isCurrentlyAlive, int neighbours);
    int counter_neighbours(int cell_y, int cell_x);
};

#endif