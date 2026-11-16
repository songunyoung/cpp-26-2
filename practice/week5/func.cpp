#include <iostream>
using namespace std;

int Sum(int x,int y=0){
    int result = x+y;
    return result;
}

int main(){
    int a =2, b = 3;

    int value;
    value= Sum(a,b);
    cout << value <<endl;

     value= Sum(a);
    cout << value <<endl;

    cout << "value= "<< value <<b<<endl;
    return 0 ;
}