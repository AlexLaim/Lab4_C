#pragma once
#include <iostream>
#include <vector>
#include "Card.h"
class Deck 
{
private:
	//Массив карт колоды
	std::vector<Card> deck_;
public:
	//Конструктор
	Deck();
	//Заполнение колоды рандомными картами
	void generateDeck();
	 //Получение колоды
	 std::vector<Card> getDeck();
	 //Получение карты
	 virtual Card getCard(int i);
	 //Создание колоды новой колоды
	 std::vector<Card> setDeck(std::vector<Card> vec);
};

