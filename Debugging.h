//
// Created by antilopa on 13.05.24.
//

#ifndef DEBUGGING_H
#define DEBUGGING_H

#include <iostream>
#include "MutableStack.h"
#include <string>

template<class T>
void testQueueWithInput(MutableStack<T>* queue) {
    char choice;
    T item;

    do {
        std::cout << "Choose an operation:\n";
        std::cout << "1. Push\n";
        std::cout << "2. Pop\n";
        std::cout << "3. Get Length\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                std::cout << "Enter item to push: ";
                std::cin >> item;
                queue->Push(item);
                break;
            case '2':
                if (queue->GetLength() > 0) {
                    std::cout << "Popped: " << queue->Pull() << std::endl;
                } else {
                    std::cout << "Queue is empty." << std::endl;
                }
                break;
            case '3':
                std::cout << "Queue Length: " << queue->GetLength() << std::endl;
                break;
            case '4':
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter again." << std::endl;
        }
    } while (choice != '4');
}

int debug() {
    // Создаем очередь целых чисел
    MutableStack<int>* intQueue = new MutableStack<int>();
    std::cout << "Testing integer queue:\n" << std::endl;
    testQueueWithInput(intQueue);

    // Создаем очередь строк
    MutableStack<std::string>* stringQueue = new MutableStack<std::string>();
    std::cout << "Testing string queue:\n" << std::endl;
    testQueueWithInput(stringQueue);

    return 0;
}

#endif //DEBUGGING_H
