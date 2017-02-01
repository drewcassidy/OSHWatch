#ifndef OSHWATCH_WATCHFACE_H
#define OSHWATCH_WATCHFACE_H

#include "Screen.h"
#include "bitmaps.h"

#include <mbed.h>
#include <Nokia5110.h>

namespace OSHWatch {

extern const uint8_t *digits[10];

class Watchface : public Screen {
public:
    Watchface();

    void draw();

    void processInput(uint8_t button);

private:
    bool _colon = true;
};
}

#endif //OSHWATCH_WATCHFACE_H
