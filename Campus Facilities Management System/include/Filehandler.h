#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include "ResourceManager.h"

using namespace std;

class FileHandler {

    public:
        static int  loadResources(string&, ResourceManager&);
        static bool saveResources(string&, ResourceManager&);
};

#endif
