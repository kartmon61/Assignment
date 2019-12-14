do{
    waiting[i] = true;
    key= true;
    while(waiting[i] && key)
        key = TestAndSet(&lock);
    waiting[i] = FALSE;
    //critical
    j = (i+1) % n; //i번째 다음을 j로 선언
    while((j != i) && !waiting[j]) 
    //한바퀴 다돌기전까지, waiting이 발견될떄 까지
        j = (j+1) % n; //순차 탐색
    if(j==i) //자원 사용 없음
        lock=false; //lock 해제
    else //자원 사용 발견
        waiting[j] = false; //-> 4번 라인 벗어남
    
}