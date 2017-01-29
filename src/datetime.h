#ifndef OSHWATCH_DATETIME_H
#define OSHWATCH_DATETIME_H

#include <stdint.h>

namespace OSHWatch {

enum DayOfWeek {
    DAY_Unknown,
    DAY_Monday,
    DAY_Tuesday,
    DAY_Wednesday,
    DAY_Thursday,
    DAY_Friday,
    DAY_Saturday,
    DAY_Sunday
};

struct datetime_t {
    uint16_t  year;
    uint8_t   month;
    uint8_t   date;
    uint8_t   hours;
    uint8_t   minutes;
    uint8_t   seconds;
    DayOfWeek day;
};

extern datetime_t *_curr_datetime;

void datetime_parse(char *datestr, char *timestr);

void datetime_increment(uint8_t seconds);

void datetime_write();

void datetime_read();

datetime_t *get_datetime();
}

#endif //OSHWATCH_DATETIME_H
