#pragma once
#include "../BlackJack/Deck.h"
#include <string>

class IFormattable
{
public:
	virtual std::string format() = 0;
	virtual void prettyPrint(const Deck& object) = 0;
};

