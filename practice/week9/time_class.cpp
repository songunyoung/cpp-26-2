#include <iostream>
using namespace std;


class Time{
    public:
    int hour;
    int minute;

    Time(int h=0, int m=0){
        hour= h;
        minute = m;
    }

    void Print(){
        cout << hour << ":" << minute << endl;
    }
};



int main(){

    Time a;
    Time b(10, 25);
    Time c{10,25};
    Time d={10,25};

    a.Print();
    b.Print();
    c.Print();
    d.Print();
    return 0;
}