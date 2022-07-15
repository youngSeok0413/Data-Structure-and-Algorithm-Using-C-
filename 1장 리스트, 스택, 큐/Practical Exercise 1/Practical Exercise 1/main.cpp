/*
* What you need to make is playlist for music
* Here is ther requirements that you need to keep
* 
* playlist should be circular linked(both able to move back and forth) 
* able to add several musics
* add, remove function must be added
* additionally, iterator must be provied
*/

#include <iostream>
#include <string>

struct Playlist_Node{
	std::string musics;
	Playlist_Node* prev;
	Playlist_Node* next;
};

class PlayList {
private:
	using node = Playlist_Node;
	using node_ptr = Playlist_Node*;
private:
	node head; // head and tail were set as kind of null node due to convineance
	node tail;

public:
	PlayList() {
		this->head = node{ "", &tail, &tail };
		this->tail = node{ "", &head, &head };
	}

	PlayList(PlayList& other) {
		playlist_iterator iter = other.begin();
		if (++iter == other.end()) {
			PlayList();
		}
		else {
			PlayList();
			for (++iter; iter != other.end(); iter++)
				this->push_back(*iter);
		}
	}

	void check() {
		std::cout << "[ ";

		node_ptr ptr = &(this->head);
		ptr = head.next;

		while (ptr != &(this->tail)) {
			std::cout << ptr->musics << ", ";
			ptr = ptr->next;
		}

		std::cout << "]" << std::endl;
	}

	void push_back(const std::string& music) {
		if (head.next == &tail) {
			node_ptr toPush = new node{ music, &head, &tail };
			head.next = toPush;
			tail.prev = toPush;
		}
		else {
			node_ptr toPush = new node{ music, tail.prev, &tail };
			tail.prev->next = toPush;
			tail.prev = toPush;
		}

		check();
	}

	void push_front(const std::string& music) {
		if (head.next == &tail) {
			node_ptr toPush = new node{ music, &head, &tail };
			head.next = toPush;
			tail.prev = toPush;
		}
		else {
			node_ptr toPush = new node{ music, &head, head.next };
			head.next->prev = toPush;
			head.next = toPush;
		}

		check();
	}

	void pop_back() {
		if (head.next == &tail) {
			std::cout << "Nothing to pop" << std::endl;
		}
		else {
			node_ptr toPop = tail.prev;
			tail.prev = tail.prev->prev;
			tail.prev->next = &tail;
			delete toPop;
		}

		check();
	}

	void pop_front() {
		if (head.next == &tail) {
			std::cout << "Nothing to pop" << std::endl;
		}
		else {
			node_ptr toPop = head.next;
			head.next = head.next->next;
			head.next->prev = &head;
		}

		check();
	}

	struct playlist_iterator {
	private:
		node_ptr pointer;
	public:
		playlist_iterator();

		playlist_iterator(node_ptr ptr) {
			pointer = ptr;
		}

		node_ptr get() {
			return pointer;
		}

		std::string& operator*() {
			return pointer->musics;
		}

		playlist_iterator& operator++() {
			pointer = pointer->next;
			return *this;
		}

		playlist_iterator operator++(int) {
			auto result = *this;
			pointer = pointer->next;
			return result;
		}

		playlist_iterator& operator--() {
			pointer = pointer->prev;
			return *this;
		}

		playlist_iterator operator--(int) {
			auto result = *this;
			pointer = pointer->prev;
			return result;
		}

		friend bool operator==(const playlist_iterator& right, const playlist_iterator& left) {
			return right.pointer == left.pointer;
		}

		friend bool operator != (const playlist_iterator& right, const playlist_iterator& left) {
			return right.pointer != left.pointer;
		}
	};

	playlist_iterator begin() {
		return playlist_iterator(&head);
	}

	playlist_iterator end() {
		return playlist_iterator(&tail);
	}

	playlist_iterator find(std::string music) {
		for (playlist_iterator iter = this->begin(); iter != this->end(); iter++) {
			if (iter.get()->musics == music) {
				return iter;
			}
		}
		return NULL;
	}

	void insert(unsigned int n, std::string music) {
		if (n > this->size()) {
			std::cout << "Error : Out of boundary" << std::endl;
		}
		else {
			playlist_iterator iter = this->begin();

			for (int i = -1; i < n; i++)
				iter++;

			this->insert(iter, music);
		}
	}

	void insert(playlist_iterator iter, std::string music) {
		if (iter == this->begin()) {
			node_ptr toAdd = new node{ music, iter.get(), iter.get()->next};
			iter.get()->next = toAdd;
			iter.get()->next->prev = toAdd;
		}
		else {
			node_ptr toAdd = new node{ music, iter.get()->prev, iter.get() };
			iter.get()->prev->next = toAdd;
			iter.get()->prev = toAdd;
		}

		check();
	}

	void remove(unsigned int n) {
		playlist_iterator iter = this->begin()++;

		if (n+1 > this->size())
			std::cout << "Error : Out of boundary" << std::endl;
		else {
			for (int i = 0; i < n+1; i++) iter++;
			node_ptr toRemove = iter.get();
			toRemove->next->prev = toRemove->prev;
			toRemove->prev->next = toRemove->next;
			delete toRemove;
		}

		check();
	}

	void remove(playlist_iterator iter) {
		if (iter == this->begin())
			this->remove(++iter);
		else if (iter == this->end())
			this->remove(--iter);
		else {
			node_ptr toRemove = iter.get();
			toRemove->next->prev = toRemove->prev;
			toRemove->prev->next = toRemove->next;
			delete toRemove;
		}

		check();
	}

	size_t size() {

		int sz = 0;

		for (playlist_iterator iter = this->begin(); iter != this->end(); iter++)
			sz++;

		return sz - 1;
	}
};

int main() {
	PlayList list;

	PlayList::playlist_iterator iter = list.begin();
	iter++;

	list.pop_front();
	list.push_back("Bohemian Rhapsody");
	list.push_back("Killer Queen");
	list.push_back("Don't Stop Me Now");
	list.insert(1, "Judy1");
	return 0;
}