#pragma once
#include <vector>
#include "Card.h"

class Player 
{
public:
	//Конструктор
	Player();
	//Получение карт игрока
	std::vector<Card> getPlayerDeck();
	//Получение карты
	Card getCard(int i);
	//Установка карты в массив карт игрока
	void setCard(Card card);
private:
	//Карты игрока
	std::vector<Card> playerCard;
};

