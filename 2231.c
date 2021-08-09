#include <stdio.h>

int d(int n);

int main(){
    int input;
    scanf ("%d", &input);
    for(int i = 1; i < input; i++){
        if (d(i) == input){
            printf("%d", i);
            return 0;
        }
    }
    printf("0");

    return 0;
}

int d(int n){
    int result = n + (n/1000000) + (n%1000000)/100000 + (n%100000)/10000 + (n%10000)/1000 + (n%1000)/100 + (n%100)/10 + (n%10);
    return result;
}
