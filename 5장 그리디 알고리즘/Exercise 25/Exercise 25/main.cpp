//Exercise 25 : 분할 가능 배낭문제
#include <iostream>
#include <algorithm>
#include <vector>

struct Object
{
	int id;
	int weight;
	double value;
	double value_per_unit_weight;

	Object(int i, int w, double v) : id(i), weight(w), value(v),
		value_per_unit_weight(v / w) {};

	inline bool operator< (const Object& obj) const {
		return this->value_per_unit_weight < obj.value_per_unit_weight;
	}

	friend std::ostream& operator<<(std::ostream& os, const Object& obj);
};

std::ostream& operator<<(std::ostream& os, const Object& obj) {
	os << "[" << obj.id << "] 가격: " << obj.value
		<< "\t무게: " << obj.weight
		<< "kg\t단위 무게 당 가격: " << obj.value_per_unit_weight;
	return os;
}

auto fill_knapsack(std::vector<Object>& object, int knasack_capcity){
	std::vector<Object> knapsack_contents;
	knapsack_contents.reserve(object.size());

	std::sort(object.begin(), object.end());
	std::reverse(object.begin(), object.end());

	auto current_object = object.begin();
	int current_total_weight = 0;
	for (; current_total_weight < knasack_capcity && current_object != object.end(); current_object++) {
		knapsack_contents.push_back(*current_object);
		
		current_total_weight += current_object->weight;
	}

	int weight_of_last_obj_to_remove = current_total_weight-knasack_capcity;
	Object& last_object = knapsack_contents.back();
	if (weight_of_last_obj_to_remove < 0) {
		last_object.weight -= weight_of_last_obj_to_remove;
		last_object.value -= weight_of_last_obj_to_remove*last_object.value_per_unit_weight;
	}

	return knapsack_contents;
}


int main() {

	std::vector<Object> objects;
	objects.reserve(7);

	std::vector<int> weights{ 1,2 , 5, 9, 2, 3, 4 };
	std::vector<double> value{10, 7, 15, 10,12, 11, 5};

	for (auto i = 0; i < 7; i++)
		objects.push_back(Object(i+1, weights[i], value[i]));

	std::cout << "Able to use" << std::endl;
	for (auto& o : objects)
		std::cout << o << std::endl;
	std::cout << std::endl;

	int knapsack_capcity = 7;
	auto solution = fill_knapsack(objects, knapsack_capcity);

	std::cout << "Things that i put in( capcity : " << knapsack_capcity << ")" << std::endl;

	for (auto& o : solution)
		std::cout << o << std::endl;
	std::cout << std::endl;

	return 0;
}