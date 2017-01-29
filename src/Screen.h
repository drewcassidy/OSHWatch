#ifndef OSHWATCH_SCREEN_H
#define OSHWATCH_SCREEN_H

#include <mbed.h>
#include <Nokia5110.h>
namespace OSHWatch {

class Screen {
public:
    virtual void draw() = 0;

    virtual void processInput(uint8_t button) = 0;
};
}

#endif //OSHWATCH_SCREEN_H
