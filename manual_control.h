#ifndef MANUAL_CONTROL_H
#define MANUAL_CONTROL_H

class playing_field; 

class manual_control {
public:
    void handle_input(playing_field& field, int symbol_input);
};

#endif