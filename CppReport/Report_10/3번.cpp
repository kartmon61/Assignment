#include <iostream>
#include <map>
using namespace std;

map<string,string> make;

void print(int a){
    string s1 , s2;
    switch(a){
        case 1:
            cout << "이름 암호>>";
            cin >> s1 >> s2;
            make.insert(make_pair(s1,s2));
            break;

        case 2:
            cout<< "이름?";
            cin >> s1;
            cout << "암호?";
            cin >> s2;
            if(make[s1]==s2) cout << "통과!"<<endl;
            else cout << "실패!" << endl;
            break;

    }
}

int main() {
    int input;

    cout << "삽입:1, 검사:2, 종료:3 >>";
    cin >> input;
    while(input!=3){
        print(input);
        cout << "삽입:1, 검사:2, 종료:3 >>";
        cin >> input;

    }
    cout << "프로그램을 종료합니다..." << endl;

}