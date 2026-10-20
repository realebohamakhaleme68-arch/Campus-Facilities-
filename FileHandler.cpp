#include "FileHandler.h"
#include <fstream>
#include <sstream>
#include <iostream>

int FileHandler::loadResources(string path, ResourceManager& mgr) {
    ifstream in(path.c_str());
    if (!in.is_open()) { cout << "Note: " << path << " not found.\n"; return -1; }
    string line; int loaded = 0; int skipped = 0;
    while (getline(in, line)) {
        if (line.size() == 0 || line[0] == '#') continue;
        Resource r;
        if (Resource::fromFileString(line, r)) {
            if (mgr.addResource(r)) loaded++; else skipped++;
        } else { skipped++; }
    }
    in.close();
    cout << loaded << " resources loaded";
    if (skipped > 0) cout << " (" << skipped << " skipped)";
    cout << "\n";
    return loaded;
}

bool FileHandler::saveResources(string path, ResourceManager& mgr) {
    ofstream out(path.c_str());
    if (!out.is_open()) { cout << "Error: could not write " << path << "\n"; return false; }
    for (int i = 0; i < mgr.count(); i++) {
        out << mgr.getList().getAt(i)->toFileString() << "\n";
    }
    out.close();
    return true;
}
