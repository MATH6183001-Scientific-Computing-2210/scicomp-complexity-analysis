#include <stdio.h>
#include <stdlib.h>


void countRowNumber(int* matrix){   
    int m = 0;
    int n = 0;
    char tmpM = 'a';
    char tmpN = 'a';

    while(tmpN != '\0'){
        tmpN = matrix[n];
        n++;
    }

    n--;

    while(tmpM != '\0'){
        tmpM = matrix[(n+1)*m];
        m++;
    }

    m--;
    

    printf("m=%d,n=%d\n",m,n);

}

int main(void){

    int M = 5;
    int N = 4;
    
    int matrix[(M+1)*(N+1)];

    for(int m=0; m<M; m++){
        for(int n=0; n<N; n++){
            matrix[M*m+n] = 'a';
        }
        matrix[M*m+N] = '\0';
    } 
    for(int n=0; n<=N; n++){
        matrix[M*M+n] = '\0';
    }
    
    for(int m=0; m<=M; m++){
        for(int n=0; n<=N; n++){
            printf("%c",matrix[M*m+n]);
        }
        printf("\n");
    } 

    countRowNumber(matrix);
    


    return 0;
}