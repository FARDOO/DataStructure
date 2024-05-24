#ifndef DataStructure_QUEUE_HPP
#define DataStructure_QUEUE_HPP

#include <exception>
#include "node.hpp"

class queue_exception : public std::exception {
};

template<typename T>
class queue {
private:
    node<T>* first_node;
    node<T>* last_node;
    size_t data_count;
public:
    // Constructor.
    queue();

    // Pre: -
    // Post: Adds the data to the end of the queue.
    void enqueue(T data);

    // Pre: The queue cannot be empty.
    // Post: Returns the first data of the queue.
    T front();

    // Pre: The queue cannot be empty.
    // Post: Removes and returns the first data of the queue.
    T dequeue();

    // Pre: -
    // Post: Returns the number of data elements in the queue.
    size_t size();

    // Pre: -
    // Post: Returns true if the queue is empty.
    bool empty();

    // Copy constructor is disabled.
    queue(const queue& q) = delete;

    // Assignment operator is disabled.
    void operator=(const queue& q) = delete;

    // Destructor.
    ~queue();
};

template<typename T>
queue<T>::queue() {
    first_node = nullptr;
    last_node = nullptr;
    data_count = 0;
}

template<typename T>
void queue<T>::enqueue(T data) {
    node<T>* new_node = new node<T>(data);

    if (empty()) {
        first_node = new_node;
    } else {
        last_node->next = new_node;
    }
    last_node = new_node;
    data_count++;
}

template<typename T>
T queue<T>::front() {

    if (empty()) {
        throw queue_exception();
    }
    return first_node->data;
}

template<typename T>
T queue<T>::dequeue() {
    if (empty()) {
        throw queue_exception();
    }

    T data = first_node->data;
    node<T>* node_to_delete = first_node;
    first_node = first_node->next;
    delete node_to_delete;
    data_count--;
    return data;
}

template<typename T>
size_t queue<T>::size() {
    return data_count;
}

template<typename T>
bool queue<T>::empty() {
    return data_count == 0;
}

template<typename T>
queue<T>::~queue() {
    while (!empty()) {
        dequeue();
    }
}

#endif
