#include <stdio.h>

int main(){
    int x, y, w, h, a, b;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    a = x > w-x ? w-x : x, b = y > h-y ? h-y : y;
    printf("%d", a > b ? b : a);    
    return 0;
}
