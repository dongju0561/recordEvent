#include"event_detector.h"
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

extern pthread_mutex_t mutex;
extern pthread_cond_t cond;

void *detectCrush(){
    while (1)
    {
        sleep(2);
        puts("사고 발생!!");
        pthread_mutex_lock(&mutex);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);    
    }
    return NULL;
}