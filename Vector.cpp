#include <iostream>
#include <vector>
using namespace std;

class A {
public :
    A() = delete;
    A(int x) : x(x) {}
    friend ostream &operator<<(ostream &out, const A &);
private:
    int x;
};

ostream &operator<<(ostream &out, const A &a) {
    out << "Class A : " << a.x;
    return out;
}

namespace haizei {
template<typename T>
class vector {
public :
    vector(int n = 10);
    vector(const vector<T> &v);
    vector(vector<T> &&v);
    
    T &operator[](int ind);
    const T &operator[](int ind) const; 
    int size() const;
    void push_back(const T &);
    void push_back(T &&);
    
    ~vector(); 
private:
    int __capacity, __size;
    T *data;
};

template<typename T>
vector<T>::vector(int n) : __capacity(n), __size(0), data(nullptr) {
    data = (T *)malloc(sizeof(T) * __capacity);
} 
template<typename T>
vector<T>::vector(const vector<T> &v) : __capacity(__capacity), __size(v.__size) {
    data = (T *)malloc(sizeof(T) * __capacity);
    for (int i = 0; i < __size; ++i) {
        new(data + i) T(v.data[i]);
    }
    return ;
}
template<typename T>
vector<T>::vector(vector<T> &&v) : __capacity(v.capacity), __size(v.__size), data(v.data) {
    v.data = nullptr;
    v.__capacity = 0;
    v.__size = 0;
}
template<typename T>
T &vector<T>::operator[](int ind) {
    return data[ind];
}
template<typename T>
const T &vector<T>::operator[](int ind) const {
    return data[ind];
}
template<typename T>
int vector<T>::size() const { return __size; }
template<typename T>
void vector<T>::push_back(const T &d) {
    new(data + __size) T(d);
    __size += 1;
    return ;
}
template<typename T>
void vector<T>::push_back(T &&d) {
    new(data + __size) T(move(d));
    __size += 1;
    return ; 
}
template<typename T>
vector<T>::~vector() {
    if (data) free(data);
    __size = 0;
    __capacity = 0;
    return ;
}

}

ostream &operator<<(ostream &out, const vector<A> &v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    return out;
}
template<typename T>
ostream &operator<<(ostream &out, const haizei::vector<T> &v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    return out;
}

int main() {
    A a = 1;
    cout << a << endl;
    vector<A> v1;
    cout << v1.size() << endl;
    v1.push_back(123);
    v1.push_back(456);
    v1.push_back(789);
    haizei::vector<A> v2;
    cout << v2.size() << endl;
    v2.push_back(123);
    v2.push_back(456);
    v2.push_back(789);
    cout << v1 << endl;
    cout << v2 << endl;
    return 0;
}
