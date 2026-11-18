#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int mapX = 5;
const int mapY = 5;


class User{
protected:
	int hp;
	int user_x = 0; // 가로 번호
	int user_y = 0; // 세로 번호
	bool item = false;
public:
	User(int p);
	void IncreaseHP(int inc_hp);
	void DecreaseHP(int dec_hp);
	int GetHP();
	void doAttack();
	void myTurn();
};

class Magician:public User{
	Magician(int p);
	void doAttack();
};
class Warrior:public User{
	Warrior(int p);
	void doAttack();
};


bool CheckUser(User user);


// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(vector<vector<int>> map, int user_x, int user_y);
bool checkGoal(vector<vector<int>> map, int user_x, int user_y);

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(vector<vector<int>> user_x, int mapX, int user_y, int mapY);

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(vector<vector<int>> map, int user_x, int user_y);