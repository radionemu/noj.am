#include <stdio.h>

int main(){
    int num;
    scanf("%d", &num);

    int result = 0;
    for(int i = 1; i<= num; i++){
        if(i < 100) result++;
        else{
            int l = i/100, m = (i%100)/10, s = i%10;
            if(m-l == s-m) result++;
        }
    }
    printf("%d", result);

    return 0;
}
