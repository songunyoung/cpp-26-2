#include <iostream>
#include <string>
using namespace std;
class Animal {
public:
void Speak()
{
cout << "동물이소리를내고있음" << endl;
}
};
class Dog : public Animal {
public:
void Speak() // 이 함수를주석처리하면?
{
cout << "멍멍!" << endl;
}


int main()
{
Dog obj;
obj.Speak();
return 0;
}
};
