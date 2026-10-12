#include <iostream>
using namespace std;

void swap(int& x,int& y){
    int tmp = x;
    x =y;
    y = tmp;
}
int main(int argc,char *argv[]){
    cout << argc <<endl;

    for (int i=0;i<argc;i++){
        cout << i <<":"<< argv[i] << endl;
    }
    return 0 ;
}