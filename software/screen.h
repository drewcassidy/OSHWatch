#ifndef SCREEN_H
#define SCREEN_H

#include "mbed.h"
#include "Nokia-5110-LCD/Nokia5110.h"

class Screen {
public:
    virtual void draw() = 0;
    virtual void processInput(uint8_t button) = 0;
};

#endif
