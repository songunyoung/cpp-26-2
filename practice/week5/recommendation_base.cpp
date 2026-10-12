#include <iostream>
using namespace std;

int main(){
    const int NUM_USERS=3;
    const int NUM_ITEMS=3;
    int userPreferences[NUM_USERS][NUM_ITEMS];

    for (int i =0; i < NUM_USERS ; ++i){
        cout << "사용자" << (i +1) << "의 선호도를 입력하세요";
        cout << NUM_ITEMS<< "개의 항목에 대해): ";
         for (int j =0; j < NUM_ITEMS ; ++j){
            cin >> userPreferences[i][j];
         }
    }

    for (int i =0; i < NUM_USERS ; ++i){
        int maxPreferenceIndex = 0;
         for (int j =1; j < NUM_ITEMS ; ++j){
            if ( userPreferences[i][j] > userPreferences[i][maxPreferenceIndex])
                maxPreferenceIndex = j; 
        }

        cout << "사용자" << (i + 1) << "에게 추천하는 항목 : ";
        cout << (maxPreferenceIndex +1) << std::endl;
    }
    
    return 0 ;
}