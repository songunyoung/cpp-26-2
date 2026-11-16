#include <iostream>
using namespace std;

int main ()
{
    char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    int k = 0;
    char who = '\0';

    cout<<"yx0_1_2_"<<endl//판을 출력하는 코드이다. 반복문에도 들어가있다.
                    <<"0|"<<board[0][0]<<"|"<<board[0][1]<<"|"<<board[0][2]<<"|"<<endl
                    <<"1|"<<board[1][0]<<"|"<<board[1][1]<<"|"<<board[1][2]<<"|"<<endl
                    <<"2|"<<board[2][0]<<"|"<<board[2][1]<<"|"<<board[2][2]<<"|"<<endl
                    <<"ㅡㅡㅡㅡ"<<endl;

    while(true){
        switch(k%3){ // 서로 번갈아 기며 말을 놓기위해 who변수에 O X, Y까지 넣고 감지할수 있게 해놓았다.
            case 0:
                who = 'O';
                break;
            case 1:
                who = 'X';
                break;
            case 2:
                who = 'Y';
                break;
        }
        
        
        int goX = 0;
        int goY = 0;
                    
        cout << who <<"의 차례입니다. Y X 를 입력하여 말을 놓으시오 : ";
        k++;
        cin >> goX >>goY;

        while (true){
            if (board[goX][goY]==' ')//넣을 칸에 빈자리인지 확인하는 코드다. 빈자리(정확힌 '  ')이아니라면 다시 입력하도록 한다..
            {
                board[goX][goY]=who;

                cout<<"yx0_1_2_"<<endl
                    <<"0|"<<board[0][0]<<"|"<<board[0][1]<<"|"<<board[0][2]<<"|"<<endl
                    <<"1|"<<board[1][0]<<"|"<<board[1][1]<<"|"<<board[1][2]<<"|"<<endl
                    <<"2|"<<board[2][0]<<"|"<<board[2][1]<<"|"<<board[2][2]<<"|"<<endl
                    <<"ㅡㅡㅡㅡ"<<endl;

                
                break;
            }

            cout << "그 자리엔 이미 말이 있습니다. 다른곳에 말을 놓으시오 : ";
            cin >> goX >>goY;
        }






        int score[3]={0,0,0};//점수계산부분
        int whoint =0;
        char whowin ='\0';


        for(int x=0;x<3;x++){//세로로 3줄이 있는지 확인하는 계산
            for(int y=0;y<3;y++){
                switch(board[y][x]){
                case 'O':
                    whoint =0 ;
                    score[0]++;
                    break;
                case 'X':
                    whoint =1 ;
                    score[1]++;
                    break;
                case 'Y':
                    whoint =2 ;
                    score[2]++;
                    break;
                }
                if(score[whoint]<=y)
                    break; // 줄 중에 다른것이 나왔으면 바로 반복문을 나오게 구현했다.
            }
            if(score[whoint]==3){// 줄을 만들었을때 승자를 지정한다.
                switch(whoint){
                case 0:
                    whowin ='O';
                    break;
                case 1:
                    whowin ='X';
                    break;
                case 2:
                    whowin ='Y';
                    break;
                }
                break;
            }
            for(int i=0;i<3;i++)
            score[i]=0;
        }

        for(int y=0;y<3;y++){//여긴 가로줄을 확인하는 계산이다.
            for(int x=0;x<3;x++){
                switch(board[y][x]){
                case 'O':
                    whoint =0 ;
                    score[0]++;
                    break;
                case 'X':
                    whoint =1 ;
                    score[1]++;
                    break;
                case 'Y':
                    whoint =2 ;
                    score[2]++;
                    break;
                }
                if(score[whoint]<=y)
                    break;
            }
            if(score[whoint]==3){
                switch(whoint){
                case 0:
                    whowin ='O';
                    break;
                case 1:
                    whowin ='X';
                    break;
                case 2:
                    whowin ='Y';
                    break;
                }
                break;
            }
            for(int i=0;i<3;i++)
            score[i]=0;
        }

        for(int j=0;j<3;j++){//대각선을 확인하는 계산이다.
            switch(board[j][j]){
                case 'O':
                    whoint =0 ;
                    score[0]++;
                    break;
                case 'X':
                    whoint =1 ;
                    score[1]++;
                    break;
                case 'Y':
                    whoint =2 ;
                    score[2]++;
                    break;
            }
            if(score[whoint]<=j)
                break;
        }
        if(score[whoint]==3){
        switch(whoint){
                case 0:
                    whowin ='O';
                    break;
                case 1:
                    whowin ='X';
                    break;
                case 2:
                    whowin ='Y';
                    break;
                }
        }
        for(int i=0;i<3;i++)
            score[i]=0;



        for(int j=0;j<3;j++){//대각선을 확인하는 두번째 계산이다.
            switch(board[2-j][j]){
                case 'O':
                    whoint =0 ;
                    score[0]++;
                    break;
                case 'X':
                    whoint =1 ;
                    score[1]++;
                    break;
                case 'Y':
                    whoint =2 ;
                    score[2]++;
                    break;
            }
            if(score[whoint]<=j)
                break;
        }
        if(score[whoint]==3){
        switch(whoint){
                case 0:
                    whowin ='O';
                    break;
                case 1:
                    whowin ='X';
                    break;
                case 2:
                    whowin ='Y';
                    break;
                }
        }
        for(int i=0;i<3;i++)
            score[i]=0;

        if(whowin!='\0'){//승자를 확인하는 계산이다.
            cout << " " <<whowin<<" 이 이게임의 승자입니다." << endl;
            return 0;
        }
        if(k>=9){//9턴이 지나면 게임에 승자가 없다.
            cout << "게임에 승자가 없습니다." << endl;
            return 0;
        }

        //승자가 안나왔을시 계속하는줄
        cout <<"ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ"<< endl;
    }
    return 0;
}
