#include <stdio.h>

int main(){
    int x, y, w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    printf("%d", ((w-x) > (h-y)) ? w-x : h-y);    
    return 0;
}
