#include <iostream>
#include <string>
#include <fstream>

#include "Resource.h"
#include "LinkedList.h"
#include "ResourceManager.h"
#include "Sorting.h"
#include "FileHandler.h"
#include "dataGenerator.h"
#include "Booking.h"
#include "TimetableParser.h"
#include "BookingManager.h"

using namespace std;

void showMenu() {
    cout << "\n=== CS3400 CAMPUS RESOURCE MANAGEMENT ===\n";
    cout << "1. Display Resources\n";
    cout << "2. Search Resource by ID\n";
    cout << "3. Sort Resources\n";
    cout << "4. Add Resource\n";
    cout << "5. Remove Resource\n";
    cout << "6. Manage Buildings (Add/Remove)\n";
    cout << "7. Check if Room is Free\n";
    cout << "8. Book a Room\n";
    cout << "9. View All Bookings\n";
    cout << "0. Exit\n";
    cout << "Choice: ";
}

void displayMenu(ResourceManager& mgr) {
    cout << "1. Display ALL rooms\n";
    cout << "2. Display ONLY Bookable rooms (Lecture Rooms, Labs, Halls, Conference Rooms)\n";
    cout << "Choice: ";
    int c; cin >> c;

    for (int i = 0; i < mgr.count(); i++) {
        Resource* r = mgr.getList().getAt(i);
        if (c == 1) {
            r->display();
        } else if (c == 2) {
            string t = r->getType();
            if (t == "Lecture Room" || t == "Lab" || t == "Hall" || t == "Conference Room") {
                r->display();
            }
        }
    }
}

void searchMenu(ResourceManager& mgr) {
    cout << "Enter ID: ";
    string id; cin >> id;
    Resource r;
    if (mgr.findResource(id, r)) r.display();
    else cout << "Not found.\n";
}

void sortMenu(ResourceManager& mgr) {
    cout << "1. Sort by ID\n2. Sort by Name\n3. Sort by Capacity\nChoice: ";
    int c; cin >> c;
    if (c < 1 || c > 3) return;
    
    int n = mgr.count();
    Resource* arr = mgr.toArray();
    
    if (c == 1) mergeSort(arr, n, Resource::compareByID);
    else if (c == 2) mergeSort(arr, n, Resource::compareByName);
    else if (c == 3) mergeSort(arr, n, Resource::compareByCapacity);
    
    for (int i = 0; i < n; i++) arr[i].display();
    delete[] arr;
}

void addResourceMenu(ResourceManager& mgr) {
    string id, name, type, loc;
    int cap;
    cout << "ID: "; cin >> id;
    cout << "Name: "; cin >> name;
    cout << "Type (Office/Lab/Lecture Room/Hall/Toilet): "; cin >> type;
    cout << "Location (Building): "; cin >> loc;
    cout << "Capacity: "; cin >> cap;

    Resource r(id, name, type, loc, cap, AVAILABLE);
    if (mgr.addResource(r)) cout << "Added.\n";
    else cout << "Error: ID exists.\n";
}

void removeResourceMenu(ResourceManager& mgr) {
    cout << "ID to remove: ";
    string id; cin >> id;
    if (mgr.removeResource(id)) cout << "Removed.\n";
    else cout << "Not found.\n";
}

void buildingMenu(ResourceManager& mgr) {
    cout << "1. Add Building\n2. Remove Building\nChoice: ";
    int c; cin >> c;
    
    if (c == 1) {
        string b, prefix, type; int from, to, cap;
        cout << "Building Name: "; cin >> b;
        cout << "Prefix (e.g. NEW): "; cin >> prefix;
        cout << "Room Type (e.g. Office): "; cin >> type;
        cout << "Start Number: "; cin >> from;
        cout << "End Number: "; cin >> to;
        cout << "Capacity: "; cin >> cap;
        int n = mgr.addBuilding(b, prefix, type, from, to, cap);
        cout << n << " rooms added to " << b << ".\n";
    } else if (c == 2) {
        string b;
        cout << "Building Name to remove: "; cin >> b;
        cout << "WARNING: This removes ALL rooms in " << b << ". Continue? (y/n): ";
        char y; cin >> y;
        if (y == 'y' || y == 'Y') {
            if (mgr.removeBuilding(b)) cout << "Building removed.\n";
            else cout << "No building found.\n";
        }
    }
}

void checkFreeMenu(BookingManager& bm) {
    string room, day, time;
    cout << "Room ID: "; cin >> room;
    cout << "Day (Monday/Tuesday/...): "; cin >> day;
    cout << "Time (e.g. 14:00): "; cin >> time;
    if (bm.isFree(room, day, time)) cout << "Room is FREE at that time.\n";
    else cout << "Room is OCCUPIED.\n";
}

void bookRoomMenu(BookingManager& bm) {
    string room, day, start, end, name, type, id;
    cout << "Room ID: "; cin >> room;
    cout << "Day: "; cin >> day;
    cout << "Start (HH:MM): "; cin >> start;
    cout << "End (HH:MM): "; cin >> end;
    
    cout << "Booker Type (STUDENT/EMPLOYEE/EXTERNAL): "; cin >> type;
    cout << "Booker Name: "; cin >> name;
    
    if (type == "STUDENT") {
        cout << "Student Number (must start with admission year): "; cin >> id;
    } else if (type == "EMPLOYEE") {
        cout << "Employee Number: "; cin >> id;
    } else {
        id = "R500/hr";
        cout << "External booking rate is R500/hr.\n";
    }

    Booking b(room, day, start, end, name, type, id, false);
    if (bm.addUserBooking(b)) cout << "Booking confirmed.\n";
    else cout << "Conflict: Room already booked at that time.\n";
}

int main() {
    ResourceManager mgr;
    BookingManager bm;
    string resPath = "data/resources.txt";
    string userBookPath = "data/bookings.txt";
    string uniBookPath = "data/university_timetable.txt";

    // Load or generate resources
    if (FileHandler::loadResources(resPath, mgr) < 0) {
        generateAllBuildings(mgr);
        FileHandler::saveResources(resPath, mgr);
    }

    // Load bookings
    bm.loadUniversity(uniBookPath);
    bm.loadUser(userBookPath);

    int choice;
    do {
        showMenu();
        cin >> choice;
        switch (choice) {
            case 1: displayMenu(mgr); break;
            case 2: searchMenu(mgr); break;
            case 3: sortMenu(mgr); break;
            case 4: addResourceMenu(mgr); break;
            case 5: removeResourceMenu(mgr); break;
            case 6: buildingMenu(mgr); break;
            case 7: checkFreeMenu(bm); break;
            case 8: bookRoomMenu(bm); break;
            case 9: bm.displayAll(); break;
            case 0: break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    // Save everything on exit
    FileHandler::saveResources(resPath, mgr);
    bm.saveUser(userBookPath);
    cout << "Data saved. Goodbye.\n";

    return 0;
}
