#include "dataGenerator.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

string intToStr(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

string pad3(int n) { 
    string s = intToStr(n); 
    while (s.size() < 3) s = "0" + s; 
    return s; 
}

bool makeRoom(ResourceManager& mgr, string id, string name, string type, string location, int capacity) {
    Resource r(id, name, type, location, capacity, AVAILABLE);
    return mgr.addResource(r);
}

void generateAllBuildings(ResourceManager& mgr) {
    cout << "Generating campus data...\n";
    string b;

    b = "Science Building";
    for (int i = 1; i <= 3; i++) makeRoom(mgr, "SCE-P" + pad3(i), "Physics Lab " + intToStr(i), "Lab", b, 30);
    for (int i = 1; i <= 3; i++) makeRoom(mgr, "SCE-C" + pad3(i), "Chemistry Lab " + intToStr(i), "Lab", b, 30);
    makeRoom(mgr, "SCE-COMP", "Computer Lab", "Lab", b, 40);
    for (int i = 101; i <= 115; i++) makeRoom(mgr, "SCE-" + intToStr(i), "Office " + intToStr(i), "Office", b, 2);
    makeRoom(mgr, "SCE-HALL", "SLT-HALL", "Lecture Room", b, 100);
    for (int i = 1; i <= 4; i++) makeRoom(mgr, "SCE-T" + pad3(i), "Toilet " + intToStr(i), "Toilet", b, 4);

    b = "Agriculture Building";
    for (int i = 101; i <= 176; i++) makeRoom(mgr, "AGR-" + intToStr(i), "Office " + intToStr(i), "Office", b, 2);
    for (int i = 1; i <= 4; i++) makeRoom(mgr, "AGR-T" + pad3(i), "Toilet " + intToStr(i), "Toilet", b, 4);

    b = "BTM";
    for (int i = 101; i <= 126; i++) makeRoom(mgr, "BTM-" + intToStr(i), "Lecture Room " + intToStr(i), "Lecture Room", b, 80);
    for (int i = 201; i <= 211; i++) makeRoom(mgr, "BTM-" + intToStr(i), "Office " + intToStr(i), "Office", b, 2);
    for (int i = 1; i <= 8; i++) makeRoom(mgr, "BTM-T" + pad3(i), "Toilet " + intToStr(i), "Toilet", b, 4);

    b = "ETF";
    for (int i = 1; i <= 3; i++) makeRoom(mgr, "ETF-" + pad3(i), "Room " + intToStr(i), "Lecture Room", b, 60);
    for (int i = 1; i <= 4; i++) makeRoom(mgr, "ETF-T" + pad3(i), "Toilet " + intToStr(i), "Toilet", b, 4);

    b = "DTF";
    for (int i = 101; i <= 121; i++) makeRoom(mgr, "DTF-" + intToStr(i), "Room " + intToStr(i), "Lecture Room", b, 60);
    for (int i = 1; i <= 8; i++) makeRoom(mgr, "DTF-T" + pad3(i), "Toilet " + intToStr(i), "Toilet", b, 4);

    b = "FTF";
    for (int i = 101; i <= 119; i++) makeRoom(mgr, "FTF-" + intToStr(i), "Room " + intToStr(i), "Lecture Room", b, 60);
    makeRoom(mgr, "FTF-207", "Computer Lab 207", "Lab", b, 40);
    for (int i = 1; i <= 8; i++) makeRoom(mgr, "FTF-T" + pad3(i), "Toilet " + intToStr(i), "Toilet", b, 4);

    b = "CMP";
    for (int i = 101; i <= 107; i++) makeRoom(mgr, "CMP-" + intToStr(i), "Lecture Room " + intToStr(i), "Lecture Room", b, 80);
    for (int i = 201; i <= 211; i++) makeRoom(mgr, "CMP-" + intToStr(i), "Office " + intToStr(i), "Office", b, 2);
    for (int i = 1; i <= 8; i++) makeRoom(mgr, "CMP-T" + pad3(i), "Toilet " + intToStr(i), "Toilet", b, 4);

    b = "Boitjaro";
    for (int i = 101; i <= 121; i++) makeRoom(mgr, "BOI-" + intToStr(i), "Office " + intToStr(i), "Office", b, 2);
    for (int i = 1; i <= 8; i++) makeRoom(mgr, "BOI-T" + pad3(i), "Toilet " + intToStr(i), "Toilet", b, 4);

    b = "Admin";
    for (int i = 101; i <= 131; i++) makeRoom(mgr, "ADM-" + intToStr(i), "Office " + intToStr(i), "Office", b, 2);
    for (int i = 1; i <= 4; i++) makeRoom(mgr, "ADM-T" + pad3(i), "Toilet " + intToStr(i), "Toilet", b, 4);

    b = "Academic Office";
    for (int i = 101; i <= 111; i++) makeRoom(mgr, "ACD-" + intToStr(i), "Office " + intToStr(i), "Office", b, 2);
    for (int i = 1; i <= 4; i++) makeRoom(mgr, "ACD-T" + pad3(i), "Toilet " + intToStr(i), "Toilet", b, 4);

    b = "Netherlands Hall";
    makeRoom(mgr, "NTH-HALL", "Netherlands Main Hall", "Hall", b, 500);
    makeRoom(mgr, "NTH-B001", "Back Room 1", "Office", b, 2);
    makeRoom(mgr, "NTH-T001", "Male Toilet", "Toilet", b, 4);
    makeRoom(mgr, "NTH-T002", "Female Toilet", "Toilet", b, 4);

    b = "Cafeteria";
    makeRoom(mgr, "CAF-BAK", "Bakery", "Cafeteria", b, 10);
    makeRoom(mgr, "CAF-MAIN", "Cafeteria", "Cafeteria", b, 50);
    for (int i = 1; i <= 4; i++) makeRoom(mgr, "CAF-T" + pad3(i), "Toilet " + intToStr(i), "Toilet", b, 4);

    b = "Highlands";
    for (int i = 101; i <= 121; i++) makeRoom(mgr, "HIG-" + intToStr(i), "Office " + intToStr(i), "Office", b, 2);
    for (int i = 1; i <= 4; i++) makeRoom(mgr, "HIG-T" + pad3(i), "Toilet " + intToStr(i), "Toilet", b, 4);

    b = "Statistics Department";
    for (int i = 101; i <= 121; i++) makeRoom(mgr, "STA-" + intToStr(i), "Office " + intToStr(i), "Office", b, 2);
    for (int i = 1; i <= 4; i++) makeRoom(mgr, "STA-T" + pad3(i), "Toilet " + intToStr(i), "Toilet", b, 4);

    b = "Law Department";
    for (int i = 101; i <= 121; i++) makeRoom(mgr, "LAW-" + intToStr(i), "Office " + intToStr(i), "Office", b, 2);
    for (int i = 1; i <= 4; i++) makeRoom(mgr, "LAW-T" + pad3(i), "Toilet " + intToStr(i), "Toilet", b, 4);

    b = "ICT Lab";
    makeRoom(mgr, "ICT-LAB", "ICT Lab", "Lab", b, 40);
    makeRoom(mgr, "ICT-OFF", "ICT Office", "Office", b, 2);

    b = "Cisco Lab";
    makeRoom(mgr, "CIS-LAB", "Cisco Lab", "Lab", b, 40);
    makeRoom(mgr, "CIS-OFF", "Cisco Office", "Office", b, 2);

    b = "ISAS";
    for (int i = 101; i <= 131; i++) makeRoom(mgr, "ISAS-" + intToStr(i), "Office " + intToStr(i), "Office", b, 2);
    for (int i = 201; i <= 204; i++) makeRoom(mgr, "ISAS-" + intToStr(i), "Conference Room " + intToStr(i), "Conference Room", b, 15);
    for (int i = 1; i <= 4; i++) makeRoom(mgr, "ISAS-T" + pad3(i), "Toilet " + intToStr(i), "Toilet", b, 4);

    cout << "Done. Total resources: " << mgr.count() << "\n";
}
