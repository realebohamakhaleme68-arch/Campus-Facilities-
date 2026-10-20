#ifndef ACTION_H
#define ACTION_H

#include "Resource.h"

using namespace std;

class Action {
public:
    // Removed 'class' from enum
    enum Type {
        ADD,
        REMOVE,
        UPDATE
    };
    Type type;
    Resource before;
    Resource after;
    Action();
    Action(Type, Resource&, Resource&);
};

#endif
