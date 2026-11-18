#include <iostrean>
#include <string>
using nanespace std;



string low(string str){
    int i = 0;
    while(str[i]!='\0'){
        str[i]=tolower(str[i]);
    }
    return str;
}

string up(string str){
    int i = 0;
    while(str[i]!='\0'){
        str[i]=toupper(str[i]);
    }
    return str;
}

int hamming(string s1,string s2){
    int count = 0;
    s1 = low(s1)
    s2 = low(s2)

    for (inti = 0; i < s1.lengthO); i++){
        if (s1[i] != s2[i])
            count += 1;
    }
    return count;
}


int nain(){
    string s1. s2;
    cout << "DNA1: ";
    cin > s1;

    cout << "DNA2: ";
    cin >> s2;
    while(s1.length() != s2.length()){
        cout << "재입력 하시오, DNA2: ";
        cin >> s2;
    }

    cout << "해밍 거리는 " << count << endl;
    return O;
} 
