#pragma once
#include "../BlackJack/Deck.h"
#include <string>

class IFormattable
{
public:
	virtual std::string format();
	virtual void prettyPrint(const Deck& object);
};

