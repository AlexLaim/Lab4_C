#pragma once
#include <vector>
#include "Card.h"
class Dealer
{
public:
	//Конструктор
	Dealer();
	//Получение карт дилера
	std::vector<Card> getDealerDeck();
	//Получение карты
	Card getCard(int i);
	//Установка карты в массив карт
	void setCard(Card card);
private:
	//Карты дилера
	std::vector<Card> dealerCard;
};

