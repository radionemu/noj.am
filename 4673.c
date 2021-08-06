#include <stdio.h>

int d(int n);
    int arr[10000] = {0, };

int main(){
    for(int i = 1; i<=10000; i++){
        d(i);
    }
    for(int i = 1; i<=10000; i++){
        if(!arr[i])
            printf("%d\n", i);
    }

    return 0;
}

int d(int n){
    int result = n + (n/10000) + (n%10000)/1000 + (n%1000)/100 + (n%100)/10 + n%10;
    if(result > 10000) return 0;
    arr[result]++;
    return d(result);
}
