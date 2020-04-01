#include "interface.h"
#include <iostream>
#include <vector>

bool comp(IFigure* x,IFigure* y){
    return x->getMass() < y->getMass();
}

int main() {
//    Vector2D vect = {2,2};
//    Eq_triangle first{3.54, 6.23, vect};
//    first.draw();
//    std::cout << first.square() << "\n" << first.perimeter() << "\n" << first.getMass() << "\n";
//    std::cout << first.getClassName() << "\n" << first.getSize() << "\n";
//    Eq_triangle sec{};
//    sec.initFromDialog();
//    if (first < sec){
//        std::cout << "SEC_MASS" << "\n";
//    } else{
//        std::cout << "First_MASS" << "\n";
//    }
    std::vector<IFigure*> vector;
    std::string s;
    std::cout << "Write 'add Parallelogram' or 'add Eq_triangle' to add that figure\n";
    std::cout << "Write 'showAll' to draw all figures\n";
    std::cout << "Write 'sortByMass' to sort objects by mass\n";
    std::cout << "Write 'sumSquare' or 'sumPerimeter' to get summary square or perimeter respectively\n";
    std::cout << "Write 'sumSize' to get summary size of all objects\n";
    std::cout << "Write 'massCenter' to get mass center vector(x, y)\n";
    std::cout << "Write 'stop' to finish this program\n";
    while (std::cin >> s){
        if (s == "add") {
            std::cin >> s;
            transform(s.begin(), s.end(),s.begin(), (int (*)(int))std::tolower);
            if (s == "parallelogram") {
                vector.push_back(new Parallelogram());
            } else if (s == "eq_triangle") {
                vector.push_back(new Eq_triangle());
            } else {
                std::cout << "Wrong figure name\nYou entered '" << s << "\n";
                continue;
            }
            vector.back()->initFromDialog();
        } else if (s == "showAll") {
            for (const auto &x : vector) {
                x->draw();
            }
        } else if (s == "sumSquare") {
            double ans = 0;
            for (const auto& x : vector) {
                ans += x->square();
            }
            std::cout << "Summary square = " << ans << "\n";
        } else if (s == "sumPerimeter") {
            double ans = 0;
            for (const auto& x : vector) {
                ans += x->perimeter();
            }
            std::cout << "Summary perimeter = " << ans << "\n";
        } else if (s == "sumSize") {
            double ans = 0;
            for (const auto& x : vector) {
                ans += x->getSize();
            }
            std::cout << "Summary size = " << ans << "\n";
        } else if (s == "sortByMass") {
            sort(vector.begin(), vector.end(), comp);
            std::cout << "Sorted.\n";
        } else if (s == "massCenter") {
            Vector2D center;
            double massSum = 0;
            for (const auto &x : vector) {
                center.x += x->getPosition().x * x->getMass();
                center.y += x->getPosition().y * x->getMass();
                massSum += x->getMass();
            }
            center.x /= massSum;
            center.y /= massSum;
            std::cout << "Mass center = (" << center.x << "; " << center.y << ")\n";
        } else if (s == "stop"){
            std::cout << "Have a good day. Bye!\n";
            break;
        } else {
            std::cout << "wrong command!\nYou entered '" << s << "\n";
            continue;
        }
    }
    return 0;
}
