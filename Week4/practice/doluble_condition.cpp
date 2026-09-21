#include <stdio.h>
using namespace std;

int main()
{
    int number1, number2;

    printf("두 양수를 입력하시오");
    scanf_s("%d %d",&number1, &number2);

    if (number1 >0 ){
        if(number2 > 0){
            printf("%d, %d 두 숫자모두 양수입니다.\n", number1,number2);
        }
        else{
            printf("%d 맨 앞 양수입니다.\n", number1);
        }
    }
    else{
        printf("%d 는 0 이거나 음수입니다. \n", number1);
    }

    return 0;
}