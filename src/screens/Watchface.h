#ifndef OSHWATCH_WATCHFACE_H
#define OSHWATCH_WATCHFACE_H

#include "Screen.h"
#include "bitmaps.h"

#include <mbed.h>
#include <Nokia5110.h>

namespace OSHWatch {

class Watchface : public Screen {
public:
    Watchface();

    void draw();

    void processInput(uint8_t button);

private:
    const uint8_t *getDigit(uint8_t value);
    bool _colon = false;
};
}

#endif //OSHWATCH_WATCHFACE_H
