#ifndef LAB3_QUEUE_H
#define LAB3_QUEUE_H


#include <iosfwd>

class Queue {
private:
    int len;
    struct node{
        int value;
        node* next;
    };
    node* back;
    node* front;
public:
    Queue();
    ~Queue();
    std::ostream& operator<<(std::ostream&);
    std::istream& operator>>(std::istream&);
    void print_all();
};


#endif //LAB3_QUEUE_H
