//Exercise 3
#include <iostream>
#include <deque>
#include <string>

struct Job {
	unsigned int workID;
	std::string userName;
	unsigned int pagesNum;
};

class Printer {
private:
	std::deque<Job> deq;
public:

	void getWork(const Job& job) {
		deq.push_back(job);
	}

	void print(const Job& job) {
		std::cout << job.workID << std::endl;
		std::cout << job.userName << std::endl;
		std::cout << job.pagesNum << std::endl;
		std::cout << std::endl;
	}

	void work() {
		Job job = deq.front();
		print(job);
		deq.pop_front();
	}

	bool empty() {
		return deq.empty();
	}
};

int main() {
	Job j1 = {1, "Tom", 10};
	Job j2 = { 2, "Tm", 109 };
	Job j3 = { 13, "To", 10567 };
	Job j4 = { 1532, "om", 104 };
	Job j5 = { 112321, "T", 10123 };
	Job j6 = { 1245, "m", 10123 };
	Job j7 = { 11231, "Tm", 101};

	Printer printer;
	printer.getWork(j1);
	printer.getWork(j2);
	printer.getWork(j3);
	printer.getWork(j4);
	printer.getWork(j5);
	printer.getWork(j6);
	printer.getWork(j7);
	
	while (!printer.empty()) {
		printer.work();
	}

	return 0;
}