#include <cstring>
#include <cstdlib>
#include "datetime.h"
#include "peripherals.h"

namespace OSHWatch {

datetime_t *_curr_datetime = (datetime_t *) malloc(sizeof(datetime_t));

const char *months[13] = {
    "????month", "January", "February",
    "March", "April", "May", "June",
    "July", "August", "September",
    "October", "November", "December"
};

const char *days[8] = {
    "??????day", "Monday", "Tuesday", "Wednesday",
    "Thursday", "Friday", "Saturday", "Sunday"
};

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

    _curr_datetime->day = DAY_Sunday;
    for (uint8_t i = 1; i <= 12; i++) {
        if (memcmp(months[i], _month, 3) == 0) {
            _curr_datetime->month = i;
            return;
        }
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
    rtc->write_buffer();
}

void datetime_read() {
    rtc->read_buffer();
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
