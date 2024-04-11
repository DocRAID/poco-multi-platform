#include <pthread.h> 
#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h>

int count=0;
#define LOOP_CNT 5
void* thread_routine(void *arg){  
    pthread_t tid;    
    tid=pthread_self();
    int i=0;       
    for(int i=0;i<10;i++){
        // int arg_cast=(int)arg;
        printf("%d's loop : %d\n",arg,i);
        count++;
    }
} 

int main(){    
    pthread_t thread[LOOP_CNT];
    for(int i=0;i<LOOP_CNT;i++){
        pthread_create(&thread[i],NULL,thread_routine, (void*)i);   
    } 
    for(int i=0;i<LOOP_CNT;i++){
        pthread_join(thread[i],nullptr);
    }
    printf("Count : %d\n", count);
}
//gcc -o a main.cpp -lpthread