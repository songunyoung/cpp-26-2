
#include <iostream>
#include <string>
using namespace std;

class Car{
public:
    //속성
    int speed;
    int gear;
    string color;
    
    // 메소드
    void Speedup(){
        speed += 10;
    }  
    void SpeedDown(){
        speed -=10;
    }
};


int main(){
    Car myCar;

    myCar.speed =100;
    myCar.gear = 3;
    myCar.color = "red";

    cout <<"1st speed: " << myCar.speed << endl;
    myCar.SpeedUp();
    cout <<"2nd speed: " << myCar.speed << endl;
    myCar.SpeedDown(); 
    cout <<"3rd speed: " << myCar.speed << endl;
    return 0;
}

