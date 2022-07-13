//코드 출처 : 코딩 테스트를 위한 자료구조와 알고리즘 with C++(존 캐리 외 2인, 길벗)
//Exercise 3 : remove_if()를 이용한 조건부 원소 삭제

#include <string>
#include <iostream>
#include <forward_list>

using namespace std;

struct citizen {
	string name;
	int age;
};

ostream& operator<<(ostream& os, const citizen& c) {
	return (os << "[" << c.name << ", " << c.age << "]");
}

int main() {
	forward_list<citizen> citizens = {
		{"Kim", 22},
		{"Lee", 25},
		{"Park", 18},
		{"Jin", 16}
	};

	auto citizens_copy = citizens;

	cout << "전체 시민들: ";
	for (auto c : citizens)
		cout << c << " ";

	cout << endl;

	citizens.remove_if([](const citizen& c) {
		return (c.age < 19);
		});

	cout << "투표권 있는 시민들: ";
	for (auto c : citizens)
		cout << c << " ";

	cout << endl;

	citizens = citizens_copy;

	citizens.remove_if([](const citizen& c) {
		return (c.age != 18);
		});

	cout << "투표권 곧 생길 시민들: ";
	for (auto c : citizens)
		cout << c << " ";
}

