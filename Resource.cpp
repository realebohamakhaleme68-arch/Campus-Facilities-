#include "Resource.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>

string myToString(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

Resource::Resource() {
    resourceID = ""; name = ""; type = ""; location = ""; capacity = 0; status = AVAILABLE;
}

Resource::Resource(string id, string n, string t, string loc, int c, Status s) {
    resourceID = id; name = n; type = t; location = loc; capacity = c; status = s;
}

string Resource::getID()       { return resourceID; }
string Resource::getName()     { return name;       }
string Resource::getType()     { return type;       }
string Resource::getLocation() { return location;   }
int    Resource::getCapacity() { return capacity;   }
Status Resource::getStatus()   { return status;     }

void Resource::setName(string n)     { name = n; }
void Resource::setType(string t)     { type = t; }
void Resource::setLocation(string l) { location = l; }
void Resource::setCapacity(int c)    { if (c >= 0) capacity = c; }
void Resource::setStatus(Status s)   { status = s; }

// ============================================================
// Updated display() to hide status for non-bookable rooms
// ============================================================
void Resource::display() {
    cout << left << setw(12) << resourceID << setw(22) << name << setw(18) << type
         << setw(20) << location << setw(8) << capacity;

    // Only show status for rooms that can be booked
    if (type == "Lecture Room" || type == "Lab" || type == "Hall" || type == "Conference Room") {
        cout << statusToString(status);
    } else {
        cout << "-"; 
    }
    cout << "\n";
}

string Resource::toFileString() {
    return resourceID + "|" + name + "|" + type + "|" + location + "|" +
           myToString(capacity) + "|" + statusToString(status);
}

bool Resource::fromFileString(string line, Resource& out) {
    stringstream ss(line);
    string id, n, t, loc, capStr, statusStr;
    if (!getline(ss, id, '|')) return false;
    if (!getline(ss, n, '|')) return false;
    if (!getline(ss, t, '|')) return false;
    if (!getline(ss, loc, '|')) return false;
    if (!getline(ss, capStr, '|')) return false;
    if (!getline(ss, statusStr)) return false;

    int cap = 0;
    if (capStr.size() > 0) {
        cap = atoi(capStr.c_str());
    }

    Status st = stringToStatus(statusStr);
    out = Resource(id, n, t, loc, cap, st);
    return true;
}

string Resource::statusToString(Status s) {
    if (s == BOOKED) return "Booked";
    if (s == MAINTENANCE) return "Maintenance";
    return "Available";
}

Status Resource::stringToStatus(string s) {
    if (s == "Booked") return BOOKED;
    if (s == "Maintenance") return MAINTENANCE;
    return AVAILABLE;
}

bool Resource::compareByID(Resource& a, Resource& b)       { return a.getID() < b.getID(); }
bool Resource::compareByName(Resource& a, Resource& b)     { return a.getName() < b.getName(); }
bool Resource::compareByCapacity(Resource& a, Resource& b) { return a.getCapacity() < b.getCapacity(); }
bool Resource::compareByType(Resource& a, Resource& b)     { return a.getType() < b.getType(); }
