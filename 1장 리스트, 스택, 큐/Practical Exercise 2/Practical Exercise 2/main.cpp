//Practical Exercise 2
/*
* 4 players play a game.
* Each players holds 13 cards in ther hand
* there will be four cards to compare
* if there are two same type of cards, remove them
* if there are three, just remove two of them
* if all cards are same type, remove all of them
* if there is any card pair, then player shuffle the deck
* the one who throw all the deck will win!!
*/

#include <iostream>
#include <list>
#include <algorithm>
#include <time.h>

class Player {
private:
	std::list<int> deck;
public:
	Player() {
		deck = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
		shuffleDeck();
	}

	int showCard() { return deck.back(); }

	void deleteCard() { deck.pop_back(); }

	void returnCard() {
		int card = deck.back();
		deck.pop_back();
		deck.push_front(card);
	}

	void shuffleDeck() {
		int sz = (int)(this->deck.size());
		int* arr = new int[sz];
		int i = 0;

		for (std::list<int>::iterator iter = deck.begin(); iter != deck.end(); iter++) {
			arr[i] = *iter;
			i++;
		}

		deck.clear();

		int randomNumber = rand()%sz;

		for (int i = 0; i < sz; i++) {
			while (arr[randomNumber] == -1) {
				randomNumber = rand() % sz;
			}

			deck.push_back(arr[randomNumber]);
			arr[randomNumber] = -1;
		}

		delete[] arr;

	}

	bool whetherDeckEmpty() { return deck.empty(); }

	void printTheDeck() {
		for (std::list<int>::iterator iter = deck.begin(); iter != deck.end(); iter++) {
			std::cout << *iter << " ";
		}

		std::cout << std::endl;
	}
};

class Game {
private:
	Player players[4];
	int whatPlayerShow[4] = {-1, -1, -1, -1};
	bool deleteOrReturn[4] = {false, false, false, false};
public:
	Game() {
		bool over = false;

		while (!over) {
			showDeckState();
			updateWhatPlayerShow();
			showWhatPlayersShow();
			updateDeck(updateWheterDeleteOrShow());
			std::cout << std::endl;
			over = whehterGameFinished();
		}
	}

	void showDeckState() {
		for (int i = 0; i < 4; i++)
			players[i].printTheDeck();
	}

	void showWhatPlayersShow() {
		for (int i = 0; i < 4; i++)
			std::cout << "Player " << i + 1 << " : " << whatPlayerShow[i] << std::endl;
	}

	void showDeleteOrReturn() {
		for (int i = 0; i < 4; i++)
			std::cout << "Player " << i + 1 << " : " << deleteOrReturn[i] << std::endl;
	}

	void updateWhatPlayerShow() {
		for (int i = 0; i < 4; i++)
			whatPlayerShow[i] = players[i].showCard();
	}

	bool updateWheterDeleteOrShow() {

		for (int i = 0; i < 4; i++)
			deleteOrReturn[i] = false;

		if (whatPlayerShow[0] == whatPlayerShow[1]) {
			deleteOrReturn[0] = true;
			deleteOrReturn[1] = true;
		}
		if (whatPlayerShow[0] == whatPlayerShow[2]) {
			deleteOrReturn[0] = true;
			deleteOrReturn[2] = true;
		}
		if (whatPlayerShow[0] == whatPlayerShow[3]) {
			deleteOrReturn[0] = true;
			deleteOrReturn[3] = true;
		}
		if (whatPlayerShow[1] == whatPlayerShow[2]) {
			deleteOrReturn[1] = true;
			deleteOrReturn[2] = true;
		}
		if (whatPlayerShow[1] == whatPlayerShow[3]) {
			deleteOrReturn[1] = true;
			deleteOrReturn[3] = true;
		}
		if (whatPlayerShow[2] == whatPlayerShow[3]) {
			deleteOrReturn[2] = true;
			deleteOrReturn[3] = true;
		}

		int cnt = 0;
		for (int i = 0; i < 4; i++){
			if (deleteOrReturn[i]) { cnt++; }
		}

		if (cnt == 3) {
			for (int i = 0; i < 4; i++) {
				if (deleteOrReturn[i] == true) {
					int coin = rand()%2;
					if (coin == 1) {
						deleteOrReturn[i] = false;
						break;
					}
				}
			}
		}
		else if (cnt == 0) {
			return true;
		}

		return false;

	}

	void updateDeck(bool whetherShuffle){

		for (int i = 0; i < 4; i++) {
			if (deleteOrReturn[i] == true) {
				players[i].deleteCard();
			}
			else {
				players[i].returnCard();
			}
		}

		if (whetherShuffle == true) {
			for (int i = 0; i < 4; i++) {
				int coin = rand()%2;
				if (coin == 1) {
					players[i].shuffleDeck();
				}
			}
		}
	}

	bool whehterGameFinished() {
		bool over = false;

		for (int i = 0; i < 4; i++) {
			if (players[i].whetherDeckEmpty()) {
				std::cout << "Player " << i + 1 << " wins" << std::endl;
				over = true;
			}
		}

		if (over) {
			std::cout << std::endl;
			std::cout << "Last State" << std::endl;
			showWhatPlayersShow();
		}

		return over;
	}
};



int main() {
	Game game;
	
	return 0;
}