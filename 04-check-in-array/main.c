#include <stdio.h>
#include <stdlib.h>


int checkInArray(int* x, int* y, int m, int n, int k){   
    
    int result1 = 0;
    int result2 = 0;
    for(int i=0; i<m;i++){
        if(x[i]==k){
            result1 = 1;
            break;
        }
    }
    for(int j=0; j<n;j++){
         if(y[j]==k){
            result2 = 1;
            break;
        }
    }
    return result1 & result2;

}

int main(void){

    int m = 6;
    int n = 5;
    
    int x[6] = {1,4,5,6,2,3};
    int y[5] = {2,3,4,5,1};

    printf("%d\n",checkInArray(x,y,m,n,6));

    return 0;
}