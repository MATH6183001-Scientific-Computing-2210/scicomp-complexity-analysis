#include <stdio.h>
#include <stdlib.h>


int sumElementMatrix(int* matrix,int M,int N){   
    
    int sum = 0;
    for(int m=0; m<M; m++){
        for(int n=0; n<N; n++){
            sum += matrix[M*m+n];
        }
    }

    return sum;

}

int main(void){

    int M = 4;
    int N = 3;
    int* matrix = (int*) malloc(M*N*sizeof(int));
    for(int m=0; m<M; m++){
        for(int n=0; n<N; n++){
            matrix[M*m+n] = M*m+n;
        }
    } 
    printf("sum = %d \n", sumElementMatrix(matrix,M,N));

    free(matrix);

    return 0;
}