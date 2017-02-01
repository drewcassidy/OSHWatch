#include "pins.h"
#include "datetime.h"
#include "peripherals.h"
#include "Screen.h"
#include "screens/Mainscreen.h"
#include <mbed.h>
#include <Nokia5110.h>
#include <BQ32000.h>

using namespace OSHWatch;

#define TICK_FREQ 1

Ticker     _ticker           = Ticker();
uint8_t    _ticker_collector = 0;
Mainscreen _mainscreen       = Mainscreen();

void tick() {
    _mainscreen.draw();

    _ticker_collector++;
    if (_ticker_collector == TICK_FREQ) {
        _ticker_collector = 0;
        datetime_increment(1);
    }
}

int main() {
    // write current time to rtc
    datetime_parse((char *) __DATE__, (char *) __TIME__);
    datetime_write();

    // initialize display
    display->init(0x2F);

    // attach ticker to tick()
    _ticker.attach(tick, 1.0 / TICK_FREQ);



    // when anything exits, it goes back to here and sleeps... probably
    while (true) {
        sleep();
    }
}

