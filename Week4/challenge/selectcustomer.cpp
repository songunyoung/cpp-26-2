#include <iostream>
#include <string>
using namespace std;

int main()
{
    //int maxPeople;
    //cout << "총 고객의 수를 입력하라.";
    //cin >> maxPeople;
    const int maxPeople = 3;

    string names[maxPeople];
    int ages[maxPeople];

    for(int i =0 ;i<maxPeople;i++)
    {
        cout << "고객의 이름과 나이를 입력하시오 : ";
        cin >> names[i];
        cin >> ages[i];
    }

    int ageThreshold;
    cout << "특정 나이 이상인 사람을 찾으려면 나이를 입력하세요 :";
    cin >> ageThreshold;
    cout << ageThreshold << "세 이상이 고객들 : \n";

    bool noThatPeople =1 ;
    for(int i =0 ;i<maxPeople;i++)
    {
        if(ages[i]>=ageThreshold)
        {
            cout << names[i] << " 님은 " << ageThreshold << "세 이상이십니다." << endl;
            noThatPeople =0;
        }
    }
    if(noThatPeople)
        cout << "조건에 맞는 사람을 찾을수 없습니다." << endl;

    return 0;
}