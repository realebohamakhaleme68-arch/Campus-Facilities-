#ifndef LINKEDLIST_H
#define LINKEDLIST_H
template <class T>
class Node{
    public:
        T data:
        Node<T>* next:
        Node(T);
};

template <class T>
class LinkedList {
    private:
        Node<T>* head;
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