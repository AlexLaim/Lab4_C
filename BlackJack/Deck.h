#pragma once
#include <iostream>
#include <vector>
#include "Card.h"
class Deck
{
private:
	std::vector<Card*> deck_;
public:
	Deck();
	~Deck() {};

};

