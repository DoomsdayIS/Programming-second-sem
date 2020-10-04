#include <iostream>
#include <string>

#include "circular_buffer.h"

int main(){
    //
    circular_buffer<int> first(4);
    //
    try{
        first.pop_back();
    }catch (std::exception & exp){
        std::cout << exp.what() << std::endl;
    }
    // Добавляем в конец и удаляем из начала
    first.push_back(12);
    first.push_back(13);
    first.pop_front();
    // Обращение по индексу
    std::cout << first[0] << std::endl;
    first.push_front(9);
    // Вывод первого и последнего
    std::cout << first.first_element() << std::endl;
    std::cout << first.last_elemet() << std::endl;
    first.insert(1,15);
    first.delete_by_pos(1);
    std::cout << first.first_element() << std::endl;
    std::cout << first.last_elemet() << std::endl;
    //
    circular_buffer<double> l(6);
    l.push_back(12.3);
    l.push_back(12.4);
    l.push_back(12.1);
    l.push_back(12.7);
    l.push_back(12.5);
    l.push_back(12.4);
    //Изменяем размер хранилища
    l.change_capacity(3);
    l.print_buff();
    // Используем стандартный сорт
    std::sort(l.begin(&l),l.end(&l));
    l.print_buff();
    return 0;
}