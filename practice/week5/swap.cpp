#include <iostream>
using namespace std;

void swap(int& x,int& y){
    int tmp = x;
    x =y;
    y = tmp;
}

int main(){
    int a =100, b = 200;

    cout << "a=" <<a << " b=" <<b<<endl;

    int tmp = a;
    a =b;
    b = tmp;

    cout << "a=" <<a << " b=" <<b<<endl;
    return 0 ;
}