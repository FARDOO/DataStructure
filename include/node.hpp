#ifndef DataStructure_NODE_HPP
#define DataStructure_NODE_HPP

template<typename T>
class queue;

template<typename T>
class circular_list;

template<typename T>
class node {
private:
    T data;
    node<T>* previous;
    node<T>* next;
public:
    // Constructors.
    node(T data);

    node(T data, node<T>* previous, node<T>* next);

    // Allowing direct access to node attributes.
    friend class queue<T>;

    friend class circular_list<T>;
};

template<typename T>
node<T>::node(T data) {
    this->data = data;
    previous = nullptr;
    next = nullptr;
}

template<typename T>
node<T>::node(T data, node<T>* previous, node<T>* next) {
    this->data = data;
    this->previous = previous;
    this->next = next;
}

#endif