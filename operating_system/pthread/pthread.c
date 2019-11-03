#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//task 실행 함수
void* task(int id){
    printf("Task %d started\n",id);
    int i;
    double result = 0.0;
    //많은 작업 실행
    for(i=0;i<100000;i++){
        result = result + sin(i)*tan(i);
    }
    //작업 종료 출력
    printf("Task %d completed with result %e\n",id,result);
}

//시리얼 task 실행 함수
void* serial(int num_tasks;i++){
    int i;
    for(i=0;i<num_tasks;i++){
        task(i); //i번째 task 호출
    }
}

//스레드 task 실행 함수
void* threaded_task(void *t){
    long id = (long) t;
    printf("Thread %id started\n",id); //스레드 실행 출력
    task(id); //task 함수 호출
    printf("Thread *id done\n",id); //스레드 종료 출력
    pthread_exit(0); //스레드 정상 종료
}

//parallel task 실행 함수
void* parallel(int num_tasks){
    int num_threads = num_tasks; //전달받은 task 개수 저장
    pthread_t thread[num_threads]; //task의 개수 만큼  스레드 배열 생성
    int rc;
    long t;
    for(t=0;t<num_threads;t++){
        printf("Creating thread %id\n",t);
        //스레드 배열의 index 접근을 통해 스레드 생성, threaded_task 동작함수 대입
        rc = pthread_create(&thread[t],NULL,threaded_task,(void*)t);
        if(rc){
            printf("ERROR: return code from pthread_create() is %d\n",rc);
            exit(-1);//문제 발생 종료
        }
    }
}

//동작 task 출력 함수
void* print_usage(int argc,char* argv[]){
    printf("Usage: %s serialparallel num_tasks\n",argv[0]);
    exit(1); //종료
}

//메인 함수
int main(int argc,char* argv[]){
    //메인에 전달되는 정보의 개수가 3이 아니면
    if(argc!=3){
        print_usage(argc,argv);//print_usage에 메인에 전달되는 argc, argv 정보 전달
    }

    int num_tasks = atoi(argv[2]); //num_task에 argv에 있는 두번쨰 문자열 저장
    //argv의 첫번째 정보가 serial이면
    if(!strcmp(argv[1],"serial")){
        serial(num_tasks);  //serial 함수 실행
    }
    //argv의 첫번째 정보가 parallel이면
    else if(!strcmp(argv[1],"parallel")){
        parallel(num_tasks); //parallel 함수 실행
    }
    else{
        print_usage(argc,argv);//print_usage 함수 실행
    }
    printf("Main completed\n");
    pthread_exit(NULL);//스레드 종료
}