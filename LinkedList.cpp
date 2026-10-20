#include "LinkedList.h"
#include "Resource.h"
#include "Booking.h"   

template <typename T>
LinkedList<T>::Node::Node() { next = NULL; }

template <typename T>
LinkedList<T>::LinkedList() { head = NULL; tail = NULL; count = 0; }

template <typename T>
LinkedList<T>::~LinkedList() { clear(); }

template <typename T>
int LinkedList<T>::size() { return count; }

template <typename T>
bool LinkedList<T>::isEmpty() { return count == 0; }

template <typename T>
void LinkedList<T>::insertAtBeginning(T& value) {
    Node* n = new Node(); n->data = value; n->next = head; head = n;
    if (tail == NULL) tail = n;
    count++;
}

template <typename T>
void LinkedList<T>::insertAtEnd(T& value) {
    Node* n = new Node(); n->data = value;
    if (tail == NULL) { head = n; tail = n; } 
    else { tail->next = n; tail = n; }
    count++;
}

template <typename T>
void LinkedList<T>::insertAtPosition(int position, T& value) {
    if (position <= 0) { insertAtBeginning(value); return; }
    if (position >= count) { insertAtEnd(value); return; }
    Node* before = head;
    for (int i = 0; i < position - 1; i++) before = before->next;
    Node* n = new Node(); n->data = value; n->next = before->next; before->next = n;
    count++;
}

template <typename T>
bool LinkedList<T>::removeAtPosition(int position) {
    if (position < 0 || position >= count) return false;
    Node* toDelete;
    if (position == 0) {
        toDelete = head; head = head->next;
        if (head == NULL) tail = NULL;
    } else {
        Node* before = head;
        for (int i = 0; i < position - 1; i++) before = before->next;
        toDelete = before->next; before->next = toDelete->next;
        if (toDelete == tail) tail = before;
    }
    delete toDelete; count--; return true;
}

template <typename T>
void LinkedList<T>::clear() {
    Node* current = head;
    while (current != NULL) {
        Node* nextNode = current->next; delete current; current = nextNode;
    }
    head = NULL; tail = NULL; count = 0;
}

template <typename T>
T* LinkedList<T>::getAt(int position) {
    if (position < 0 || position >= count) return NULL;
    Node* current = head;
    for (int i = 0; i < position; i++) current = current->next;
    return &current->data;
}

template <typename T>
T* LinkedList<T>::toArray() {
    T* array = new T[count]; Node* current = head;
    for (int i = 0; i < count; i++) { array[i] = current->data; current = current->next; }
    return array;
}


template class LinkedList<Resource>;
template class LinkedList<Booking>; 
