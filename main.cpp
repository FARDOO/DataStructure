#include <iostream>
#include "queue.hpp"
#include "circular_list.hpp"

int main() {

    std::cout << "Testing queue of integers:\n" << std::endl;
    queue<int> int_queue;
    int_queue.enqueue(1);
    int_queue.enqueue(2);
    int_queue.enqueue(3);

    std::cout << "----- Size of queue: " << int_queue.size() << " -----" << std::endl;
    std::cout << "----- Front element: " << int_queue.front() << " -----" << std::endl;

    int first = int_queue.dequeue();
    std::cout << "----- Dequeued element: " << first << " -----" << std::endl;
    std::cout << "----- Size of queue after dequeue: " << int_queue.size() << " -----" << std::endl;
    std::cout << "----- Front element after dequeue: " << int_queue.front() << " -----" <<std::endl;

    std::cout << std::endl;

    // Testing circular list of strings
    std::cout << "Testing circular list of strings:\n" << std::endl;
    circular_list<std::string> str_list;
    str_list.insert("Charlie");
    str_list.insert("Adam");
    str_list.insert("Smith");

    std::cout << "----- Size of circular list: " << str_list.size() << " -----" << std::endl;
    std::cout << "----- Current element: " << str_list.current() << " -----" << std::endl;

    std::string removed = str_list.remove();
    std::cout << "----- Removed element: " << removed << " -----" << std::endl;
    std::cout << "----- Size of circular list after remove: " << str_list.size() << " -----" << std::endl;
    std::cout << "----- Current element after remove: " << str_list.current() << " -----" << std::endl;

    return 0;
}