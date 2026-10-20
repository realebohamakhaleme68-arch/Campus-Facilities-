#ifndef TIMETABLEPARSER_H
#define TIMETABLEPARSER_H

#include <string>
#include "LinkedList.h"
#include "Booking.h"

using namespace std;

class TimetableParser {
public:
    static int parseTimetable(string, LinkedList<Booking>&);
};

#endif
