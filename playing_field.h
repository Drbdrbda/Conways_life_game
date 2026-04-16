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

    void set_cells();

public:
    playing_field(int height, int width);
    void check_status_cell();
    void display();
};

#endif