#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> a;

    int input;
    int sum=0;
    cout << "입력(0은 종료): ";
    cin >> input;


    while(input != 0){
        a.push_back(input);
        cout << "입력(0은 종료): ";
        cin >> input;
    }

    for(int i=0;i<a.size();i++){
        cout << a[i] << " ";
        sum += a[i];
    }
    cout << endl;

    double pyun = (double)sum/(a.size());

    cout << "평균: " << pyun << endl;



}