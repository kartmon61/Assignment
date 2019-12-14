typedef struct{
    int value;
    struct process* list;
} semaphore;

wait(semaphore* S){
    S->value--;
    if(S->value<0){
        add this process to S-> list;
        block();
    }
    while (S<=0);
    S--;

}

signal(semaphore* S){
    S->value++;
    if(S->value<=0){
        remove a process P from S->list;
        wakeup(P);
    }
}

Semaphore mutex;

do{
    wait(mutex);
    //critical
    signal(mutex);
    //remainder
}while(true);