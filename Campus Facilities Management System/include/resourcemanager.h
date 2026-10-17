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
        bool removeResource(string&, Resource* = nullptr);
        bool updateResource(string&, Resource&);
        bool findResource(string&, Resource&);
        bool idExists(string&);

        void displayAll();
        int  count();

        LinkedList<Resource>& getList();
        Resource*             toArray();
};

#endif