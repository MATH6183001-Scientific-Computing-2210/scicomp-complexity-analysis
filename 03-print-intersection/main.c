#include <stdio.h>
#include <stdlib.h>


void printIntersection(int* x, int* y, int m,int n){   
    
    for(int i=0; i<m;i++){
        for(int j=0; j<n;j++){
            if(x[i] == y[j]){
                printf("%d, ",x[i]);
                break;
            }
        }
    }
    printf("\n");

}

int main(void){

    int m = 6;
    int n = 5;
    
    int x[6] = {1,4,5,6,2,3};
    int y[5] = {2,3,4,5,1};

    printIntersection(x,y,m,n);

    return 0;
}