#include "Card.h"
#include <iostream>
#include <random>
Card::Card()
{
}

int Card::getScore() {
	if (score_card < 8) {
		return score_card + 2;
	}
	else if (score_card > 8 && score_card < 12) {
		return 10;
	}
	else {
		while (true)
		{
			int value = 0;
			std::cout << "¬ведите значение туза: 1 или 11" << std::endl;
				std::cin >> value;
				switch (value)
				{
				case 1:
					return 1;
					break;
				case 11:
					return 11;
					break;
				default:
					std::cout << "¬ведено неверное значение!" << std::endl;
					break;
				}
		}
	}
}
const char* Card::getSuit() {
	if (suit_card == 0)
	{
		return "\x04";
	}
	else if(suit_card == 1){
		return "\x05";
	}
	else if (suit_card == 2) {
		return "\x06";
	}
	else {
		return "\x03";
	}
}

void Card::setCard() {
	suit_card = static_cast<suit>(rand() % spade);
	score_card = static_cast<score>(rand() % A);
}
