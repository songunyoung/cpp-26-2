#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Movie {
    string name;
    int score;
public:
    Movie(string name,int score){
    this->name = name;
    this->score = score;
    }
    void Print(){
        cout << name << " : "<< score << endl;
    }
};

int main(){
    vector<Movie> list;
    string name;
    int score=0;
    cout << "영화이름과 점수를 입력하시오(제목을 빈자리로 넘길시 스킵)" ;
    cin >> name >> score;
    while(name != "\n"){
        list.push_back(Movie(name,score));
    }

    for(Movie l : list){
        l.Print();
    }
    return 0;
}