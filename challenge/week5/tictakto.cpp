#include <iostream>
using namespace std;

int main ()
{
    char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    int k = 0;
    char who = '\0';

    while(true){
        switch(k%2){
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
        cout << who <<"의 차례입니다. Y X 를 입력하여 말을 놓으시오 : ";
        k++;
        
        int goX = 0;
        int goY = 0;
        cin >> goX >>goY;

        cout<<"yx0_1_2_"<<endl
                    <<"0|"<<board[0][0]<<"|"<<board[0][1]<<"|"<<board[0][2]<<"|"<<endl
                    <<"1|"<<board[1][0]<<"|"<<board[1][1]<<"|"<<board[1][2]<<"|"<<endl
                    <<"2|"<<board[2][0]<<"|"<<board[2][1]<<"|"<<board[2][2]<<"|"<<endl
                    <<"ㅡㅡㅡㅡ"<<endl;

        while (true){
            if (board[goX][goY]==' ')
            {
                board[goX][goY]=who;

                cout<<"yx0_1_2_"<<endl
                    <<"0|"<<board[0][0]<<"|"<<board[0][1]<<"|"<<board[0][2]<<"|"<<endl
                    <<"1|"<<board[1][0]<<"|"<<board[1][1]<<"|"<<board[1][2]<<"|"<<endl
                    <<"2|"<<board[2][0]<<"|"<<board[2][1]<<"|"<<board[2][2]<<"|"<<endl
                    <<"ㅡㅡㅡㅡ"<<endl;

                
                break;
            }

            cout << who <<"그 자리엔 이미 말이 있습니다. 다른곳에 말을 놓으시오 : ";
            cin >> goX >>goY;
        }


        int score[3]={0,0,0};//점수계산부분
        int whoint =0;
        char whowin ='\0';


        for(int x=0;x<3;x++){
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

        for(int y=0;y<3;y++){
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

        for(int j=0;j<3;j++){
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



        for(int j=0;j<3;j++){
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

        if(whowin!='\0'){
            cout << " " <<whowin<<" 이 이게임의 승자입니다." << endl;
            return 0;
        }
        if(k>=9){
            cout << whowin<<"게임에 승자가 없습니다." << endl;
            return 0;
        }

        cout <<"ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ"<< endl;
    }
    return 0;
}
