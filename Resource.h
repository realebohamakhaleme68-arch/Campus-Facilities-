#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>

using namespace std;

enum Status {
    AVAILABLE,
    BOOKED,
    MAINTENANCE
};

class Resource {

private:
    string resourceID;
    string name;
    string type;
    string location;
    int    capacity;
    Status status;

public:
    Resource();
    Resource(string, string, string, string, int, Status); // Changed & to value

    string getID();
    string getName();
    string getType();
    string getLocation();
    int    getCapacity();
    Status getStatus();

    void setName(string);
    void setType(string);
    void setLocation(string);
    void setCapacity(int);
    void setStatus(Status);

    void        display();
    string      toFileString();
    static bool fromFileString(string, Resource&);

    static string statusToString(Status);
    static Status stringToStatus(string);

    static bool compareByID(Resource&, Resource&);
    static bool compareByName(Resource&, Resource&);
    static bool compareByCapacity(Resource&, Resource&);
    static bool compareByType(Resource&, Resource&);
};

#endif
