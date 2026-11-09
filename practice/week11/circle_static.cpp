#include <iostream>
using namespace std;


#include <iostream>
#include <string>
using namespace std;
class Circle {
    int x, y;
    int radius;
public:
    static int count; // 정적변수
    Circle(int x = 0, int y= 0, int radius=0) {
        this->x = x; this->y= y;
        this->radius = radius;
        count++;
    }
};
int Circle::count = 0;

int main()
{
    Circle c1;
    cout << "지금까지생성된원의개수= " << Circle::count << endl;
    cout << "지금까지생성된원의개수= " << c1.count << endl;
    Circle c2(100, 100, 30);
    cout << "지금까지생성된원의개수= " << Circle::count << endl;
    cout << "지금까지생성된원의개수= " << c2.count << endl;
    return 0;
}