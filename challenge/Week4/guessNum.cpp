#include <iostream>
#include <time.h>
using namespace std;

int main(){
    srand(time(NULL));
    
    int answer = rand()%100;
    int treies = 0;
    
    int guess;
    cout << "답은 0~99까지의 숫자입니다. 시도하십시오  : ";

    cin >> guess;
    while( guess!=answer){

        if (answer > guess)
        {
            cout << "답은 그것보다 더 큽니다. 재시도 :";
        }
        else
        {
            cout << "답은 그것보다 더 작습니다. 재시도 :";
        }
        treies++;
        cin >> guess;

    }

    cout << "축하합니다. 시도횠수 :" << treies <<endl;
    return 0;

}