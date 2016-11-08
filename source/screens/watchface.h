#ifndef WATCHFACE_H
#define WATCHFACE_H

#include "bitmaps.h"
#include "screen.h"

class Watchface : public Screen {
public:
    Watchface(Nokia_5110* display);
    void draw();
    void processInput(uint8_t button);
private:
    const uint8_t* getDigit(uint8_t value);
    Nokia_5110* _display;
};

#endif
