#include "Node.h"
#ifndef LIST_H
#define LIST_H
#include <iostream>
template <class T>
class List {
private:
    Node<T>* first;

public:
    List();
    ~List();
        
    int size() const;
    bool is_empty() const;
    void push_back(T e);
    T update(int i, T e);
    T get_at(int i) const;  
    void set_at(int i, T e);
    T delete_at(int i);
};
#endif
