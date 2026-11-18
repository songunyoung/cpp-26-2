#include <iostream>
#include <stream>
using namespace std;

class Person {
protected:
    string name; // 기본적으로private
    string address;
};
class Student : Person {
public:
    void SetAddress(string add) {
    address = add;
    }
    string GetAddress() {
    return address;
    }
    // void SetName(string name){ this->name = name; } // 에러
};
int main() {
    Student obj;
    // obj.SetName(“미수“) ; // 에러
    obj.SetAddress("서울시종로구1번지");
    cout << obj.GetAddress() << endl;
    return 0;
}