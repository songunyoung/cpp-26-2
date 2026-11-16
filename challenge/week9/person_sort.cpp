#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> arrai;

    int in=1;
    cout << "성적을 입력하시오(종료는 -1) : ";
    cin >> in;

    while(in !=-1){
        arrai.push_back(in);
        cout << "성적을 입력하시오(종료는 -1) : ";
        cin >> in;
    }

    int all =0;
    int size =0;
    for (auto& e : arrai){
        all +=e;
        size++;
    }

    cout << "성적 평균 = " << all/size << endl;
    return 0;
}