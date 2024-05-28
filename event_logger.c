#include"event_logger.h"
#include<pthread.h>
#include<stdio.h>
#include<time.h>

extern pthread_mutex_t mutex;
extern pthread_cond_t cond;

void *makeLog(){
    
    char log[100];
    char timeStr[50];

    //충돌 전까지 대기
    pthread_cond_wait(&cond, &mutex);
    //충돌 시

    //log.bin 파일 이어쓰기 모드로 열기
    FILE *file = fopen("log.bin","ab");

    if(file == NULL){
        printf("파일을 열 수 없습니다.");
        return 1;
    }

    get_current_time(timeStr);

    sprintf(log, "%s INFO : 충돌 감지\n", timeStr);

    //로그 남김 : [YY:MM:DD:HH:mm:SS] INFO : 충돌 감지
    fputs(log, file);

    puts("로그 남김");

    //thread 종료
    fclose(file);
}

void get_current_time(char *timeStr){
    time_t now;
    struct tm *timeinfo;

    time(&now);
    timeinfo = localtime(&now);

    strftime(timeStr, sizeof(char) * 20, "[%y-%m-%d %H:%M:%S]", timeinfo);

    puts(timeStr);
}

