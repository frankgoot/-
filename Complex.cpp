#include <iostream>
#include <ctime>
#include "Vector.h"
#include "Complex.h"

using namespace std;

int main() {
    srand(time(NULL));

    Vector<Complex> v(4);
    v[0] = Complex(1, 2);
    v[1] = Complex(3, 4);
    v[2] = Complex(5, 6);
    v[3] = Complex(1, 2);

    cout << v << endl;

    v.shuffle();
    cout << v << endl;

    int index = v.find(Complex(1, 2));
    cout << "Index of (1, 2): " << index << endl;

    v.insert(2, Complex(3, 4));
    cout << v << endl;

    v.remove(2);
    cout << v << endl;

    int n = v.deduplicate();
    cout << "Deduplicated " << n << " elements." << endl;

    v.sort();
    cout << v << endl;

    v.shuffle();
    cout << v << endl;

    v.sort(Vector<Complex>::MERGE_SORT);
    cout << v << endl;

    v.shuffle();
    cout << v << endl;

    v.sort(Vector<Complex>::BUBBLE_SORT);
    cout << v << endl;

    v.shuffle();
    cout << v << endl;

    clock_t t1 = clock();
    v.sort();
    clock_t t2 = clock();
    cout << "Default sort: " << t2 - t1 << " ticks." << endl;

    v.shuffle();
    t1 = clock();
    v.sort(Vector<Complex>::MERGE_SORT);
    t2 = clock();
    cout << "Merge sort: " << t2 - t1 << " ticks." << endl;

    v.shuffle();
    t1 = clock();
    v.sort(Vector<Complex>::BUBBLE_SORT);
    t2 = clock();
    cout << "Bubble sort: " << t2 - t1 << " ticks." << endl;

    Vector<Complex> sub_v = v.search(2, 5);
    cout << sub_v << endl;

    return 0;
}
