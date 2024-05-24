#ifndef DataStructure_CIRCULAR_LIST_HPP
#define DataStructure_CIRCULAR_LIST_HPP

#include <exception>
#include "node.hpp"

class circular_list_exception : public std::exception {
};

template<typename T>
class circular_list {
private:
    node<T>* first_node;
    // The cursor is the current element.
    node<T>* cursor;
    size_t data_count;
public:
    // Constructor.
    circular_list();

    // Pre: -
    // Post: Adds data at the position of the cursor (the new data is "before" the cursor). For example:
    //
    // 1  2  4  6  8
    //    ^
    // insert(5);
    // 1  5  2  4  6  8
    //       ^
    //
    // 1  2  4  6  8
    // ^
    // insert(9);
    // 1  2  4  6  8  9
    // ^
    //
    // The cursor point to the same node.
    // If the list is empty, the cursor points to the first node.
    void insert(T data);

    // Pre: The list cannot be empty.
    // Post: Returns the current data (cursor).
    T current();

    // Pre: The list cannot be empty.
    // Post: Removes and returns the current data (cursor). For example:
    //
    // 1  2  4  6  8
    //    ^
    // remove();
    // 1  4  6  8
    //    ^
    //
    // 1  2  4  6  8
    // ^
    // remove();
    // 2  4  6  8
    // ^
    //
    // The cursor point to the next node after the deleted one.
    // If the first node is deleted, it would be reassigned with its next node.
    // If the list is empty, it should return to its initial state.
    T remove();

    // Pre: -
    // Post: Moves the cursor to the next of the current cursor. If there is no data, it does nothing.
    void advance();

    // Pre: -
    // Post: Moves the cursor to the previous of the current cursor. If there is no data, it does nothing.
    void retreat();

    // Pre: -
    // Post: Returns the number of data elements in the list.
    size_t size();

    // Pre: -
    // Post: Returns true if the list is empty.
    bool empty();

    // Copy constructor is disabled.
    circular_list(const circular_list& l) = delete;

    // Assignment operator is disabled.
    void operator=(const circular_list& l) = delete;

    // Destructor.
    ~circular_list();
};

template<typename T>
circular_list<T>::circular_list() {
    cursor = nullptr;
    first_node = nullptr;
    data_count = 0;
}

template<typename T>
void circular_list<T>::insert(T data) {
    if ( data_count == 0 ) {
        node<T>* new_node = new node<T>(data);
        first_node = new_node;
        first_node->next = first_node->previous = first_node;
        cursor = first_node;
    }
    else {
        node<T>* new_node = new node<T>( data, cursor->previous, cursor );
        cursor->previous->next = new_node;
        cursor->previous = new_node;
    }
    data_count++;
}

template<typename T>
T circular_list<T>::current() {
    if ( empty() ) {
        throw circular_list_exception();
    }
    return cursor->data;
}

template<typename T>
T circular_list<T>::remove() {
    if ( empty() ) {
        throw circular_list_exception();
    }

    T removed_data = cursor->data;

    if ( data_count == 1 ) {
        delete cursor;
        cursor = nullptr;
        first_node = nullptr;
    }
    else {
        cursor->previous->next = cursor->next;
        cursor->next->previous = cursor->previous;
        node<T>* node_to_delete = cursor;
        cursor = cursor->next;
        delete node_to_delete;
    }
    data_count--;
    return removed_data;
}

template<typename T>
void circular_list<T>::advance() {
    if ( cursor ) {
        cursor = cursor->next;
    }
}

template<typename T>
void circular_list<T>::retreat() {
    if ( cursor ) {
        cursor = cursor->previous;
    }
}

template<typename T>
size_t circular_list<T>::size() {
    return data_count;
}

template<typename T>
bool circular_list<T>::empty() {
    return data_count == 0;
}

template<typename T>
circular_list<T>::~circular_list() {
    while ( !empty() ) {
        remove();
    }
}

#endif
