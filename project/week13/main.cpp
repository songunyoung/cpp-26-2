#include "user.h"
using namespace std;


// 메인  함수
int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	vector<vector<int>> map = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };


	// 유저의 위치를 저장할 변수

	vector<User*> man;
	man.push_back(new Magician(20));
	man.push_back(new Warrior(20));
	int chose = 0; // man[chose]->

	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프
		// 사용자의 입력을 저장할 변수
		string user_input = "";

		cout << "체력이 "<< man[chose]->GetHP()<<"남았습니다. 명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
		cin >> user_input;

		if (user_input == "상") {
			// 위로 한 칸 올라가기
			man[chose]->user_y -= 1;
			bool inMap = checkXY(man[chose]->user_x, mapX, man[chose]->user_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				man[chose]->user_y += 1;
			}
			else {
				cout << "위로 한 칸 올라갑니다." << endl;
				displayMap(map, man[chose]->user_x, man[chose]->user_y);
				DecreaseHP(1);
			}
		}
		else if (user_input == "하") {
			// TODO: 아래로 한 칸 내려가기
			man[chose]->user_y += 1;
			bool inMap = checkXY(man[chose]->user_x, mapX, man[chose]->user_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				man[chose]->user_y -= 1;
			}
			else {
				cout << "위로 한 칸 내려갑니다." << endl;
				displayMap(map, man[chose]->user_x, man[chose]->user_y);
				DecreaseHP(1);
			}
		}
		else if (user_input == "좌") {
			// TODO: 왼쪽으로 이동하기
			man[chose]->user_x -= 1;
			bool inMap = checkXY(man[chose]->user_x, mapX, man[chose]->user_y, mapY);

			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				man[chose]->user_x += 1;
			}
			else {
				cout << "왼쪽으로 이동합니다." << endl;
				displayMap(map, man[chose]->user_x, man[chose]->user_y);
				DecreaseHP(1);
			}
		}
		else if (user_input == "우") {
			// TODO: 오른쪽으로 이동하기
			man[chose]->user_x += 1;
			bool inMap = checkXY(man[chose]->user_x, mapX, man[chose]->user_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				man[chose]->user_x -= 1;
			}
			else {
				cout << "오른쪽으로 이동합니다." << endl;
				displayMap(map, man[chose]->user_x, man[chose]->user_y);
				DecreaseHP(1);
			}
		}
		else if (user_input == "지도") {
			// TODO: 지도 보여주기 함수 호출
			displayMap(map, man[chose]->user_x, man[chose]->user_y);
		}
		else if (user_input == "종료") {
			cout << "종료합니다.";
			exit(0);
		}
		else {
			cout << "다시 입력하십시오";
		}


		switch(map[man[chose]->user_x][man[chose]->user_y]){
			case 0 :
				cout << "당신은 앞으로 나아갔습니다." <<endl;
				break;
			
			case 1 :
				cout << "나아간곳에서 전투에 쓸만한 물건을 발견했습니다.";
				break;
			
			case 2 :
				
				doAttack();
				DecreaseHP(2);
				
				break;
			
			case 3 :
				cout << "나아간 곳에 놓인 수상쩍은 포션을 마셨습니다. 2hp를 회복합니다.";
				IncreaseHP(2);
				break;
			case 4 :
				cout << "목적지에 도달했습니다. 게임을 종료합니다.";
				exit(0);
				break;
			
			default:
				cout << "????";
				break;
		}

		if (!CheckUser(*this)){
			cout << "체력이 다 떨어졌습니다. 힘아 다합니다. 게임 종료....";
			exit(0);
		}
		// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지

		if(chose == 0) chose =1;
		else chose =0;

	}//반복문
}

// 지도와 사용자 위치 출력하는 함수
void displayMap(int map[][mapX], int man[chose]->user_x, int man[chose]->user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == man[chose]->user_y && j == man[chose]->user_x) {
				cout << " USER |"; // 양 옆 1칸 공백
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6칸 공백
					break;
				case 1:
					cout << "아이템|";
					break;
				case 2:
					cout << "  적  |"; // 양 옆 2칸 공백
					break;
				case 3:
					cout << " 포션 |"; // 양 옆 1칸 공백
					break;
				case 4:
					cout << "목적지|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}







