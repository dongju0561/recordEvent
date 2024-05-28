#include<stdio.h>
#include<pthread.h>
#include"event_detector.h"
#include"event_logger.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int main(){
    pthread_t detector, logger;

    pthread_create(&detector, NULL, detectCrush, NULL);
    pthread_create(&logger, NULL, makeLog, NULL);

    pthread_join(detector,NULL);
    pthread_join(logger,NULL);
}

