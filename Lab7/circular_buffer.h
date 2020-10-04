#ifndef LAB7_CIRCULAR_BUFFER_H
#define LAB7_CIRCULAR_BUFFER_H

#include <exception>



class out_of_range_exp : public std::exception{
private:
    const char* m_err;
public:
    explicit out_of_range_exp(const char* error)
        :m_err(error)
    {}

    const char* what() const noexcept override {
        return m_err;
    }

};


template<class T>
class circular_buffer{
private:
    size_t back;
    size_t front;
    size_t size;
    T* data;
    size_t capacity;
    class MyIterator: public std::iterator<std::random_access_iterator_tag,T>{
    public:
        MyIterator() = delete;
        MyIterator(const MyIterator& it)
                :ptr(it.ptr)
                ,cap(it.cap)
                ,data_get(it.data_get)
        {}
        explicit MyIterator(T *p,circular_buffer* buff)
                :ptr(p)
                ,cap(buff->capacity)
                ,data_get(buff->data)
        {}
        ~MyIterator()= default;
        MyIterator& operator= (MyIterator const& other){
            this->ptr = other.ptr;
            this->cap = other.cap;
            this->data_get = other.data_get;
            return *this;
        }
        MyIterator& operator= (T *p){
            this->ptr = p;
            return *this;
        }
        MyIterator& operator= (const T& val){
            *(this->ptr) = val;
            return *this;
        }
        bool operator == (const MyIterator& other){
            return this->ptr == other.ptr;
        }
        bool operator != (const MyIterator& other){
            return this->ptr != other.ptr;
        }
        T& operator*(){
            return *(this->ptr);
        }
        T* operator->(){
            return (this->ptr);
        }
        MyIterator& operator + (const int& val){
            int value = val;
            value %= cap;
            auto& tmp(*this);
            if (data_get + cap - tmp.ptr > value){
                tmp.ptr += value;
            }else{
                tmp.ptr = tmp.ptr + value - cap;
            }
            return tmp;
        }
        MyIterator& operator - (const int& val){
            int value = val;
            value %= cap;
            auto& tmp(*this);
            if (tmp.ptr - data_get >= value){
                tmp.ptr -= value;
            } else{
                tmp.ptr = tmp.ptr - value + cap;
            }
            return tmp;
        }
        long operator - (MyIterator& other){
            if (this->ptr - other.ptr > 0)
                return (this->ptr - other.ptr);
            else{
                return ((this->ptr - other.ptr) + cap);
            }
        }
        MyIterator& operator += (const int& val){
            int value = val;
            value %= cap;
            if (data_get + cap - this->ptr > value){
                this->ptr += value;
            }else{
                this->ptr = this->ptr + value - cap;
            }
            return *this;
        }
        MyIterator& operator -= (const int& val){
            int value = val;
            value %= cap;
            if (this->ptr - data_get >= value){
                this->ptr -= value;
            } else{
                this->ptr = this->ptr - value + cap;
            }
            return *this;
        }
        MyIterator& operator++(){
            if (data_get + cap - this->ptr <= 1){
                this->ptr = data_get;
            } else{
                this->ptr++;
            }
            return *this;
        }
        MyIterator& operator--(){
            if (this->ptr - data_get <= 0){
                this->ptr = data_get + cap - 1;
            }else{
                this->ptr--;
            }
            return *this;
        }
        MyIterator&  operator++(int){
            auto& tmp(*this);
            if (data_get + cap - tmp.ptr <= 1){
                tmp.ptr = data_get;
            } else{
                tmp.ptr++;
            }
            return tmp;
        }
        MyIterator& operator--(int){
            auto& tmp(*this);
            if (tmp.ptr - data_get <= 0){
                tmp.ptr = data_get + cap - 1;
            }else{
                tmp.ptr--;
            }
            return tmp;
        }
        T& operator[](const int& val){
            int value = val;
            value %= cap;
            if (data_get + cap - this->ptr > value){
                return *(this->ptr + value);
            }else{
                return *(this->ptr + value - cap);
            }
        }
        bool operator > (MyIterator& it){
            return this->ptr > it.ptr;
        }
        bool operator >= (MyIterator& it){
            return this->ptr >= it.ptr;
        }
        bool operator < (MyIterator& it){
            return this->ptr < it.ptr;
        }
        bool operator <= (MyIterator& it){
            return this->ptr < it.ptr;
        }
    private:
        T *ptr;
        size_t cap;
        T *data_get;
    };
public:
    circular_buffer()
            :capacity(1)
            ,size(0)
            ,back(0)
            ,front(0)
            ,data(new T[1])
    {}
    circular_buffer(size_t cap)
            :capacity(cap)
            ,size(0)
            ,back(0)
            ,front(0)
            ,data(new T[cap])
    {}

    ~circular_buffer() {
        delete [] data;
    };
    void push_back(const T& val){
        if (size == capacity){
            front = (front + 1) % capacity;
            this->end(this) = val;
            back = (back + 1) % capacity;
        }else{
            this->end(this) = val;
            back = (back + 1) % capacity;
            size++;
        }
    }
    T& pop_back(){
        if (size <= 0){
            throw out_of_range_exp("Incorrect operation. Buffer is clear!");
        }
        size --;
        back = (back + capacity - 1) % capacity;
        return *this->end(this);
    }
    void push_front(const T& val){
        if (size == 0){
            this->begin(this) = val;
            back = (back + 1) % capacity;
            size++;
        } else if (size == capacity){
            front = (front + capacity - 1) % capacity;
            this->begin(this) = val;
            back = (back + capacity - 1) % capacity;
        } else{
            front = (front + capacity - 1) % capacity;
            this->begin(this) = val;
            size++;
        }
    }
    T& pop_front(){
        if (size <= 0){
            throw out_of_range_exp("Incorrect operation. Buffer is clear!");
        }
        size --;
        front = (front + 1) % capacity;
        return *(this->begin(this) - 1);
    }
    T& last_elemet(){
        if (size <= 0){
            throw out_of_range_exp("Incorrect operation. Buffer is clear!");
        }
        return *(data + ((back + capacity - 1) % capacity));
    }
    T& first_element(){
        if (size <= 0){
            throw out_of_range_exp("Incorrect operation. Buffer is clear!");
        }
        return *(data + front);
    }
    T& operator[](const size_t pos){
        return this->begin(this)[pos];
    }
    void change_capacity(size_t new_cap){
        T* new_data(new T[new_cap]);
        back = 0;
        for (size_t it = 0; it < size; it ++){
            new_data[back] = data[it];
            back = (back + 1) % new_cap;
        }
        data = new_data;
        capacity = new_cap;
        if (size <= new_cap){
            front = 0;
        }else{
           front = back;
        }
        size = std::min(size,new_cap);
    }
    void insert(size_t pos,const T& val){
        if (size - pos <= 0){
            throw out_of_range_exp("Incorrect position!");
        }
        T buffer1;
        T buffer2 = val;
        for (int i = pos;i < size + 1;i++){
            buffer1 = this->begin(this)[i];
            this->begin(this)[i] = buffer2;
            buffer2 = buffer1;

        }
        size++;
        size = std::min(capacity,size);
    }
    void delete_by_pos(size_t pos){
        if (size <= 0){
            throw out_of_range_exp("Incorrect operation. Buffer is clear!");
        }
        size--;
        for (int i = pos;i < size;i++){
            this->begin(this)[i] = this->begin(this)[i+1];
        }
    }
    void print_buff(){
        for (size_t it = 0;it < size;it++){
            std::cout << data[it] << " ";
        }
        std::cout << std::endl;
    }
    circular_buffer::MyIterator begin(circular_buffer* buff) {
        return  MyIterator(data + front,buff);
    }
    circular_buffer::MyIterator end(circular_buffer* buff) {
        return MyIterator(data + back,buff);
    }
};


#endif //LAB7_CIRCULAR_BUFFER_H
