#include "ResourceManager.h"
#include <iostream>
#include <sstream>

string myIntToString(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

// Changed & to value
bool ResourceManager::idExists(string id) {
    for (int i = 0; i < resources.size(); i++)
        if (resources.getAt(i)->getID() == id) return true;
    return false;
}

bool ResourceManager::addResource(Resource& r) {
    if (idExists(r.getID())) return false;
    resources.insertAtEnd(r);
    return true;
}

// Changed & to value
bool ResourceManager::removeResource(string id, Resource* out) {
    for (int i = 0; i < resources.size(); i++) {
        if (resources.getAt(i)->getID() == id) {
            if (out != NULL) *out = *resources.getAt(i);
            return resources.removeAtPosition(i);
        }
    }
    return false;
}

bool ResourceManager::updateResource(string id, Resource& newData) {
    for (int i = 0; i < resources.size(); i++) {
        Resource* target = resources.getAt(i);
        if (target->getID() == id) {
            target->setName(newData.getName()); 
            target->setType(newData.getType());
            target->setLocation(newData.getLocation()); 
            target->setCapacity(newData.getCapacity());
            target->setStatus(newData.getStatus());
            return true;
        }
    }
    return false;
}

bool ResourceManager::findResource(string id, Resource& out) {
    for (int i = 0; i < resources.size(); i++) {
        if (resources.getAt(i)->getID() == id) { out = *resources.getAt(i); return true; }
    }
    return false;
}

void ResourceManager::displayAll() {
    if (resources.isEmpty()) { cout << "No resources.\n"; return; }
    for (int i = 0; i < resources.size(); i++) resources.getAt(i)->display();
}

int ResourceManager::count() { return resources.size(); }
LinkedList<Resource>& ResourceManager::getList() { return resources; }
Resource* ResourceManager::toArray() { return resources.toArray(); }

bool ResourceManager::removeBuilding(string buildingName) {
    bool removedAny = false;
    for (int i = resources.size() - 1; i >= 0; i--) {
        Resource* r = resources.getAt(i);
        if (r->getLocation() == buildingName) { resources.removeAtPosition(i); removedAny = true; }
    }
    return removedAny;
}

int ResourceManager::addBuilding(string buildingName, string prefix, string roomType, int startNumber, int endNumber, int capacity) {
    int added = 0;
    for (int i = startNumber; i <= endNumber; i++) {
        string id = prefix + "-" + myIntToString(i);
        string name = roomType + " " + myIntToString(i);
        Resource r(id, name, roomType, buildingName, capacity, AVAILABLE);
        if (addResource(r)) added++;
    }
    return added;
}
