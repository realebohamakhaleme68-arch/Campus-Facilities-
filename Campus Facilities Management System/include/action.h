#ifndef ACTION_H
#define ACTION_H

#include "Resource.h"

class Action {

    public:
        enum class Type {
            ADD,
            REMOVE,
            UPDATE
    };

        Type     type;
        Resource before;
        Resource after;

        Action();
        Action(Type, Resource&, Resource&);
};

#endif