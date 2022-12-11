#pragma once
#include <vector>
#include "Card.h"
class Dealer
{
public:
	Dealer();
	std::vector<Card> getDealerDeck();
	Card getCard(int i);
	void setCard(Card card);
private:
	std::vector<Card> dealerCard;
};

