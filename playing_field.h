#ifndef PLAYING_FIELD_H
#define PLAYING_FIELD_H

#include <vector>

class playing_field {
private:
    const int field_height;
    const int field_width;
    std::vector<std::vector<bool>> current;
    std::vector<std::vector<bool>> next;

public:
    playing_field(int height, int width);
    void set_cell();
    void display();
};

#endif