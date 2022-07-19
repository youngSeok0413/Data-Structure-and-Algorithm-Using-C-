//Exercise 9(BST : childeren<=2/ L <= P <= R)
#include <iostream>

struct node {
	int data;
	node* left;
	node* rigth;
};

struct bst {
	node* root = nullptr;

	node* find(int value) {
		return find_impl(root, value);
	}

	void insert(int value) {
		if (!root)
			root = new node{ value, NULL, NULL };
		else
			insert_impl(root, value);
	}

	void inorder() {
		inorder_impl(root);
	}

	node* successor(node* start) {
		auto current = start->rigth;

		while (current && current->left)
			current = current->left;
		return current;
	}

	void deleteValue(int value) {
		root = delete_impl(root, value);
	}

private:
	node* find_impl(node* current, int value) {
		if (!current) {
			std::cout << std::endl;
			return NULL;
		}

		if (current->data == value) {
			std::cout << value << "를 찾았습니다." << std::endl;
			return current;
		}
		else if (current->data > value) {
			std::cout << "오른쪽으로 이동" << std::endl;
			return find_impl(current->rigth, value);
		}
		else{
			std::cout << "왼쪽으로 이동" << std::endl;
			return find_impl(current->left, value);
		}
	}

	void insert_impl(node* current, int value) {
		if (value < current->data)
		{
			if (!current->left)
				current->left = new node{ value, NULL, NULL };
			else
				insert_impl(current->left, value);
		}
		else {
			if (!current->rigth)
				current->rigth = new node{ value, NULL, NULL };
			else
				insert_impl(current->rigth, value);
		}
	}

	void inorder_impl(node* current) {
		if (!current)
			return;

		inorder_impl(current->left);
		std::cout << current->data << " ";
		inorder_impl(current->rigth);
	}

	node* delete_impl(node* start, int value) {
		if (!start)
			return NULL;

		if (value < start->data)
			start->left = delete_impl(start->left, value);
		else if (value > start->data)
			start->rigth = delete_impl(start->rigth, value);
		else {
			if (!start->left) {
				auto tmp = start->rigth;
				delete start;
				return tmp;
			}

			if (!start->rigth) {
				auto tmp = start->left;
				delete start;
				return tmp;
			}

			auto succNode = successor(start);
			start->data = succNode->data;

			start->rigth = delete_impl(start->rigth, succNode->data);
		}

		return start;
	}
};

int main() {
	bst tree;
	tree.insert(12);
	tree.insert(10);
	tree.insert(20);
	tree.insert(8);
	tree.insert(11);
	tree.insert(15);
	tree.insert(28);
	tree.insert(4);
	tree.insert(2);

	std::cout << "중위 순회 : ";
	tree.inorder();
	std::cout << std::endl;

	tree.deleteValue(12);
	std::cout << "12를 삭제한 후 중위 순회: ";
	tree.inorder();
	std::cout << std::endl;

	if (tree.find(12))
		std::cout << "원소 12는 트리에 있습니다." << std::endl;
	else
		std::cout << "원소 12는 트리에 없습니다." << std::endl;

	return 0;
}