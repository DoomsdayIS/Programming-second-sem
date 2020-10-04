

#ifndef LAB5_QUEUE_H
#define LAB5_QUEUE_H

#include <cstddef>
#include "exceptions.h"

template<class T,std::size_t MaxSize>
class Queue{
private:
    std::size_t size;
    std::vector<T> elements;
public:
    Queue()
        : size(0)
        , elements(0)
    {}
    void push(T var){
        if (size == MaxSize){
            throw QueueOverflowException();
        }else{
            size++;
            elements.push_back(var);
        }
    }
    T pop(){
        if (size == 0){
            throw EmptyQueueException();
        } else{
            size--;
            T buffer = *elements.begin();
            elements.erase(elements.begin());
            return buffer;
        }
    }
    size_t getSize(){
        return size;
    }
    void print_all()
    {
        for (auto it = elements.begin(); it != elements.end(); it++) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }


};


#endif //LAB5_QUEUE_H
