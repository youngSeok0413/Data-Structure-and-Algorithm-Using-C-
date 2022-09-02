#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

template <typename T>
struct Edge
{
	unsigned src;
	unsigned dst;
	T weight;

	// Edge ��ü �񱳴� ����ġ�� �̿�
	inline bool operator< (const Edge<T>& e) const
	{
		return this->weight < e.weight;
	}

	inline bool operator> (const Edge<T>& e) const
	{
		return this->weight > e.weight;
	}
};

template <typename T>
class Graph
{
public:
	// N���� �������� ������ �׷���
	Graph(unsigned N) : V(N) {}

	// �׷����� ���� ���� ��ȯ
	auto vertices() const { return V; }

	// ��ü ���� ����Ʈ ��ȯ
	auto& edges() const { return edge_list; }

	// ���� v���� ������ ��� ������ ��ȯ
	auto edges(unsigned v) const
	{
		vector<Edge<T>> edges_from_v;
		for (auto& e : edge_list)
		{
			if (e.src == v)
				edges_from_v.emplace_back(e);
		}

		return edges_from_v;
	}

	void add_edge(Edge<T>&& e)
	{
		// ���� �� �� ���� ID�� ��ȿ���� �˻�
		if (e.src >= 1 && e.src <= V && e.dst >= 1 && e.dst <= V)
			edge_list.emplace_back(e);
		else
			cerr << "����: ��ȿ ������ ��� ����!" << endl;
	}

	// ǥ�� ��� ��Ʈ�� ����
	template <typename U>
	friend ostream& operator<< (ostream& os, const Graph<U>& G);

private:
	unsigned V;		// ���� ����
	vector<Edge<T>> edge_list;
};

template <typename U>
ostream& operator<< (ostream& os, const Graph<U>& G)
{
	for (unsigned i = 1; i < G.vertices(); i++)
	{
		os << i << ":\t";

		auto edges = G.edges(i);
		for (auto& e : edges)
			os << "{" << e.dst << ": " << e.weight << "}, ";

		os << endl;
	}

	return os;
}

unordered_map<unsigned, string> color_map = {
	{1, "Red"},
	{1, "Blue"},
	{1, "Green"},
	{1, "Yellow"},
	{1, "Black"},
	{1, "White"}
};

template<typename T>
auto greedy_coloring(const Graph<T>& G) {
	auto size = G.vertices();
	vector<unsigned> assigned_colors(size);

	for (unsigned int i = 1; i < size; i++) {
		auto outgoing_edges = G.edges(i);

		set<unsigned> neighbors;

		for (auto& e : outgoing_edges) {
			neighbors.insert(assigned_colors[e.dst]);
		}

		auto smallest = 1;
		for (; smallest <= color_map.size(); smallest++) {
			if (neighbors.find(smallest) == neighbors.end())
				break;
		}

		assigned_colors[i] = smallest;
	}

	return assigned_colors;
}

template<typename T>
void print_colors(vector<T>& colors) {
	for (auto i = 1; i < colors.size(); i++) {
		cout << i << ": " << color_map[colors[i]] << endl;
	}
}

int main() {
	Graph<unsigned> G(9);

	map<unsigned, vector<pair<unsigned, unsigned>>> edge_map;
	edge_map[1] = { {2, 0}, {5, 0} };
	edge_map[2] = { {1, 0}, {5, 0}, {4, 0} };
	edge_map[3] = { {4, 0}, {7, 0} };
	edge_map[4] = { {2, 0}, {3, 0}, {5, 0}, {6, 0}, {8, 0} };
	edge_map[5] = { {1, 0}, {2, 0}, {4, 0}, {8, 0} };
	edge_map[6] = { {4, 0}, {7, 0}, {8, 0} };
	edge_map[7] = { {3, 0}, {6, 0} };
	edge_map[8] = { {4, 0}, {5, 0}, {6, 0} };

	for (auto& i : edge_map)
		for (auto& j : i.second)
			G.add_edge(Edge<unsigned>{ i.first, j.first, j.second });

	cout << "Input" << endl;
	cout << G << endl;

	auto colors = greedy_coloring<unsigned>(G);

	cout << "Coloring" << endl;
	print_colors(colors);

	return 0;
}