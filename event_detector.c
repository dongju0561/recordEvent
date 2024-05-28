#include"event_detector.h"
#include<pthread.h>
#include<unistd.h>

extern pthread_mutex_t mutex;
extern pthread_cond_t cond;

void *detectCrush(){
    sleep(1);
    pthread_cond_signal(&cond);
}