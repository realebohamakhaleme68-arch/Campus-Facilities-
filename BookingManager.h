#ifndef BOOKINGMANAGER_H
#define BOOKINGMANAGER_H

#include <string>
#include "LinkedList.h"
#include "Booking.h"

using namespace std;

class BookingManager {
private:
    LinkedList<Booking> universityBookings;
    LinkedList<Booking> userBookings;

public:
    int loadUniversity(string);
    int loadUser(string);
    bool saveUser(string);

    bool isFree(string, string, string);
    bool addUserBooking(Booking&);

    void displayAll();
    void displayForRoom(string);
};

#endif
