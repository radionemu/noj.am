#include <stdio.h>

int main(){
    char arr[1000001] = {0, };
    scanf("%[^\n]", &arr);
    int init = 0;
    int result = 0;
    //계산
    
    for(int i = 0; arr[i] < 1000001; i++){
        if((int)arr[i] == 32){
            continue;
        }else if((int)arr[i] != 32 && (int)arr[i] !=0){
            init = i;
            break;
        }else{
            break;
        }
    }


    for(int j = init; arr[j] < 1000001; j++){
        if((int)arr[j] == 32){
            result ++;
            continue;
        }
        if((int)arr[j] == 0){
            result ++;
            break;
        }else{
            continue;
        }
    }
    //출력
    printf("%d", result);


    return 0;
}
