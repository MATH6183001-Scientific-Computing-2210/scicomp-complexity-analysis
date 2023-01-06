#include <stdio.h>


int sumN(int n){   
    return n*(n+1)/2;
}

int main(void){

    int n = 10;
    printf("n=%d, sum(n) = %d \n", n, sumN(n));

    return 0;
}