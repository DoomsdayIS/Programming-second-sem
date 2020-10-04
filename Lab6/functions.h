#ifndef LAB6_FUNCTIONS_H
#define LAB6_FUNCTIONS_H

template<typename containerIterator, typename object>
bool all_of(containerIterator, containerIterator, bool (&f)(object));
template<typename containerIterator, typename object>
bool one_of(containerIterator, containerIterator, bool (&f)(object));
template<typename  containerIterator,typename object>
containerIterator find_backward(containerIterator,containerIterator,object);

#include "functions.tpp"

#endif //LAB6_FUNCTIONS_H
