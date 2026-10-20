#include "Action.h"

Action::Action() { type = ADD; }

Action::Action(Type t, Resource& b, Resource& a) {
    type = t; before = b; after = a;
}
