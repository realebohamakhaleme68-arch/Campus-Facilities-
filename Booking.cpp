#include "Booking.h"
#include <iostream>
#include <sstream>

Booking::Booking() {
    roomID = ""; day = ""; startTime = ""; endTime = "";
    bookerName = ""; bookerType = ""; bookerID = ""; isUniversity = false;
}

Booking::Booking(string room, string d, string start, string end, string name, string type, string id, bool uni) {
    roomID = room; day = d; startTime = start; endTime = end;
    bookerName = name; bookerType = type; bookerID = id; isUniversity = uni;
}

string Booking::toFileString() {
    return roomID + "|" + day + "|" + startTime + "|" + endTime + "|" +
           bookerName + "|" + bookerType + "|" + bookerID + "|" +
           (isUniversity ? "1" : "0");
}

bool Booking::fromFileString(string line, Booking& out) {
    stringstream ss(line);
    string r, d, s, e, n, t, id, u;
    if (!getline(ss, r, '|')) return false;
    if (!getline(ss, d, '|')) return false;
    if (!getline(ss, s, '|')) return false;
    if (!getline(ss, e, '|')) return false;
    if (!getline(ss, n, '|')) return false;
    if (!getline(ss, t, '|')) return false;
    if (!getline(ss, id, '|')) return false;
    if (!getline(ss, u, '|')) return false;
    out = Booking(r, d, s, e, n, t, id, (u == "1"));
    return true;
}

void Booking::display() {
    cout << roomID << " | " << day << " | " << startTime << "-" << endTime
         << " | " << bookerName << " (" << bookerType << ")\n";
}
