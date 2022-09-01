//Exercise 24 : 최단 작업 우선 스케줄링
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

template<typename T>
auto compute_waiting_times(std::vector<T>& service_times) {
	std::vector<T> W(service_times.size());
	W[0] = 0;

	for (auto i = 1; i < service_times.size(); i++)
		W[i] = W[i - 1] + service_times[i - 1];

	return W;
}

template<typename T>
void print_vector(std::vector<T>& V){
	for (auto i : V)
		std::cout << i << " ";
	std::cout << std::endl;
}

template<typename T>
void pcompute_and_print_waiting_times(std::vector<T>& service_times) {
	auto waiting_times = compute_waiting_times(service_times);

	std::cout << "- 처리시간 : ";
	print_vector(service_times);

	std::cout << "- 대기시간 : ";
	print_vector(waiting_times);

	auto ave_waiting_times = std::accumulate(waiting_times.begin(), waiting_times.end(), 0.0) / waiting_times.size();
	std::cout << "- 평균대기시간: " << ave_waiting_times;

	std::cout << std::endl;
}

int main() {
	std::vector<int> service_times{8, 1, 2, 4, 9, 2, 3, 5};

	std::cout << "Before Being Sorted" << std::endl;
	pcompute_and_print_waiting_times(service_times);

	std::sort(service_times.begin(), service_times.end());

	std::cout << std::endl;

	std::cout << "After Being Sorted" << std::endl;
	pcompute_and_print_waiting_times(service_times);

	return 0;
}