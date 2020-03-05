#include <iostream>
#include "queue.h"

Queue::Queue() {
    len = 0;
    front = nullptr;
    back = nullptr;
}

std::istream& Queue::operator>>(std::istream& x) {
    if (len >= 100){
        std::cout << "Error: size >= 100" << std::endl;
    }else{
        len++;
        node* buffer = new node;
        x >> buffer->value;
        buffer->next = nullptr;
        if (front != nullptr){
            front->next = buffer;
        }
        if (back == nullptr){
            back = buffer;
        }
        front = buffer;
    }
    return x;
}

std::ostream &Queue::operator<<(std::ostream &out) {
    if (len == 0){
        std::cout << "Error: size = 0" << std::endl;
    }else{
        len--;
        out << back->value << std::endl;
        node* buffer = back;
        back = back->next;
        delete buffer;

    }
    return out;
}

Queue::~Queue() {
    if (len != 0){
        node* buffer = back;
        while (buffer != nullptr){
            node* buffer2 = buffer;
            buffer = buffer->next;
            delete buffer2;
        }
    }
}

void Queue::print_all() {
    if (len != 0){
        node* buffer = back;
        while (buffer != nullptr){
            std::cout << buffer->value << " ";
            buffer = buffer->next;
        }
        std::cout << std::endl;
    }else{
        std::cout << "Queue is empty" << std::endl;
    }
}