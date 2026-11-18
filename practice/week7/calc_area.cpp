
#include <iostream>
using namespace std;

class PrintData{
public:
    //속성
    double calcArea();
    /
    int radius;
    string color;
};

//메소드
double Circle::CalcArea(){
        return 3.14 * radius * radius;
}


int main(){
    Circle c;
    c.radius =10;
    cout << c.CalcArea() << "\n";
    return 0;
}

