#include <vector>
#include <iostream>
using namespace std;


void Print(vector<int> v){
    for (auto& e : v)
        cout << e << " ";
    cout << endl;
}


int main(void){
    vector<int> v;
    for(int i =0;i<10 ; ++i){
        v.push_back(i);
    }

    cout << "현재의 v = ";
    Print(v);

    auto it = v.begin() +5;
    v.insert(it,100);
    
    cout << "5번 인덱스를 제거한후 v = ";
    Print(v);
    
    return 0;
}