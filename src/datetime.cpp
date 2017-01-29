#include <cstring>
#include <cstdlib>
#include "datetime.h"
#include "peripherals.h"

namespace OSHWatch {

datetime_t *_curr_datetime = (datetime_t *) malloc(sizeof(datetime_t));

void datetime_parse(char *datestr, char *timestr) {
    char *_month = datestr;
    char *_date  = datestr + 4;
    char *_year  = datestr + 7;

    char *_hours   = timestr;
    char *_minutes = timestr + 3;
    char *_seconds = timestr + 6;

    _curr_datetime->date    = atoi(_date);
    _curr_datetime->year    = atoi(_year);
    _curr_datetime->hours   = atoi(_hours);
    _curr_datetime->minutes = atoi(_minutes);
    _curr_datetime->seconds = atoi(_seconds);

    if (memcmp("Jan", _month, 3) == 0) {
        _curr_datetime->month = 1;
    } else if (memcmp("Feb", _month, 3) == 0) {
        _curr_datetime->month = 2;
    } else if (memcmp("Mar", _month, 3) == 0) {
        _curr_datetime->month = 3;
    } else if (memcmp("Apr", _month, 3) == 0) {
        _curr_datetime->month = 4;
    } else if (memcmp("May", _month, 3) == 0) {
        _curr_datetime->month = 5;
    } else if (memcmp("Jun", _month, 3) == 0) {
        _curr_datetime->month = 6;
    } else if (memcmp("Jul", _month, 3) == 0) {
        _curr_datetime->month = 7;
    } else if (memcmp("Aug", _month, 3) == 0) {
        _curr_datetime->month = 8;
    } else if (memcmp("Sep", _month, 3) == 0) {
        _curr_datetime->month = 9;
    } else if (memcmp("Oct", _month, 3) == 0) {
        _curr_datetime->month = 10;
    } else if (memcmp("Nov", _month, 3) == 0) {
        _curr_datetime->month = 11;
    } else if (memcmp("Dec", _month, 3) == 0) {
        _curr_datetime->month = 12;
    } else {
        _curr_datetime->month = 0;
    }
}

void datetime_increment(uint8_t seconds) {
    _curr_datetime->seconds += seconds;

    if (_curr_datetime->seconds >= 60) {
        datetime_read();
    }
}

void datetime_write() {
    rtc->set_seconds(_curr_datetime->seconds);
    rtc->set_minutes(_curr_datetime->minutes);
    rtc->set_hours(_curr_datetime->hours);
    rtc->set_date(_curr_datetime->date);
    rtc->set_month(_curr_datetime->month);
    rtc->set_year(_curr_datetime->year);
    rtc->set_day((BQ32000::DayOfWeek) _curr_datetime->day);
}

void datetime_read() {
    _curr_datetime->seconds = rtc->get_seconds();
    _curr_datetime->minutes = rtc->get_minutes();
    _curr_datetime->hours   = rtc->get_hours();
    _curr_datetime->date    = rtc->get_date();
    _curr_datetime->month   = rtc->get_month();
    _curr_datetime->year    = rtc->get_year() + 2000;
    _curr_datetime->day     = (DayOfWeek) rtc->get_day();
}

datetime_t *get_datetime() {
    return _curr_datetime;
}
}
