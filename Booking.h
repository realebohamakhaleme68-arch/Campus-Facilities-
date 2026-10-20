#ifndef BOOKING_H
#define BOOKING_H

#include <string>
using namespace std;

class Booking {
public:
    string roomID;
    string day;
    string startTime;
    string endTime;
    string bookerName;
    string bookerType;
    string bookerID;
    bool   isUniversity;

    Booking();
    Booking(string, string, string, string, string, string, string, bool);

    string toFileString();
    static bool fromFileString(string, Booking&);
    void display();
};

#endif
