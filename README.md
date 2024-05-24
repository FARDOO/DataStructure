<h1>
  Data Structure
</h1>

This repository contains an implementation of circular doubly linked lists and queues using Object-Oriented Programming (OOP) principles in C++. The purpose of this project is to demonstrate how these data structures can be designed and used in an OOP environment.

<div align="center">
    <img src="https://www.monografias.com/trabajos107/guia-teoria-otras-estructuras-dinamicas-y-orden-algoritmos/image005.jpg" width="700" height="240"/>
  </div>

 <h2> Contents </h2>

- Description
- Requirements
- Installation
- Usage
- Code Structure
- Contributions
- License

<h2> Description </h2>

This project includes the implementation of two fundamental data structures:

1. **Circular Doubly Linked List**: A linked list where each node has a reference to the next node and the previous node, forming a circular structure.
2. **Queue**: A FIFO (First In, First Out) data structure.

Each data structure is implemented as a class in Python, utilizing OOP principles to encapsulate data and behavior.

<h2> Requeriments </h2>

- C++11 or higher
- A C++ compiler (e.g., g++, clang++)

<h2>Installation</h2> 

1. Clone this repository to your local machine:
    ```bash
    git clone https://github.com/your-username/your-repo.git
    ```
2. Navigate to the project directory:
    ```bash
    cd your-repo
    ```
3. Compile the source files:
    ```bash
    g++ -o main main.cpp circular_doubly_linked_list.cpp queue.cpp
    ```

 <h2> Usage </h2>

Here is an example of how you can use the classes implemented in this project:

```cpp
#include <iostream>
#include "circular_doubly_linked_list.h"
#include "queue.h"

int main() {
    // Create a circular doubly linked list
    CircularDoublyLinkedList cdll;
    cdll.insertAtStart(10);
    cdll.insertAtEnd(20);
    cdll.insertAtEnd(30);
    std::cout << "Circular Doubly Linked List:" << std::endl;
    cdll.displayList();

    // Create a queue
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    std::cout << "Queue:" << std::endl;
    queue.displayQueue();

    // Additional operations
    std::cout << "Dequeued element: " << queue.dequeue() << std::endl;
    queue.displayQueue();

    return 0;
}
