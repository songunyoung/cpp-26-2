#include <iostream>
#include <string>
using namespace std;

class circle.cpp{
public:
    //속성
    int radius;
    string color;
    
    // 메소드
    double CalcArea(){
        return 3.14 * radius * radius;
    }
};


int main(){
    Circle obj;

    obj.radius =100;
    obj.color = "blue";

    cout << "원의 면적=" << obj.CalcArea() << "\n";
    return 0;
}

