#pragma once
#include "IFormattable.h"
#include <iostream>
#include <string>

class Adapter : public IFormattable
{
public:
	Adapter();
	std::string format() override;
	void prettyPrint(const Deck& formatDeck) override;
};

