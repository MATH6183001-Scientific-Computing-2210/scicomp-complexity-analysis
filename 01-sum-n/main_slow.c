#include <stdio.h>


int sumN(int n){
    int sum = 0;
    while(n>0){
        sum += n;
        n--;
    }

    return sum;
}

int main(void){

    int n = 10;
    printf("n=%d, sum(n) = %d \n", n, sumN(n));

    return 0;
}