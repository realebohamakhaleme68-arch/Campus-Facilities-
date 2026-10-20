#include "BookingManager.h"
#include "TimetableParser.h"
#include <fstream>
#include <iostream>

int BookingManager::loadUniversity(string path) {
    return TimetableParser::parseTimetable(path, universityBookings);
}

int BookingManager::loadUser(string path) {
    ifstream in(path.c_str());
    if (!in.is_open()) return 0;
    string line; int count = 0;
    while (getline(in, line)) {
        if (line.empty()) continue;
        Booking b;
        if (Booking::fromFileString(line, b)) {
            userBookings.insertAtEnd(b);
            count++;
        }
    }
    in.close();
    return count;
}

bool BookingManager::saveUser(string path) {
    ofstream out(path.c_str());
    if (!out.is_open()) return false;
    for (int i = 0; i < userBookings.size(); i++) {
        out << userBookings.getAt(i)->toFileString() << "\n";
    }
    out.close();
    return true;
}

bool BookingManager::isFree(string roomID, string day, string time) {
    for (int i = 0; i < universityBookings.size(); i++) {
        Booking* b = universityBookings.getAt(i);
        if (b->roomID == roomID && b->day == day) {
            if (time >= b->startTime && time < b->endTime) return false;
        }
    }
    for (int i = 0; i < userBookings.size(); i++) {
        Booking* b = userBookings.getAt(i);
        if (b->roomID == roomID && b->day == day) {
            if (time >= b->startTime && time < b->endTime) return false;
        }
    }
    return true;
}

bool BookingManager::addUserBooking(Booking& b) {
    if (!isFree(b.roomID, b.day, b.startTime)) return false;
    userBookings.insertAtEnd(b);
    return true;
}

void BookingManager::displayAll() {
    cout << "\n--- UNIVERSITY BOOKINGS ---\n";
    for (int i = 0; i < universityBookings.size(); i++) universityBookings.getAt(i)->display();
    cout << "\n--- USER BOOKINGS ---\n";
    if (userBookings.isEmpty()) { cout << "None.\n"; return; }
    for (int i = 0; i < userBookings.size(); i++) userBookings.getAt(i)->display();
}

void BookingManager::displayForRoom(string roomID) {
    cout << "\nBookings for " << roomID << ":\n";
    for (int i = 0; i < universityBookings.size(); i++) {
        if (universityBookings.getAt(i)->roomID == roomID) universityBookings.getAt(i)->display();
    }
    for (int i = 0; i < userBookings.size(); i++) {
        if (userBookings.getAt(i)->roomID == roomID) userBookings.getAt(i)->display();
    }
}
