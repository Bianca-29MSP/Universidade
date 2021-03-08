//Calcula MDC
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y, r;
    int mdc;
    int aux;
    scanf("%d %d", &x, &y);
    
    r = x % y;
    mdc = y;
    
    while(r != 0) {
        aux = r;
        r = y % r;
        y = aux;
        mdc = y;
    }
    
    printf("MDC = %d\n", mdc);
    
    return 0;
}