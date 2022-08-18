#include <iostream>
#include <vector>

template<typename T>
std::vector<T> merge(std::vector<T>& arr1, std::vector<T>& arr2) {
	std::vector<T> merged;

	auto iter1 = arr1.begin();
	auto iter2 = arr2.begin();

	while (iter1 != arr1.end() && iter2 != arr2.end()) {
		if (*iter1 < *iter2) {
			merged.emplace_back(*iter1);
			iter1++;
		}
		else {
			merged.emplace_back(*iter2);
			iter2++;
		}
	}

	if (iter1 != arr1.end()) {
		for (; iter1 != arr1.end(); iter1++)
			merged.emplace_back(*iter1);
	}
	else {
		for (; iter2 != arr2.end(); iter2++)
			merged.emplace_back(*iter2);
	}

	return merged;
}

template<typename T>
std::vector<T> merge_sort(std::vector<T> arr) {
	if (arr.size() > 1) {
		auto mid = size_t(arr.size()/2);
		auto left_half = merge_sort(std::vector<T>(arr.begin(), arr.begin()+mid));
		auto right_half = merge_sort(std::vector<T>(arr.begin() + mid, arr.end()));

		return merge<T>(left_half, right_half);
	}

	return arr;
}

template<typename T>
void print_vector(std::vector<T> arr) {
	for (auto i : arr)
		std::cout << i << " ";
	std::cout << std::endl;
}

void run_merge_sort_test() {
	std::vector<int> S1{ 45, 1, 3, 1, 2, 3, 45, 5, 1, 2, 44, 5, 7};
	std::vector<float> S2{45.6f, 1.0f, 3.8f, 1.0f, 2.2f, 3.9f, 43.3f, 5.5f};
	std::vector<double> S3{45.6, 1.0, 3.8, 1.01, 2.2, 3.9, 45.3, 5.5, 1.0, 2.0, 44.0, 5.0, 7.0};
	std::vector<char> S4{'b', 'z', 'a', 'e', 'f', 't', 'q', 'u', 'y'};

	std::cout << "���ĵ��� ���� : " << std::endl;
	print_vector(S1);
	print_vector(S2);
	print_vector(S3);
	print_vector(S4);

	std::vector<int> sorted_s1 = merge_sort<int>(S1);
	std::vector<float> sorted_s2 = merge_sort<float>(S2);
	std::vector<double> sorted_s3 = merge_sort<double>(S3);
	std::vector<char> sorted_s4 = merge_sort<char>(S4);

	std::cout << "���ĵ� : " << std::endl;
	print_vector(sorted_s1);
	print_vector(sorted_s2);
	print_vector(sorted_s3);
	print_vector(sorted_s4);
}

int main() {
	run_merge_sort_test();
	return 0;
}