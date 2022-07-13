//코드 출처 : 코딩테스트를 위한 자료 구조와 알고리즘 with C++ ( 존 캐리, 셰리안 도시, 피야스 라잔 지음, 길벗 출판사)
//문제 1 : 동적 배열 구현

#include <iostream>
#include <sstream>
#include <algorithm>

template <typename T>
class dynamic_array {

	T* data;
	size_t n;

public:
	// 내용 없고 크기만 있는 생성자
	dynamic_array(int n) {
		this->n = n;
		data = new T[n];
	}

	// 외부에서 다른 생성자를 복사하는 방식의 생성자
	dynamic_array(const dynamic_array<T>& other) {
		n = other.n;
		data = new T[n];

		for (int i = 0; i < n; i++)
			data[i] = other.data[i];
	}

	//[] operator
	T& operator[](int index) {
		return data[index];
	}
	const T& operator[](int index) const {
		return data[index];
	}

	//at() : data[] over boundary 처리 기능을 포함(기본적인 기능은 operator []와 같음)
	T& at(int index) {
		if (n < index)
			return data[index];
		throw "Index out of bound";
	}

	//dynamic array의 첫 주소 반환
	T* begin() { return data; }
	const T* begin() const { return data; }

	//dynamic array의 마지막 주소 반환
	T* end() { return data + n; }
	const T* end() const { return data + n; }

	//size 반환
	size_t size() const {
		return n;
	}

	//destructor
	~dynamic_array() {
		delete[] data;
	}

	//operator +
	friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, const dynamic_array<T>& arr2) {
		dynamic_array<T> result(arr1.size() + arr1.size());

		std::copy(arr1.begin(), arr1.end(), result.begin());
		std::copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());

		return result;
	}

	//array to string
	std::string to_string(const std::string& sep = ", ") {
		if (n == 0)
			return "";

		std::ostringstream os;
		os << data[0];

		for (int i = 0; i < n; i++)
			os << sep << data[i];

		return os.str();
	}

};

//밑에 부터는 다이나믹 어레이 사용 예시
struct student{
	std::string name;
	int standard;
};

std::ostream& operator<<(std::ostream& os, const student& s) {
	return (os << "[" << s.name << ", " << s.standard << "]");
}

int main() {
	int nStudents;
	std::cout << "1반 학생 수를 입력하세요: ";
	std::cin >> nStudents;

	dynamic_array<student> class1(nStudents);
	for (int i = 0; i < nStudents; i++) {
		std::string name;
		int standard;
		std::cout << i + 1 << "번째 학생 이름과 나이를 입력하세요: ";
		std::cin >> name >> standard;
		class1[i] = student{name, standard};
	}

	//try {
	//	//class1[nStudents] = student{"John, 8"};
	//	class1.at(nStudents) = student{"John, 8"};
	//}
	//catch (...) {
	//	std::cout << "예외 발생" << std::endl;
	//}

	auto class2 = class1;
	std::cout << "1반을 복사하여 2반 생성: " << class2.to_string() << std::endl;

	auto class3 = class1 + class2;
	std::cout << "1반과 2반을 합하여 3반 생성: " << class3.to_string() << std::endl;

	return 0;
}