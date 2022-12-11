#pragma once
#include <vector>
#include "Card.h"
class Player
{
public:
	Player();
	std::vector<Card> getPlayerDeck();
	Card getCard(int i);
	void setCard(Card card);
private:
	std::vector<Card> playerCard;
};

