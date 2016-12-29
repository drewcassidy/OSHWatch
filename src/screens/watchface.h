#ifndef WATCHFACE_H
#define WATCHFACE_H

#include "screen.h"
#include "bitmaps.h"

#include <mbed.h>
#include <Nokia5110.h>

class Watchface : public Screen {
  public:
    Watchface(Nokia5110 *display);
    void draw();
    void processInput(uint8_t button);

  private:
    const uint8_t *getDigit(uint8_t value);
    Nokia5110 *_display;
};

#endif
