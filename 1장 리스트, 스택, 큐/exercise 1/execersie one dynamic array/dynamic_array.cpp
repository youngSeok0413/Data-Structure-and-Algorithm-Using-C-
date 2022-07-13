//�ڵ� ��ó : �ڵ��׽�Ʈ�� ���� �ڷ� ������ �˰��� with C++ ( �� ĳ��, �θ��� ����, �Ǿ߽� ���� ����, ��� ���ǻ�)
//���� 1 : ���� �迭 ����

#include <iostream>
#include <sstream>
#include <algorithm>

template <typename T>
class dynamic_array {

	T* data;
	size_t n;

public:
	// ���� ���� ũ�⸸ �ִ� ������
	dynamic_array(int n) {
		this->n = n;
		data = new T[n];
	}

	// �ܺο��� �ٸ� �����ڸ� �����ϴ� ����� ������
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

	//at() : data[] over boundary ó�� ����� ����(�⺻���� ����� operator []�� ����)
	T& at(int index) {
		if (n < index)
			return data[index];
		throw "Index out of bound";
	}

	//dynamic array�� ù �ּ� ��ȯ
	T* begin() { return data; }
	const T* begin() const { return data; }

	//dynamic array�� ������ �ּ� ��ȯ
	T* end() { return data + n; }
	const T* end() const { return data + n; }

	//size ��ȯ
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

//�ؿ� ���ʹ� ���̳��� ��� ��� ����
struct student{
	std::string name;
	int standard;
};

std::ostream& operator<<(std::ostream& os, const student& s) {
	return (os << "[" << s.name << ", " << s.standard << "]");
}

int main() {
	int nStudents;
	std::cout << "1�� �л� ���� �Է��ϼ���: ";
	std::cin >> nStudents;

	dynamic_array<student> class1(nStudents);
	for (int i = 0; i < nStudents; i++) {
		std::string name;
		int standard;
		std::cout << i + 1 << "��° �л� �̸��� ���̸� �Է��ϼ���: ";
		std::cin >> name >> standard;
		class1[i] = student{name, standard};
	}

	//try {
	//	//class1[nStudents] = student{"John, 8"};
	//	class1.at(nStudents) = student{"John, 8"};
	//}
	//catch (...) {
	//	std::cout << "���� �߻�" << std::endl;
	//}

	auto class2 = class1;
	std::cout << "1���� �����Ͽ� 2�� ����: " << class2.to_string() << std::endl;

	auto class3 = class1 + class2;
	std::cout << "1�ݰ� 2���� ���Ͽ� 3�� ����: " << class3.to_string() << std::endl;

	return 0;
}