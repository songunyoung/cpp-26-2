#include <iostream>
using namespace std;
class Box {
double length, width, height;
public:
Box(double l, double w, double h) : length{l}, width{w}, height{h} { }
friend void printBox(Box box);
};


void printBox(Box box) {
cout << "Box( " << box.length << ", " << box.width << ", " << box.height<<") " << endl;
}

class A {
public:
friend class B; // B는 A의 프렌드가 된다.
A(string s = "") : secret{s} { }
private:
string secret; // B는 여기에 접근할 수 있다.
};
class B {
public:
B() { }
void print(A obj) {
cout << obj.secret << endl;
}
};



int main() {
Box box(10, 20, 30);
printBox(box);
return 0;
}