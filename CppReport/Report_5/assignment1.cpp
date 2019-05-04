#include<iostream>
#include<string>
#include<random>
#include<ctime>

using namespace std;

int main() {
	//랜덤 함수 생성
	default_random_engine engine(static_cast<unsigned int>(time(0)));

	//랜덤 ascii 코드 번호 생성하는 randomInt 생성
	uniform_int_distribution<unsigned int>
		randomInt(97, 122);

	//변수 생성
	string a;
	int point;

	//while문 계속 반복
	while (1) {
		cout << "문자열을 입력하세요" << endl;
		getline(cin, a);

		//만약 a에 exit가 입력되면 while문을 벗어남
		if (a == "exit") break;

		//랜덤 문자열의 위치를 생성하는 randomInt2 생성
		uniform_int_distribution<unsigned int>
			randomInt2(0,a.length());

		//랜덤 문자열 위치 
		point = randomInt2(engine);

		//랜덤 문자열 위치에 랜덤 문자열 삽입
		a[point] = (char)randomInt(engine);

		//변환된 문자열 출력
		cout <<"변환된 문자열: "<< a << endl;
	}
	
	system("pause");

}