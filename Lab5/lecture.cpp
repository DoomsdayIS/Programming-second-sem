//template<class T>
//void printMe(const T& value){
//    std::cout << value;
//}
//
//template<class InputIt, class UnaryFunc>
//void for_each(InputIt first, InputIt last,UnaryFunc func){
//    for (; first < last; ++first) {
//        func(*first);
//    }
//}
//
//template<class T1, class T2>
//struct Pair{
//    Pair() = default;
//    Pair(const T1& ft,const T2& sec)
//        : first(ft)
//        , second(sec)
//    {}
//    T1 first;
//    T2 second;
//};
//
//template<class T1, class T2>
//std::ostream& operator<< (std::ostream& stream,const Pair<T1,T2>& pair){
//    std::cout << "Pair " << pair.first << " " << pair.second << std::endl;
//    return stream;
//}
//
//template <unsigned N>
//struct factorial{
//    enum  {value = N*factorial<N-1>::value};
//};
//
//template<>
//struct factorial<0>{
//    enum {value = 1};
//};

