#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    const int numCell = 10;
    int numList[numCell][numCell];


    for(int i =0 ;i<numCell;i++){
        for(int j =0 ;j<numCell;j++){
            numList[i][j] = rand()%1000;
        }
    }

    cout << endl;

    int max=numList[0][0];
    int maxI,maxJ;

    for(int i =0 ;i<numCell;i++){
        for(int j =0 ;j<numCell;j++){
            if(max < numList[i][j]){
                    max = numList[i][j];
                    maxI = i;
                    maxJ = j;
                }
        }
    }

    cout << "가장 큰 값은 " << max << "이고,";
    cout << "i j값은 각각" << maxI<<", "<< maxJ << "입니다."<<endl;
    cout << "검증결과 " << numList[maxI][maxJ] <<endl;

    return 0;
}