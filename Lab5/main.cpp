#include <iostream>
#include <vector>
#include "func.h"
#include "queue.h"
#include "exceptions.h"


int main() {
    int a = 10;
    int b = 8;
    std::cout << my_func::min(a,b) << std::endl;
    std::string s1 = "rervfdgf";
    std::string s2 = "efgfewr";
    std::cout << my_func::min(10.2,6.5) << std::endl;
    std::cout << my_func::min<std::string>("erer","rt4trt") << std::endl;
    std::cout << my_func::min<std::string>(s1,s2) << std::endl;
    std::cout << std::endl;
    try {
        Queue<int,2> que{};
        que.push(10);
        std::cout << que.pop() << std::endl;
        std::cout << que.pop() << std::endl;
    }catch (const std::exception& e){
        std::cout << e.what() << std::endl;
    }


    return 0;
}