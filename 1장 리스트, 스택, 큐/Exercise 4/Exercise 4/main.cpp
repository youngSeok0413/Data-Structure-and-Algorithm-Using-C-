//출처 : 코딩테스트를 위한 자료 구조와 알고리즘 with C++( 존 캐리 외 2인, 길벗)
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
	cout << "가장 최근 우승자: " << *it << endl;

	it += 8;
	cout << "8년차 우승자: " << *it << endl;

	advance(it, -3);

	cout << "그 후 3년 후 우승자: " << *it << endl;

	forward_list<string> fwd(vec.begin(), vec.end());

	auto it1 = fwd.begin();
	cout << "가장 최근 우승자: " << *it1 << endl;

	advance(it1, 5);
	cout << "5년차 우승자: " << *it1 << endl;

	/*advance(it, -2);

	cout << "그 후 3년 후 우승자: " << *it << endl;*/

	return 0;
}