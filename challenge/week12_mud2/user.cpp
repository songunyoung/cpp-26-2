#include "user.h"


User::User(int p): hp(p)itemCnt(0){}
void User::IncreaseHP(int inc_hp){
	hp+=inc_hp;
}
void User::DecreaseHP(int dec_hp){
	hp-=dec_hp;
}

int User::GetHP(){
	return this->hp;
}

int User::GetHP(){
	return this->hp;
}

int User::GetHP(int inc_item){
	this->itmeCnt+=inc_item;
}


string User::operator<<(){
	return "현재 HP는 " +(string)this->hp "이고 먹은 아이템은 총 " + (string)this->itemCnt+"개입니다."
}


bool CheckUser(User user){
	if (user.GetHP()<=0)
		return false;
	else
		return true;
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(int map[][mapX], int user_x, int user_y) {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) { return false;}
	return true;
}//이게 왜있어야하는지 모르겠다?





MyVector::MyVector(double x = 0.0, double y = 0.0) : x{x}, y{y} { }
string toString() {
    return "("+to_string(x) +", "+to_string(y)+")" ;
}

MyVector MyVector::operator+(const MyVector& v2)
{
MyVector v;
v.x = this->x + v2.x;
v.y = this->y + v2.y;
return v;
}

MyVector MyVector::operator-(const MyVector& v2)
{
MyVector v;
v.x = this->x - v2.x;
v.y = this->y - v2.y;
return v;
}