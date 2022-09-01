//Exercise 26 : Kruskal MST Algorithm
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

class SimpleDisjointSet {
private:
	struct Node
	{
		unsigned int id;
		unsigned int rank;
		unsigned int parent;

		Node(unsigned int  _id) : id(_id), rank(0), parent(_id) {}

		bool operator !=(const Node& n) const {
			return this->id != n.id;
		}
	};

	vector<Node> nodes;

public:
	SimpleDisjointSet(unsigned int N) {
		nodes.reserve(N);
	}

	void make_set(const unsigned int& x) {
		nodes.emplace_back(x);
	}

	unsigned find(unsigned int x) {
		auto node_it = find_if(nodes.begin(), nodes.end(), 
			[x](auto n) {return n.id == x; });
		unsigned int node_id = (*node_it).id;

		while (node_id != nodes[node_id].parent) {
			node_id = nodes[node_id].parent;
		}

		return node_id;
	}

	void union_sets(unsigned int x, unsigned int y) {
		auto root_x = find(x);
		auto root_y = find(y);

		if (root_x == root_y)
			return;

		if (nodes[root_x].rank > nodes[root_y].rank)
			swap(root_x, root_y);

		nodes[root_x].parent = nodes[root_y].parent;
		nodes[root_y].rank++;
	}
};

int main() {
	cout << sizeof(unsigned int) << endl;
	return 0;
}