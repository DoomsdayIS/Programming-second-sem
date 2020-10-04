
namespace my_func {
    template<class T>
    const T &min(const T &a, const T &b){
        return a < b ? a:b;
    }
}