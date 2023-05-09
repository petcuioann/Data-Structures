#include "List.h"


template<class T>
List<T>::List() {
    this->first = nullptr;
}

template <class T>
List<T>::~List() {
    Node<T>* current = first;
    while (current != nullptr) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
    first = nullptr;
}

template<class T>
int List<T>::size() const {
    int size = 0;
    Node<T>* current = first;
    while (current) {
        size++;
        current = current->next;
    }
    return size;
}

template <class T>
bool List<T>::is_empty() const {
    return first == nullptr;
}

template<class T>
void List<T>::push_back(T e) {
    Node<T>* new_node = new Node<T>(e);
    new_node->next = nullptr;
    if (first == nullptr) {
        first = new_node;
    }
    else {
        Node<T> *current = first;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
    }
}

template<class T>
T List<T>::update(int i, T e) {
    if (i < 0 || i >= size()) {
        throw std::out_of_range("Invalid index");
    }
    Node<T>* current = first;
    for (int j = 0; j < i; j++) {
        current = current->next;
    }
    T old_value = current->data;
    current->data = e;
    return old_value;
}

template<class T>
T List<T>::get_at(int i) const {
    if (i < 0 || i >= size()) {
        throw std::out_of_range("Invalid index");
    }
    Node<T>* current = first;
    for (int j = 0; j < i; j++) {
        current = current->next;
    }
    return current->data;
}

template <class T>
void List<T>::set_at(int i, T e) {
    if (i < 0 or i >= size()) {
        throw std::out_of_range("Invalid index");
    }
    Node<T>* current = first;
    for (int j = 0; j < i; j++) {
        current = current->next;
    }
    current->data = e;
}

template <class T>
T List<T>::delete_at(int i) {
    if (i < 0 || i >= size()) {
        throw std::out_of_range("Index out of range!");
    }
    Node<T>* current = first;
    Node<T>* previous = nullptr;
    int counter = 0;
    while (counter < i) {
        previous = current;
        current = current->next;
        counter++;
    }
    if (previous == nullptr) {
        first = current->next;
    }
    else {
        previous->next = current->next;
    }
    T deleted_value = current->data;
    delete current;
    return deleted_value;
}


// size curs7
/*
template<class T>
int List<T>::size() const {
    int contor = 0;
    Node<T>* last = first;
    while (last != nullptr)
    {
        contor++;
        last = last->next;
    }
    return contor;
}
*/

// update curs7
/*
template<class T>
T List<T>::update(int i, T e) {
    if (i < 0 || i >= size())
        throw invalid_argument("pozitia nu e valida");
    Node<T>* crt = first;
    int noE = 0;
    while (noE < i) {
        crt = crt->next;
        noE++;
    }
    T old_value = crt->data;
    crt->data = e;

    return old_value;
}
*/

// get_at curs7
/*
template<class T>
T List<T>::get_at(int i) const {
    if (i < 0 || i >= size())
        throw invalid_argument("pozitia nu e valida");
    Node<T>* crt = first;
    int noE = 0;
    while (noE < i) {
        crt = crt->next;
        noE++;
    }
    return crt->data;
}
*/

// push_back curs7
/*
template<class T>
void List<T>::push_back(T e) {
    Node<T>* newNode = new Node<T>(e, nullptr);
    if (first == nullptr) {
        first = newNode;
    }
    else {
        Node<T>* last = first;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = newNode;
    }

}
*/ 






