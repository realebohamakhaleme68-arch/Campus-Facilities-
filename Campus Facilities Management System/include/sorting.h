#ifndef SORTING_H
#define SORTING_H

#include "Resource.h"

using namespace std;
class sorter{
    public:

        typedef bool (*Comparator)(Resource&, Resource&);

        long insertionSort(Resource[], int, Comparator);
        long mergeSort(Resource[], int, Comparator);

        int linearSearchByID(Resource[], int, string&);
        int binarySearchByID(Resource[], int, string&);

};
#endif
