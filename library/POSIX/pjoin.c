#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void print_message_func(void *ptr);

int main() {
    int tmp1,tmp2;
    void *retival;
    pthread_t thread1,thread2;
    char *message1 = "thread1";
    char *message2 = "thread2";

    int ret_thread1,ret_thread2;
    ret_thread1 = pthread_create(&thread1, NULL, (void *)&print_message_func, (void *)message1);
    ret_thread2 = pthread_create(&thread2, NULL, (void *)&print_message_func, (void *)message2);

    if(ret_thread1 == 0)
        printf("Successfully create thread 1 \n");
    else
        printf("Failed to create thread 1 \n");

    if(ret_thread2 == 0)
        printf("Successfully create thread 2 \n");
    else
        printf("Failed to create thread 2 \n");

    // int pthread_join(pthread_t thread, void **status);
    tmp1 = pthread_join(thread1,&retival); //If successful, pthread_join() returns 0.
    printf("thread 1 return value (retival) is %d\n",(int)retival);
    printf("thread 1 return value (tmp1) is %d\n",tmp1);

    if(tmp1 != 0)
        printf("cannot join with thread 1\n");
    printf("thread 1 is end\n");

    tmp2 = pthread_join(thread2,&retival);
    printf("thread 2 return value (retival) is %d\n",(int)retival);
    printf("thread 2 return value (tmp2) is %d\n",tmp2);

    if(tmp2 != 0)
        printf("cannot join with thread 2\n");
    printf("thread 2 is end\n");

}

void print_message_func(void *ptr){
    for(int i=0;i<5;++i)
        printf("%s:%d\n",(char*)ptr,i);
}
