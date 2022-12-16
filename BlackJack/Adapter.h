#pragma once

#include "IFormattable.h"


#include <string>
#include <iostream>

class Adapter  : public IFormattable
{
public:
	//Конструктор
	Adapter();
	//Смена форматов
	Deck format(Player playerDeck_);
	//Красивый вывод колоды игрока
	void prettyPrint(Deck formatDeck);
};
