#pragma once
#include <iostream>
#include <vector>
#include "Card.h"
class Deck 
{
private:
	std::vector<Card> deck_;
public:
	Deck();
	void generateDeck();
	 std::vector<Card> getDeck();
	 virtual Card getCard(int i);
	 std::vector<Card> setDeck(std::vector<Card> vec);
};

