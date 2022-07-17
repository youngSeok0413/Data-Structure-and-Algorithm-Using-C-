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
#include <vector>

enum CARD {
	ACE = 1, 
	TWO = 2,
	THREE = 3,
	FOUR = 4,
	FIVE = 5,
	SIX = 6,
	SEVEN =7,
	EIGHT = 8,
	NINE = 9,
	TEN = 10,
	JACK = 11,
	QUEEN = 12,
	KING = 13
};

class player {
private:
	bool turn;
	std::vector<CARD> deck;
public:
	player() {
		turn = false;
		deck = {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
	}

	CARD showCard() {
		return deck[0];
	}

	void shuffleTheDeck() {
	}
};

int main() {
	return 0;
}