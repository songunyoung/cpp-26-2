#include <iostream>
using namespace std;
const int SIZE = 10;
class MyArray {
private:
    int a[SIZE];
public:
    MyArray() {
    for (int i = 0; i < SIZE; i++)
    a[i] = 0;
    }
    int &operator[](int i) {
    if (i >= SIZE) {
    cout << "잘못된 인덱스:" ;
    return a[0];
    }
    return a[i];
    }
};


int main() {
MyArray A;
A[3] = 9;
cout << "A[3]= " << A[3] << endl;
cout << "A[16]= " << A[16] << endl;
return 0;
}