#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class LinkedList {

private:
    class Node {
    public:
        T     data;
        Node* next;

        Node();
    };

    Node* head;
    Node* tail;
    int   count;

public:
    LinkedList();
    ~LinkedList();

    int  size();
    bool isEmpty();

    void insertAtBeginning(T&);
    void insertAtEnd(T&);
    void insertAtPosition(int, T&);

    bool removeAtPosition(int);
    void clear();

    T* getAt(int);

    T* toArray();
};

#endif
