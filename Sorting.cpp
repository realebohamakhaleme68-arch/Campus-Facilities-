#include "Sorting.h"

long insertionSort(Resource arr[], int n, Comparator less) {
    long comparisons = 0;
    for (int i = 1; i < n; i++) {
        Resource key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            comparisons++;
            if (less(key, arr[j])) { arr[j + 1] = arr[j]; j--; } else break;
        }
        arr[j + 1] = key;
    }
    return comparisons;
}

long mergeCombine(Resource arr[], Resource tmp[], int lo, int mid, int hi, Comparator less) {
    long comparisons = 0; int i = lo; int j = mid + 1; int k = lo;
    while (i <= mid && j <= hi) {
        comparisons++;
        if (less(arr[j], arr[i])) { tmp[k] = arr[j]; k++; j++; } 
        else { tmp[k] = arr[i]; k++; i++; }
    }
    while (i <= mid) { tmp[k] = arr[i]; k++; i++; }
    while (j <= hi) { tmp[k] = arr[j]; k++; j++; }
    for (int x = lo; x <= hi; x++) arr[x] = tmp[x];
    return comparisons;
}

long mergeRecursive(Resource arr[], Resource tmp[], int lo, int hi, Comparator less) {
    if (lo >= hi) return 0;
    int mid = lo + (hi - lo) / 2;
    long comparisons = 0;
    comparisons += mergeRecursive(arr, tmp, lo, mid, less);
    comparisons += mergeRecursive(arr, tmp, mid + 1, hi, less);
    comparisons += mergeCombine(arr, tmp, lo, mid, hi, less);
    return comparisons;
}

long mergeSort(Resource arr[], int n, Comparator less) {
    if (n <= 1) return 0;
    Resource* tmp = new Resource[n];
    long comparisons = mergeRecursive(arr, tmp, 0, n - 1, less);
    delete[] tmp;
    return comparisons;
}

int linearSearchByID(Resource arr[], int n, string& id) {
    for (int i = 0; i < n; i++) if (arr[i].getID() == id) return i;
    return -1;
}

int binarySearchByID(Resource arr[], int n, string& id) {
    int lo = 0; int hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid].getID() == id) return mid;
        else if (arr[mid].getID() < id) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}
