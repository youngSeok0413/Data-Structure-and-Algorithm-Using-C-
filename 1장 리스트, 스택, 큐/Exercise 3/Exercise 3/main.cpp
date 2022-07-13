//�ڵ� ��ó : �ڵ� �׽�Ʈ�� ���� �ڷᱸ���� �˰��� with C++(�� ĳ�� �� 2��, ���)
//Exercise 3 : remove_if()�� �̿��� ���Ǻ� ���� ����

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

	cout << "��ü �ùε�: ";
	for (auto c : citizens)
		cout << c << " ";

	cout << endl;

	citizens.remove_if([](const citizen& c) {
		return (c.age < 19);
		});

	cout << "��ǥ�� �ִ� �ùε�: ";
	for (auto c : citizens)
		cout << c << " ";

	cout << endl;

	citizens = citizens_copy;

	citizens.remove_if([](const citizen& c) {
		return (c.age != 18);
		});

	cout << "��ǥ�� �� ���� �ùε�: ";
	for (auto c : citizens)
		cout << c << " ";
}

