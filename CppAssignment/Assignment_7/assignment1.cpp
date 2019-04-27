//
//  main.cpp
//  assignment1
//
//  Created by 이진호 on 23/04/2019.
//  Copyright © 2019 이진호. All rights reserved.
//

#include <iostream>

using namespace std;

void printChar(char a='*',int n=3);

int main(){
    printChar();
    printChar('&',10);

}

void printChar(char a,int n){
    for(int i=0;i<n+1;i++){
        for(int j=0;j<i;j++){
             cout << a;
        }
        cout << endl;
    }
    cout << endl;
}

