#include "pins.h"
#include "Screen.h"
#include "Watchface.h"
#include "peripherals.h"
#include "datetime.h"

#include <Nokia5110.h>
#include <mbed.h>

namespace OSHWatch {

Watchface::Watchface() {
}

void Watchface::draw() {
    display->clear_buffer();

    datetime_t *curr_datetime = get_datetime();

    uint8_t hours_10   = curr_datetime->hours / 10;
    uint8_t hours_1    = curr_datetime->hours % 10;
    uint8_t minutes_10 = curr_datetime->minutes / 10;
    uint8_t minutes_1  = curr_datetime->minutes % 10;
    //uint8_t seconds    = curr_datetime->seconds;

    I2C bus = I2C(SDA, SCL);
    char val = 0;
    bus.write(0xD0, &val, 1, true);
    bus.write(0xD0, &val, 1);
    char *seconds_str = (char *) malloc(3);
    sprintf(seconds_str, "%02x", rtc->read_byte(rtc->REG_Seconds));
    display->print_string(seconds_str, 70, 34);

    display->draw_wbitmap(getDigit(hours_10), 0, 16);
    display->draw_wbitmap(getDigit(hours_1), 20, 16);
    display->draw_wbitmap(getDigit(minutes_10), 46, 16);
    display->draw_wbitmap(getDigit(minutes_1), 64, 16);

    if (_colon) {
        display->fill_rect(41, 21, 44, 22);
        display->fill_rect(42, 20, 43, 23);
        display->fill_rect(41, 28, 44, 29);
        display->fill_rect(42, 27, 43, 30);
    }
    _colon = !_colon;
    display->display();
}

const uint8_t *Watchface::getDigit(uint8_t value) {
    switch (value) {
    default:
    case 0:
        return Digit0;
        break;
    case 1:
        return Digit1;
        break;
    case 2:
        return Digit2;
        break;
    case 3:
        return Digit3;
        break;
    case 4:
        return Digit4;
        break;
    case 5:
        return Digit5;
        break;
    case 6:
        return Digit6;
        break;
    case 7:
        return Digit7;
        break;
    case 8:
        return Digit8;
        break;
    case 9:
        return Digit9;
        break;
    }
}

void Watchface::processInput(uint8_t button) {}
}
