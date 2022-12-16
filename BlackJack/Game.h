#pragma once
#include "Deck.h"
#include "Player.h"
#include "Dealer.h"

class Game
{
public:
	//Контруктор
	Game();
	//Показать колоду
	void showDeck();
	//Метод игры
	void play();
private:
	//Массив колод
	std::vector<Deck> decks;
	//Очки игрока и дилера, ставка
	int playerScore = 0, dealerScore = 0, bet = 0;
};
