/**
 *   Modified Date:
 *   Description:
 **/
 
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
/**************************************************************************
 *The struct keyword is used to define, or to refer to, a structure type. *
 * A typedef, in spite of the name, does not define a new type;           *
 * it merely creates a new name for an existing type                      *
 * ************************************************************************/
typedef struct person{
    char *name;
    int age;
    int height;
    int weight;
} Person;
/* the return type of function person_create is a structure */
Person *person_create(char *name, int age, int height, int weight){
    Person *who = malloc(sizeof(Person));
    /* create a structure by applying a piece of raw memory from OS
     * pass the parameter of struct person to malloc */
    assert(who != NULL);
    /* make sure get an effective piece of memory. */
    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight=weight;
    /**********************************************************************
     * Initialize the members in struct person , use `strdup` to copy string	 * name, in order to make sure the struct really own it x->y is short
     * for  (*x).y
     * ********************************************************************/
    return who;
}

void person_destroy(Person *who){
    assert(who != NULL);

    free(who->name);
    free(who);
}

void person_print(Person* who){
    printf("Name: %s\n", who->name);
    printf("Age: %d\n", who->age);
    printf("Height: %d\n", who->height);
    printf("Weight: %d\n", who->weight);
}

int main(int argc, char *argv[]){
    Person *joe = person_create("Joe Alex", 32, 64, 140);
    Person *frank ;
    frank = person_create("Frank Blank", 20, 72, 180);

    printf("Size of struct person %lu\n", sizeof(joe));
    printf("Frank is at the men=mory location %p :\n", joe);
    person_print(joe);
    printf("Frank is at the men=mory location %p :\n", frank);
    person_print(joe);

    person_destroy(joe);
    person_destroy(frank);

    return 0;
}