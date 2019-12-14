#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <sched.h>

//define the rwlock struct
typedef struct _rwlock_t {
    sem_t writelock;
    sem_t lock;
    int readers;
} rwlock_t;

//rwlock init function
void rwlock_init(rwlock_t *lock) {
    lock->readers = 0;
    sem_init(&lock->lock,0,1); 
    sem_init(&lock->writelock,0,1); 
}

//rwlock acquire readlock function
void rwlock_acquire_readlock(rwlock_t *lock) {
    sem_wait(&lock->lock);
    lock->readers++;
    if (lock->readers == 1)
	    sem_wait(&lock->writelock);
    sem_post(&lock->lock);
}

//rwlock release readlock function
void rwlock_release_readlock(rwlock_t *lock) {
    sem_wait(&lock->lock);
    lock->readers--;
    if (lock->readers == 0)
	    sem_post(&lock->writelock);
    sem_post(&lock->lock);
}

//rwlock acquire writelock function
void rwlock_acquire_writelock(rwlock_t *lock) {
    sem_wait(&lock->writelock);
}

//rwlock release writelock function
void rwlock_release_writelock(rwlock_t *lock) {
    sem_post(&lock->writelock);
}

int read_loops;
int write_loops;
int counter = 0;

rwlock_t mutex;

//reader function
void *reader(void *arg) {
    int i;
    int local = 0;
	int thread_numb = *(int *)arg; //save current thread number

    for (i = 0; i < read_loops; i++) {
	rwlock_acquire_readlock(&mutex); //readlock acquire
	sleep(rand()%5); //sleep random time 0~5
	local = counter; //critical section
	rwlock_release_readlock(&mutex); //readlock release
	printf("thread%d-read %d\n",thread_numb,local); //print thread num, local
    }
    printf("read%d done: %d\n",thread_numb ,local);
    return NULL;
}

//writer function
void *writer(void *arg) {
    int i;
	int thread_numb = *(int *)arg; //save current thread number
	
    for (i = 0; i < write_loops; i++) {

	rwlock_acquire_writelock(&mutex); //writelock acquire
	sleep(rand()%5); //sleep random time 0-5
	counter++; //critical section
    printf("thread%d-write %d\n",thread_numb,counter); //print thread num, counter
	rwlock_release_writelock(&mutex); //writelock release
    }
    printf("write done\n");
    return NULL;
}

//main function
int main(int argc, char *argv[]) {
    //exception
    if (argc != 3) {
	fprintf(stderr, "usage: rwlock readloops writeloops\n");
	exit(1);
    }
    read_loops = atoi(argv[1]); //save read loop
    write_loops = atoi(argv[2]); //save write loop
    int thread_numb[2] = {1,2}; //define thread number
    rwlock_init(&mutex); //rwlock initialize
    pthread_t c1, c2;
    //create 1 reader , 1 writer thread
	printf("1 reader, 1 writer\n");
    pthread_create(&c1, NULL, reader,thread_numb);
    pthread_create(&c2, NULL, writer,thread_numb+1);
	pthread_join(c1, NULL);
    pthread_join(c2, NULL);
	printf("==============done==============\n");
    //create 2 reader thread
	printf("2 reader\n");
	pthread_create(&c1,NULL,reader,thread_numb);
	pthread_create(&c2,NULL,reader,thread_numb+1);
	pthread_join(c1,NULL);
	pthread_join(c2,NULL);
	printf("===========done==============\n");
    //create 2 writer thread
	printf("2 writer\n");
	pthread_create(&c1,NULL,writer,thread_numb);
	pthread_create(&c2,NULL,writer,thread_numb+1);
	pthread_join(c1,NULL);
	pthread_join(c2,NULL);
	printf("===========done==============\n");

    printf("all done\n");
    return 0;
}









