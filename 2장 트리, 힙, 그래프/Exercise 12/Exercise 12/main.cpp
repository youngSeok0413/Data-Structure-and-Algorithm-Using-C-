//Exercise 12
//using list make more efficient(array uses lots of data)
#include <iostream>
#include <vector>
#include <algorithm>

enum class city : int {
	MOSCOW,
	LONDON,
	SEOUL,
	SEATLE,
	DUBAI,
	SYDNEY
};

std::ostream& operator<<(std::ostream& os, const city c) {
	switch (c)
	{
	case city::MOSCOW:
		os << "����";
		return os;
	case city::LONDON:
		os << "����";
		return os;
	case city::SEOUL:
		os << "����";
		return os;
	case city::SEATLE:
		os << "�þ�Ʋ";
		return os;
	case city::DUBAI:
		os << "�ι���";
		return os;
	case city::SYDNEY:
		os << "�õ��";
		return os;
	}
}

struct graph {
	std::vector<std::vector<std::pair<int, int>>> data;

	graph(int n) {
		data = std::vector<std::vector<std::pair<int, int>>>(n, std::vector<std::pair<int, int>>());
	}

	void addEdge(const city c1, const city c2, int dis) {
		std::cout << "���� �߰�:" << c1 << "-" << c2 << "=" << dis << std::endl;

		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		data[n1].push_back({n2, dis});
		data[n2].push_back({ n1, dis });
	}

	void removeEdge(const city c1, const city c2) {
		std::cout << "���� ����:" << c1 << "-" << c2 << std::endl;
		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		std::remove_if(data[n1].begin(), data[n1].end(), [n2](const auto& pair){
			return pair.first == n2;
		});
		std::remove_if(data[n1].begin(), data[n1].end(), [n1](const auto& pair){
			return pair.first == n1;
		});
	}
};

int main() {
	graph g(6);

	g.addEdge(city::LONDON, city::MOSCOW, 2500);
	g.addEdge(city::LONDON, city::SEOUL, 9000);
	g.addEdge(city::LONDON, city::DUBAI, 5500);
	g.addEdge(city::SEOUL, city::MOSCOW, 6600);
	g.addEdge(city::SEOUL, city::SEATLE, 8000);
	g.addEdge(city::SEOUL, city::DUBAI, 7000);
	g.addEdge(city::SEOUL, city::SYDNEY, 8000);
	g.addEdge(city::SEATLE, city::MOSCOW, 8400);
	g.addEdge(city::SEATLE, city::SYDNEY, 1200);
	g.addEdge(city::DUBAI, city::SYDNEY, 1200);

	g.addEdge(city::SEATLE, city::LONDON, 8000);
	g.removeEdge(city::SEATLE, city::LONDON);

	return 0;
}