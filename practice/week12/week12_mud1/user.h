#include <iostream>
#include <string>
using namespace std;
const int mapX = 5;
const int mapY = 5;

class User{
	int hp;
public:
	User(int p);
	void IncreaseHP(int inc_hp);
	void DecreaseHP(int dec_hp);
	int GetHP();
};

bool CheckUser(User user);


// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(int map[][mapX], int user_x, int user_y);