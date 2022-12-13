#pragma once

#include "IFormattable.h"


#include <string>
#include <iostream>

class Adapter  : public IFormattable
{
public:
	Adapter();
	Deck format(Player playerDeck_);
	void prettyPrint(Deck formatDeck);
};
