//Exercise 11
//그래프를 구성하고 인접 행렬로 표현하기
#include <iostream>
#include <vector>

enum class city : int {
	MOSCOW,
	LONDON,
	SEOUL,
	SEATLE,
	DUBAI,
	SYDNEY
};

std::ostream& operator<<(std::ostream & os, const city c) {
	switch (c)
	{
	case city::MOSCOW:
		os << "모스코";
		return os;
	case city::LONDON:
		os << "런던";
		return os;
	case city::SEOUL:
		os << "서울";
		return os;
	case city::SEATLE:
		os << "시애틀";
		return os;
	case city::DUBAI:
		os << "두바이";
		return os;
	case city::SYDNEY:
		os << "시드니";
		return os;
	}
}

struct graph {
	std::vector<std::vector<int>> data; // n by n matrix

	graph(int n) {
		data.reserve(n); // non flexible
		std::vector<int> row(n);
		std::fill(row.begin(), row.end(), -1);

		for (int i = 0; i < n; i++)
			data.push_back(row);
	}

	void addEdge(const city c1, const city c2, int dis) {
		std::cout << "에지 추가:" << c1 << "-" << c2 << "=" << dis << std::endl;

		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		data[n1][n2] = dis;
		data[n2][n1] = dis;
	}

	void removeEdge(const city c1, const city c2) {
		std::cout << "에지 삭제:" << c1 << "-" << c2 << std::endl;
		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		data[n1][n2] = -1;
		data[n2][n1] = -1;
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