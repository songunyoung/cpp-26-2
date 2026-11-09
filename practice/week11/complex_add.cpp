#include <iostream>
using namespace std;

class Complex {
public:
    double real, imag;
    Complex(double r = 0.0, double i = 0.0) {
    real = r;
    imag = i;
    cout << "생성자호출";
    Print();
    }
    ~Complex() {
    cout << "소멸자호출";
    Print();
    }
    void Print() {
    cout << real << "+" << imag << "i" << endl;
    }
};


/*
Complex Add(Complex c1, Complex c2){
    int a=c1.real + c2.real;
    int b=c1.imag + c2.real;
    Coplex c3{a,b};
    return c3;
}*/

/*
void Add(Complex & c1, Complex & c2){
    c1.real += c2.real;
    c1.imag += c2.real;
}*/

void Add(Complex * c1, Complex * c2){
    c1->real += c2->real;
    c1->imag += c2->real;
}


int main()
{
Complex c1{ 1,2 }, c2{ 3,4 };
Complex t;
Add(&c1,&c2);
t.Print();
return 0;
}