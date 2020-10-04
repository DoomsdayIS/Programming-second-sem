#include <iostream>
#include "functions.h"
#include <vector>
#include <set>

template<class T>
bool Foo(T a){
    return a > 0;
}

class MyClass{
private:
    int znam = 1;
    int chis = 0;
public:
    MyClass() = default;
    bool operator>(int a){
        return chis/znam > a;
    }
    void make_double(int a,int b){
        chis = a;
        znam = b;
    }
    ~MyClass() = default;
};

int main() {
    std::vector<int> vec = {1,2,2,3};
    std::set<double> sett = {-1.2,3.1,-4.1};
    std::cout << all_of(vec.begin(),vec.end(),Foo<int>) << " : "<< all_of(sett.begin(),sett.end(),Foo<double>)  << std::endl;
    std::cout << one_of(vec.begin(),vec.end(),Foo<int>) << " : " << one_of(sett.begin(),sett.end(),Foo<double>) << std::endl;
    std::cout << *find_backward(vec.begin(),vec.end(),2) << std::endl;
    //
    std::vector<MyClass> my_vec;
    MyClass f;
    f.make_double(12,5);
    my_vec.push_back(f);
    MyClass s;
    s.make_double(14,3);
    my_vec.push_back(s);
    std::cout << all_of(my_vec.begin(),my_vec.end(),Foo<MyClass>);
    return 0;
}
