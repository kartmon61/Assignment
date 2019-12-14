#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUMB_THREADS 2



typedef struct _rwlock_t{
    sem_t lock;
    sem_t writelock;
    int readers;
} _rwlock_t;

void rwlock_init(_rwlock_t* rw){
    rw->readers = 0;
    sem_init(&rw->lock,0,1);
    sem_init(&rw->writelock,0,1);
}

void rwlock_acquire_readlock(rwlock_t* rw){
    sem_wait(&rw->lock);
    rw->readers++;
    if(rw->readers == 1){
        sem_wait(&rw->writelock);
    }
    sem_post(&rw->lock);
}

void rwlock_release_readlock(rwlock_t* rw){
    
}

void rwlock_acquire_writelock(rwlock_t* rw){
    sem_wait(&rw->writelock);
}

void rwlock_release_writelock(rwlock_t* rw){
    sem_post(&rw->writelock);
}

int main(int argc, int** argv){
    rwlock_init();

    pthread_t thread[NUMB_THREADS];
    int thread_numb[NUMB_THREADS];
    int i;
    for(i=0;i<NUMB_THREADS;){
        thread_numb[i] = i;
        pthread_create(thread + i, NULL,,thread_numb+i);
        i++;
        thread_numb[i] = i;

        pthread_create(&thread[i],NULL,consumer,&*thread_numb[i]);
        i++;
    }

    for(i=0;i<NUMB_THREADS;i++){
        pthread_join(thread[i],NULL);
    }
}