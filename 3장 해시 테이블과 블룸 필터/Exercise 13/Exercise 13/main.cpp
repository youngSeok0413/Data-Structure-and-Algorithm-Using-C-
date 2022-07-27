//Exercise 13

#include <iostream>
#include <vector>

using uint = unsigned int;

class hash_map {
private:
	std::vector<int> data;

public:
	hash_map(size_t n) {
		data = std::vector<int>(n, -1);
	}

	void insert(uint value) {
		int n = data.size();
		data[value % n] = value;
		std::cout << value << "��(��) �����߽��ϴ�." << std::endl;
	}

	bool find(uint value) {
		int n = data.size();
		return (value == data[value%n]);
	}

	void erase(uint value) {
		int n = data.size();
		if (data[value % n] == value) {
			data[value % n] = -1;
			std::cout << value << "��(��) �����߽��ϴ�." << std::endl;
		}
	}
};

int main(){
	hash_map map(7);

	auto print = [&](int value) {
		if (map.find(value))
			std::cout << "�ؽ� �ʿ��� " << value << "��(��) ã�ҽ��ϴ�." << std::endl;
		else
			std::cout << "�ؽ� �ʿ��� " << value << "��(��) ��ã�ҽ��ϴ�." << std::endl;
	};

	map.insert(2);
	map.insert(25);
	map.insert(10);
	print(25);

	map.insert(100);
	print(100);
	print(2);

	map.erase(25);
	return 0;
}