//Exercise 10
//median ±¸ÇÏ±â
#include <iostream>
#include <queue>
#include <vector>

struct median {
	std::priority_queue<int> maxHeap; // max -> min
	std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // min -> max

	void insert(int data){
		if (maxHeap.size() == 0) {
			maxHeap.push(data);
			return;
		}

		if (maxHeap.size() == minHeap.size()) {
			if (data <= get())
				maxHeap.push(data);
			else
				minHeap.push(data);
			return;
		}

		if (maxHeap.size() < minHeap.size()) {
			if (data > get()) {
				maxHeap.push(minHeap.top());
				minHeap.pop();
				minHeap.push(data);
			}
			else
				maxHeap.push(data);

			return;
		}

		if (data < get()) {
			minHeap.push(maxHeap.top());
			maxHeap.pop();
			maxHeap.push(data);
		}
		else
			minHeap.push(data);

	}

	double get() {
		if (maxHeap.size() == minHeap.size())
			return (maxHeap.top()+ minHeap.top())/2.0;
		if (maxHeap.size() < minHeap.size())
			return minHeap.top();
		return maxHeap.top();
	}
};

int main() {

	median med;
	int i = 0;

	i = 1;
	med.insert(i);
	std::cout << i << " »ðÀÔ ÈÄ Áß¾Ó°ª: " << med.get() << std::endl;

	i = 5;
	med.insert(i);
	std::cout << i << " »ðÀÔ ÈÄ Áß¾Ó°ª: " << med.get() << std::endl;

	i = 2;
	med.insert(i);
	std::cout << i << " »ðÀÔ ÈÄ Áß¾Ó°ª: " << med.get() << std::endl;

	i = 10;
	med.insert(i);
	std::cout << i << " »ðÀÔ ÈÄ Áß¾Ó°ª: " << med.get() << std::endl;

	i = 40;
	med.insert(i);
	std::cout << i << " »ðÀÔ ÈÄ Áß¾Ó°ª: " << med.get() << std::endl;

	return 0;
}