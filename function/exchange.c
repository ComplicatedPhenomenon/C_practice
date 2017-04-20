#include<stdio.h>

int main()
{
	char a[10];
	char b[10];
	char *A[10];
	char *B[10];
        char *c[10];

	A = "Alive";
	B = "Dead"
	a = A;
	b = B;
        /*a = "alive";
	 *b = "dead";
	 *assignment to expression with array type*/

	printf("before exchanging, a is : %s\n", a);
	printf("before exchanging, b is : %s\n", b);
	printf("---------------------------\n");

/*	c = &a;
	a = &b;
	b = *c; */
	printf("before exchanging, a is : %s\n", a);
	printf("before exchanging, b is : %s\n", b);


	return 0;
}

/*The problem with arrays is that in all expressions (except...)
 * they convert to a pointer to their first element 
 * so suppose you have:
 * int arr1[10];
 * int arr2[10];
 * ...
 * then if you write something like
 * arr1 = arr2;
 * you are actually attempting to do this;
 * arr1 = &arr2[0]
 * or this
 * &arr1[0] = &arr2[0]
 * In both cases you have a problem preventing your code from compiling, 
 * In the former case you're attempting to assign between two incompatible 
 * types (array vs pointer), while in the latter case you're attempting to modify
 * a constant pointer(&arr1[0] )  */
