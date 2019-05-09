#ifndef ENUMARATION_H
#define ENUMARATION_H
#include "libraries.h"

enum dayOfWeek {M = 1, TU, W, TH, F, SA, SN};

string getDay(dayOfWeek d)
{
    switch (d) {
    case M:
        return "Monday";
    case TU:
        return "Tuesday";
    case W:
        return "Wednesday";
    case TH:
        return "Thursday";
    case F:
        return "Friday";
    case SA:
        return "Saturday";
    case SN:
        return "Sunday";
    default:
        return "You typed something wrong";
    }
}

#endif // ENUMARATION_H
