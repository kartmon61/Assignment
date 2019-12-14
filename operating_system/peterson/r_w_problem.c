//writer
do{
    wait(rwt);
    //writing performed
    signal(rwt);
}while(TRUE);

//reader
do{
    wait(mutex);
    readcount++;
    if(readcount == 1)
        wait(wrt);
    signal(mutex);

    //reading performed

    wait(mutex);
    readcount--;
    if(readcount == 0)
        signal(wrt);
    signal(mutex);
}while(TRUE);