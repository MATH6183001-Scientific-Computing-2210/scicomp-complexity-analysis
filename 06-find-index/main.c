#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct loc{
    int lb;
    int ub;
    int pivot;
    int length;
};

typedef struct loc loc;

void calculateLengthAndPivot(loc* l){
    l->length = l->ub - l->lb + 1;
    if(l->length%2 == 1){
        l->pivot = (int) (l->length/2)+1+l->lb-1;
    } else {
        l->pivot = l->length/2 + l->lb-1;
    }
}

void printLoc(loc l){
    printf("lb=%d\tub=%d\tpivot=%d\tlength=%d\n",l.lb,l.ub,l.pivot,l.length);
}

int checkTwoStringsEqual(char* x, char* y){


    int i = 0;

    if(
        (x[i]=='\0'&& y[i]!='\0') ||
        (x[i]!='\0'&& y[i]=='\0') 
        ) {
            return 0;
        }


    while(x[i]!='\0' && y[i]!='\0'){

        if(x[i] != y[i]){
            return 0;
        }

        i++;
    }

    if(x[i]=='\0' && y[i]=='\0'){
        return 1;
    }

    return 0;

}

int checkLessThanTwoStrings(char* x, char* y){
    // if x < y
    int i = 0;

    while(x[i]!='\0' && y[i]!='\0'){

        if(x[i] < y[i]){
            return 1;
        } else if (x[i] > y[i]){
            return 0;
        }
        
        i++;
    }

    if(x[i]=='\0' && y[i]=='\0'){
        return 0;
    } else if(x[i]=='\0' && y[i]!='\0'){
        return 1;
    } else if(x[i]!='\0' && y[i]=='\0'){
        return 0;
    }

    return 0;
}

int main(void){

    int N = 5;

    loc l;
    l.lb = 0;
    l.ub = N-1;

    calculateLengthAndPivot(&l);

    // List = [‘Abraham’, ‘Andi’, ‘Bryan’, ‘Charles’, ’Darwin’]
    char name1[]= "Abraham"; 
    char name2[]= "Andi"; 
    char name3[]= "Bryan"; 
    char name4[]= "Charles"; 
    char name5[]= "Darwin"; 

    char nameRef[] = "Charles";

    char** listNames = (char**) malloc(N*sizeof(char*));

    for(int i =0; i<N;i++){
        if(i==0){
            listNames[i] = &name1[0];
        } else if(i==1){
            listNames[i] = &name2[0];
        } else if(i==2){
            listNames[i] = &name3[0];
        } else if(i==3){
            listNames[i] = &name4[0];
        } else if(i==4){
            listNames[i] = &name5[0];
        }
    }

    printLoc(l);

    while(l.length!=1 && !checkTwoStringsEqual(listNames[l.pivot],nameRef)){
        printf("%s<%s = %d\n",
            listNames[l.pivot],
            nameRef,
            checkLessThanTwoStrings(listNames[l.pivot],nameRef)
            );
        if(checkLessThanTwoStrings(listNames[l.pivot],nameRef)){
            l.lb = l.pivot+1;
            calculateLengthAndPivot(&l);
        } else {
            l.ub = l.pivot-1;
            calculateLengthAndPivot(&l);
        }
        printLoc(l);
    }

    printf("The answer is: %d\n",l.pivot);

    return 0;
}