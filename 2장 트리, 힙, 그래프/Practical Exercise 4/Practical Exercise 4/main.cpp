//Practical Exercise 4
//Making file system using N-tree
//dir, file move, search, add, delete function needed

//완료된 것 : add ,delete, location change, printAll

#include <string>
#include <vector>

#include <iostream>

enum TYPE : bool{
	DIR = true,
	FL = false
};

struct Node {
	TYPE type;
	std::string name;
	Node* prev;
	std::vector<Node*> next;
};

class nTree {
private:
	using node = Node;
	using node_adr = Node*;

private:
	node_adr root;
	node_adr location;
public:

	nTree() {
		root = new node{TYPE::DIR, "root", nullptr, std::vector<node_adr>()};
		location = root;
	}

	//print every dir and file
	void PrintAll() {
		Impl_PrintAll(root);
	}

	//add file
	void AddFile(const std::string& file) {
		if (!location->type) {
			std::cout << "Error" << std::endl;
			return;
		}
		node_adr toAdd = new node{TYPE::FL, file, location, std::vector<node_adr>() };
		location->next.push_back(toAdd);
	}

	//add dir
	void AddDir(const std::string& dir) {
		if (!location->type) {
			std::cout << "Error" << std::endl;
			return;
		}
		node_adr toAdd = new node{ TYPE::DIR, dir, location, std::vector<node_adr>() };
		location->next.push_back(toAdd);
	}

	//delete file
	void DeleteFile(const std::string& input) {
		if (!location->type) {
			std::cout << "Error : Location Error : Location type should be dir" << std::endl;
			return;
		}

		if (location->next.empty()) {
			std::cout << "Error : Dir Empty" << std::endl;
			return;
		}

		for (int i = 0; i < location->next.size(); i++) {
			if (location->next[i]->name == input) {
				if (!(location->next[i]->type)) {
					node_adr toErase = location->next[i];
					location->next.erase(location->next.begin() + i);
					delete toErase;
					return;
				}
			}
		}

		std::cout << "There is no file to erase" << std::endl;
		return;
	}

	//delete dir
	void DeleteDir(const std::string& input) {
		if (!location->type) {
			std::cout << "Error : Location Error : Location type should be DIR" << std::endl;
			return;
		}

		if (location->next.empty()) {
			std::cout << "Error : Dir Empty" << std::endl;
			return;
		}

		for (int i = 0; i < location->next.size(); i++) {
			if (location->next[i]->name == input) {
				if (location->next[i]->type) {
					Impl_ClearDir(location->next[i]);
					location->next.erase(location->next.begin() + i);
					return;
				}
			}
		}

		std::cout << "There is no Dir to erase" << std::endl;
		return;
	}

	//이동 관련 함수들
	//초기화
	void GoToRoot() {
		Impl_GoToRoot();
	}

	//전 dir로
	void GoToPrevDir() {
		Impl_GoToPrev();
	}

	//dir에 있는 dir 혹은 파일로
	void GoToNext(TYPE type, const std::string& name) {
		Impl_GoToNext(type, name);
	}

private:
	//print all function(implicit)
	void Impl_PrintAll(node_adr here) {
		if (!here){
			std::cout << "Empty" << std::endl;
			return;
		}

		if (here->next.empty()) {
			std::cout << ((here->type == DIR) ? "DIR" : "FILE") << " " 
				<< here->name << std::endl;
		}
		else {
			for (int i = 0; i < here->next.size(); i++)
				Impl_PrintAll(here->next[i]);

			std::cout << ((here->type == DIR) ? "DIR" : "FILE") << " "
				<< here->name << std::endl;
		}
	}

	//clear all dir(implicit)
	void Impl_ClearDir(node_adr here) {
		if (here->next.empty()) {
			node_adr toErase = here;
			delete here;
		}
		else {
			for (int i = 0; i < here->next.size(); i++)
				Impl_ClearDir(here->next[i]);

			node_adr toErase = here;
			delete here;
		}
	}
	
	//location 관련 함수들
	//location 초기화
	void Impl_GoToRoot() {
		location = root;
	}

	//전 dir로 이동
	void Impl_GoToPrev() {
		location = location->prev;
	}

	//다음 dir 혹은 파일로 이동
	void Impl_GoToNext(TYPE type, const std::string& name) {

		if (!location->type) {
			std::cout << "Error : Location Error : Location type should be DIR" << std::endl;
			return;
		}

		for (int i = 0; i < location->next.size(); i++) {
			if (location->next[i]->name == name) {
				if (location->next[i]->type == type) {
					location = location->next[i];
					return;
				}
			}
		}

		std::cout << "There is no file or dir" << std::endl;
		return;
	}
};

int main() {
	nTree a;

	a.AddDir("newDir1");
	a.AddDir("newDir2");
	a.AddDir("newDir3");
	a.AddFile("newFile1");
	a.AddFile("newFile2");
	a.AddFile("newFile3");
	a.PrintAll();
	std::cout << std::endl;

	a.GoToNext(TYPE::DIR ,"newDir1");
	a.AddDir("newDir11");
	a.AddDir("newDir12");
	a.AddDir("newDir13");
	a.AddFile("newFile11");
	a.AddFile("newFile12");
	a.AddFile("newFile13");
	a.GoToPrevDir();
	a.PrintAll();
	std::cout << std::endl;

	a.GoToNext(TYPE::DIR, "newDir2");
	a.AddDir("newDir21");
	a.AddDir("newDir22");
	a.AddDir("newDir23");
	a.AddFile("newFile21");
	a.AddFile("newFile22");
	a.AddFile("newFile23");
	a.GoToPrevDir();
	a.PrintAll();
	std::cout << std::endl;

	a.GoToNext(TYPE::DIR, "newDir3");
	a.AddDir("newDir31");
	a.AddDir("newDir32");
	a.AddDir("newDir33");
	a.AddFile("newFile31");
	a.AddFile("newFile32");
	a.AddFile("newFile33");
	a.GoToPrevDir();
	a.PrintAll();
	std::cout << std::endl;

	a.DeleteDir("newDir3");
	a.PrintAll();
	std::cout << std::endl;

	a.DeleteDir("newDir2");
	a.PrintAll();
	std::cout << std::endl;

	a.DeleteDir("newDir1");
	a.PrintAll();
	std::cout << std::endl;

	return 0;
}