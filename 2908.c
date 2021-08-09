#include <stdio.h>

int main(){
    //변수
    int first, second;
    int nFirst, nSecond;

    //입력
    scanf("%d %d", &first, &second);    

    //연산
    nFirst = 100*(first%10) + 10*((first%100)/10) + first/100;   
    nSecond = 100*(second%10) + 10*((second%100)/10) + second/100;

    //출력
    if(nFirst > nSecond) printf("%d", nFirst);
    else printf("%d", nSecond);

    return 0;
}
