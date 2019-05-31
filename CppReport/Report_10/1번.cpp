#include <iostream>
#include <string>

using namespace std;

template <class T>
void mySwap(T &a,T &b,T &c){
    T tmp;

    tmp = a;
    a = c;
    c = tmp;

    tmp = a;
    a = b;
    b = tmp;

}

int main() {

    int i1=1,i2=2,i3=3;
    cout << i1 << " " << i2 << " " << i3 << endl;
    mySwap(i1,i2,i3);
    cout << i1 << " " << i2 << " " << i3 << endl;
    double d1=1.0,d2=2.0,d3=3.0;
    cout << d1 << " " << d2 << " " << d3 << endl;
    mySwap(d1,d2,d3);
    cout << d1 << " " << d2 << " " << d3 << endl;
    string s1="s1",s2="s2",s3="s3";
    cout << s1 << " " << s2 << " " << s3 << endl;
    mySwap(s1,s2,s3);
    cout << s1 << " " << s2 << " " << s3 << endl;
    char c1='a',c2='b',c3='c';
    cout << c1 << " " << c2 << " " << c3 << endl;
    mySwap(c1,c2,c3);
    cout << c1 << " " << c2 << " " << c3 << endl;




}
