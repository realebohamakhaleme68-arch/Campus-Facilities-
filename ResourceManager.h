#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <string>
#include "LinkedList.h"
#include "Resource.h"

using namespace std;

class ResourceManager {
private:
    LinkedList<Resource> resources;
public:
    bool addResource(Resource&);
    bool removeResource(string, Resource* = NULL); // Changed & to value
    bool updateResource(string, Resource&);        // Changed & to value
    bool findResource(string, Resource&);          // Changed & to value
    bool idExists(string);                         // Changed & to value
    
    void displayAll();
    int  count();
    
    LinkedList<Resource>& getList();
    Resource* toArray();
    
    bool removeBuilding(string);                   // Changed & to value
    int  addBuilding(string, string, string, int, int, int); // Changed all & to value
};

#endif
