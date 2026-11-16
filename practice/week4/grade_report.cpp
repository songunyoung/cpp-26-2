#include <iostream>
using namespace std;

int main(){
    const int STUDENT = 5;
    const int SUBJECT = 3;

    int scores[STUDENT][SUBJECT];
    string studentName[STUDENT]
    ={"영수","영희","철수","미미","쥬쥬"};
    string subjectName[SUBJECT]
    ={"수학","영어","CPP"};

    
    for (int i =0;i < STUDENT; i++){
        cout << studentName[i] 
        << "의 성적을 하니씩 입력하세요." <<endl;
        for(int j; j< SUBJECT; j++){
            cout << subjectName[j] << ":";
            cin >> scores[i][j];
        }
    }

     for (int i =0;i < STUDENT; i++){
        cout << studentName[i]  << "의 평균점수는 " <<endl;
        double sum =0;
        double average =0;
        for(int j; j< SUBJECT; j++){
            sum +=scores[i][j];
        }
        average = sum / SUBJECT;
        cout << average << "입니다"<<endl;
    }
    return 0;
}