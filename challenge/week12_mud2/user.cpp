#include "user.h"


	User::User(int p): hp(p){}
	void User::IncreaseHP(int inc_hp){
		hp+=inc_hp;
	}
	void User::DecreaseHP(int dec_hp){
		hp-=dec_hp;
	}

	int User::GetHP(){
		return this->hp;
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
	if (map[user_y][user_x] == 4) { return 0;}}//이게 왜있어야하는지 모르겠다?