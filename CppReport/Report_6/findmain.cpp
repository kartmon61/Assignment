#include<iostream>

using namespace std;


char& find(char a[], char c, bool& success) {
	int loc=0;
	int i = 0;
	while(a[i]!='\0'){

		if (a[loc] == c) {
			loc = i;
			success = true;
		}
		if (a[i] == '\0') {
			loc = i;
			success = false;
		}
		i++;
	}
		return a[loc-1];
}

int main(){
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);
	if (b == false) {
		cout << "M을 발견할 수 없다." << endl;
		return 0;
	}
	loc = 'm';
	cout << s << endl;
}