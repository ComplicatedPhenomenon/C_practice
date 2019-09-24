// https://stackoverflow.com/questions/766893/how-do-i-modify-a-pointer-that-has-been-passed-into-a-function-in-c

/**
 * Create an array in a function.
 * call this function in main and manage with this array
 **/
#include<stdio.h>

int *getArray(){
    static int array[20];
    int i;

    for (i=0; i < 10; ++i) array[i] = i;

    return array;
}


void getArray_1(){
    int array[10];
    int i;


    for (i=0; i < 10; ++i) array[i] = i;
    for (i=0; i < 10; ++i) printf("%d\n", array[i]);
    printf("You can do nothing with this array in getArray_1\n");
    return ;
}


int main(){
    int *ptrToFunction;
    int i;

    ptrToFunction = getArray();
    for(i=0; i < 10; i++){
        printf ("*(ptrToFunction + %d) : %d\n",i ,*(ptrToFunction+i));
    }


    getArray_1();

    return 0;
}