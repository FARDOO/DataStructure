<h1>
  Data Structure
</h1>

This repository contains an implementation of circular doubly linked lists and queues using Object-Oriented Programming (OOP) and nodes principles in C++. The purpose of this project is to demonstrate how these data structures can be designed and used in an OOP environment.
<br>  <br/>
<div align="center">
    <img src="https://www.masaischool.com/blog/content/images/wordpress/2022/04/First-In-First-Out-Queue-768x512.png" title="Graphic Demonstration of Node Connections in a Queue"
       style="width: 35vw; height: auto;" />
</div>
<br>  <br/>
<div align="center">
    <img src="https://www.monografias.com/trabajos107/guia-teoria-otras-estructuras-dinamicas-y-orden-algoritmos/image005.jpg" title="Graphic Demonstration of Node Connections in a Doubly Linked List and a Circular Doubly Linked List"
       style="width: 35vw; height: auto;" />
</div>
<br>  <br/>

 <h2> Contents: </h2>

- Description
- Requirements
- Installation
- Usage
- Code Structure
- License

<h2> Description: </h2>

This project includes the implementation of two fundamental data structures:

1. **Circular Doubly Linked List**: A linked list where each node has a reference to the next node and the previous node, forming a circular structure.
2. **Queue**: A FIFO (First In, First Out) data structure.

Each data structure is implemented as a class in C++, utilizing OOP principles to encapsulate data and behavior.

<h2> Requeriments: </h2>

- C++11 or higher
- A C++ compiler (e.g., g++, clang++)

<h2> Installation: </h2> 

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
    g++ -o test -I./include main.cpp
    ./test
    ```

 <h2> Usage: </h2>

Here is an example of how you can use the classes implemented in this project:

```cpp
#include <iostream>
#include "circular_list.hpp"
#include "queue.hpp"

int main() {
    // Create a circular doubly linked list
    circular_list<int> cdll;
    cdll.insert(10);
    cdll.insert(20);
    cdll.insert(30);
    std::cout << "Size of circular list: " << cdll.size() << std::endl;
    std::cout << "Current element: " << cdll.current() << std::endl;

    // Create a queue
    queue<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    std::cout << "Size of queue: " << queue.size() << std::endl;
    std::cout << "Front element: " << queue.front() << std::endl;

    // Additional operations
    int first = queue.dequeue();
    std::cout << "Dequeued element: " << first << std::endl;

    return 0;
}
