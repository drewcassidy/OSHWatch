#include "pins.h"
#include "Screen.h"
#include "Watchface.h"
#include "peripherals.h"
#include "datetime.h"

#include <Nokia5110.h>
#include <mbed.h>

#define COLON_BLINK true
#define TWELVE_HOUR true

#define TIME_ROW 0
#define DATE_ROW TIME_ROW + 22

namespace OSHWatch {

const uint8_t *digits[10] = {
    Digit0,
    Digit1,
    Digit2,
    Digit3,
    Digit4,
    Digit5,
    Digit6,
    Digit7,
    Digit8,
    Digit9
};

Watchface::Watchface() {
}

void Watchface::draw() {
    display->clear_buffer();

    datetime_t *curr_datetime = get_datetime();

    uint8_t tmp_hours = curr_datetime->hours;

    if (TWELVE_HOUR) {
        if (tmp_hours > 12) {
            tmp_hours -= 12;
            display->print_string("PM", 70, TIME_ROW + 18);
        } else {
            display->print_string("AM", 70, TIME_ROW + 18);
        }
        if (tmp_hours == 0) {
            tmp_hours = 12;
        }
        display->draw_hline(2, 67, TIME_ROW + 19, Nokia5110::pattern_grey); //dividing line
    } else {
        display->draw_hline(2, 81, TIME_ROW + 19, Nokia5110::pattern_grey); //fill the gap where the AM/PM would go
    }

    uint8_t hours_10   = tmp_hours / 10;
    uint8_t hours_1    = tmp_hours % 10;
    uint8_t minutes_10 = curr_datetime->minutes / 10;
    uint8_t minutes_1  = curr_datetime->minutes % 10;
    uint8_t date_10    = curr_datetime->date / 10;
    uint8_t date_1     = curr_datetime->date % 10;

    if (hours_10 != 0) { //dont draw leading zero, eg "03:15"
        display->draw_wbitmap(digits[hours_10], 0, TIME_ROW);
    }
    display->draw_wbitmap(digits[hours_1], 21, TIME_ROW);
    display->draw_wbitmap(digits[minutes_10], 45, TIME_ROW);
    display->draw_wbitmap(digits[minutes_1], 65, TIME_ROW);

    if (_colon) {
        display->fill_rrect(41, TIME_ROW + 4, 44, TIME_ROW + 7, 2);
        display->fill_rrect(41, TIME_ROW + 10, 44, TIME_ROW + 13, 2);
    }

    if (COLON_BLINK) {
        _colon = !_colon; //blink the colon once per draw
    }

    uint8_t col = 0;
    if (curr_datetime->day != DAY_Unknown) { //dont print the day of the week if its unknown
        col = display->print_string(days[curr_datetime->day], col, DATE_ROW, 3);
        col = display->print_char(',', col, DATE_ROW);
        col += 2;
    }
    col = display->print_string(months[curr_datetime->month], col, DATE_ROW, 3);
    col += 3;
    col = display->print_char('0' + date_10, col, DATE_ROW);
    col = display->print_char('0' + date_1, col, DATE_ROW);

    //sample message, implement properly later
    display->draw_wbitmap(IconMessage, 0, 32);
    display->print_string("foo: Hello!", 18, 32);
    display->print_string("sample msg", 18, 40);

    //print the buffer to the screen
    display->display();
}

void Watchface::processInput(uint8_t button) {}
}
