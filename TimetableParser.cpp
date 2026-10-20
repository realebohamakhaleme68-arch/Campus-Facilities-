#include "TimetableParser.h"
#include <fstream>
#include <iostream>
#include <sstream>

int TimetableParser::parseTimetable(string path, LinkedList<Booking>& bookings) {
    ifstream in(path.c_str());
    if (!in.is_open()) { cout << "No timetable file found.\n"; return 0; }
    
    string line; string currentRoom = ""; string currentDay = "";
    int count = 0;
    
    while (getline(in, line)) {
        if (line.empty() || line[0] == '#' || line[0] == '=') continue;

        if (line.find("ROOM:") == 0) {
            currentRoom = line.substr(5);
            while (!currentRoom.empty() && currentRoom[0] == ' ') currentRoom.erase(0, 1);
            continue;
        }
        if (line.find("MONDAY:") == 0) { currentDay = "Monday"; continue; }
        if (line.find("TUESDAY:") == 0) { currentDay = "Tuesday"; continue; }
        if (line.find("WEDNESDAY:") == 0) { currentDay = "Wednesday"; continue; }
        if (line.find("THURSDAY:") == 0) { currentDay = "Thursday"; continue; }
        if (line.find("FRIDAY:") == 0) { currentDay = "Friday"; continue; }
        if (line.find("(No classes") != string::npos) continue;

        if (line.find("-") != string::npos && line.find(":") != string::npos) {
            stringstream ss(line);
            string start, dash, end, code, name, lecturer;
            ss >> start >> dash >> end;
            string rest;
            getline(ss, rest);
            
            string trimmedRest = rest;
            while (!trimmedRest.empty() && trimmedRest[0] == ' ') trimmedRest.erase(0, 1);
            
            int lastSpace = trimmedRest.rfind("  ");
            string booker = "Staff";
            string courseName = trimmedRest;
            if (lastSpace != string::npos) {
                booker = trimmedRest.substr(lastSpace + 2);
                courseName = trimmedRest.substr(0, lastSpace);
            }

            if (!currentRoom.empty() && !currentDay.empty()) {
                string type = "EMPLOYEE";
                string id = "N/A";
                Booking b(currentRoom, currentDay, start, end, booker, type, id, true);
                bookings.insertAtEnd(b);
                count++;
            }
        }
    }
    in.close();
    cout << count << " university bookings loaded.\n";
    return count;
}
