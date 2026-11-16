#include <iostream>
using namespace std;


class Rectangle{
    int width, height;
public:
   Rectangle(int w, int h);
   ~Rectangle();
   int CalcArea();
};

Rectangle::Rectangle(int w, int h){
    cout << "생성자 호출!" << endl;
    width = w;
    height = h;
}
Rectangle::~Rectangle(){
    cout <<"소멸자 호출!" << endl;
}

int Rectangle::CalcArea(){
    return width*height;
}



int main(){
    Rectangle r{3,4};

    cout <<"사각형의 넓이 :"<<r.CalcArea() << '\n';
    return 0;
}