#include <iostream>
using namespace std;

class PassangerCar {
public:
 int seats; // 정원
void SetSeats(int n) { seats = n; }
};

class Truck {
public:
 int payload; // 적재하중
void SetPayload(int load) { payload = load; }
};



class Pickup : public PassangerCar, public Truck {
public:
 int tow_capability; // 견인능력
void SetTow(int capa) { tow_capability = capa; }
 void Print(){
     cout << "seats:" << seats << " payload: " 
 << payload << " tow: " << tow_capability << endl;
 }
};
int main()
{
 Pickup my_car;
 my_car.SetSeats(4);
 my_car.SetPayload(10000);
 my_car.SetTow(30000);
 return 0;
}