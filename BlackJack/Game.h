#pragma once
#include "Deck.h"
#include "Player.h"
#include "Dealer.h"

class Game
{
public:
	Game();
	void showDeck();
	void play();
private:
	std::vector<Deck> decks;
	int playerScore = 0, dealerScore = 0, bet = 0;
};
