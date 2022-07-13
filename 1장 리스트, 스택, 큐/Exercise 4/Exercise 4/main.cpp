//��ó : �ڵ��׽�Ʈ�� ���� �ڷ� ������ �˰��� with C++( �� ĳ�� �� 2��, ���)
//Exercise 4

#include <iostream>
#include <forward_list>
#include <vector>

using namespace std;

int main() {

	vector<string> vec = {
		"Lewis Hamilton",
		"Lewis Hamilton",
		"Nico Roseberg",
		"Sebastian Vettel",
		"Lewis Hamilton",
		"Sebastian Vettel",
		"Sebastian Vettel",
		"Sebastian Vettel",
		"Fernado Alonso"
	};

	auto it = vec.begin();
	cout << "���� �ֱ� �����: " << *it << endl;

	it += 8;
	cout << "8���� �����: " << *it << endl;

	advance(it, -3);

	cout << "�� �� 3�� �� �����: " << *it << endl;

	forward_list<string> fwd(vec.begin(), vec.end());

	auto it1 = fwd.begin();
	cout << "���� �ֱ� �����: " << *it1 << endl;

	advance(it1, 5);
	cout << "5���� �����: " << *it1 << endl;

	/*advance(it, -2);

	cout << "�� �� 3�� �� �����: " << *it << endl;*/

	return 0;
}