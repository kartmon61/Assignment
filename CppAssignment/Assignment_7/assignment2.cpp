//
//  main.cpp
//  assignment2
//
//  Created by 이진호 on 26/04/2019.
//  Copyright © 2019 이진호. All rights reserved.
//


#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int makeRandomValue(int num){
    srand((unsigned int)time(NULL));
    
    return rand()%num;
}

int makeRandomValue(int num,bool containsZero){
    
    if(containsZero){
        srand((unsigned int)time(NULL));
        
        return rand()%num;
    }
    else{
        srand((unsigned int)time(NULL));
        
        return rand()%num+1;
    }
    
}

int makeRandomValue(int num1,int num2){
    
    srand((unsigned int)time(NULL));
    
    return rand()%(num2+1-num1)+num1;
}

int main(){
    cout<< makeRandomValue(5) << endl;
    cout << makeRandomValue(3, true) << endl;
    cout << makeRandomValue(4, false) << endl;
    cout << makeRandomValue(1, 4) << endl;
}
