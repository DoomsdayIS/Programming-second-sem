
template<typename containerIterator, typename object>
bool all_of(containerIterator start, containerIterator end, bool (&f)(object)){
    for (auto it = start; it != end; it++){
        if (!f(*it))
            return false;
    }
    return true;
}


template<typename containerIterator, typename object>
bool one_of(containerIterator start, containerIterator end, bool (&f)(object)){
    bool flag = false;
    for (auto it = start; it != end; it++){
        if (f(*it)){
            if (flag)
                return false;
            flag = true;
        }
    }
    return flag;
}


template<typename containerIterator, typename object>
containerIterator find_backward(containerIterator start,containerIterator end,object obj){
    for (auto it = end - 1; it != start - 1; it--){
        if (*it == obj)
            return it;
    }
    return start;
}
