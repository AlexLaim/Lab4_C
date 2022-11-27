#include "Deck.h"
Deck::Deck() {
	
}

void Deck::generateDeck() {
	deck_.resize(52);
	for (size_t i = 0; i < deck_.size(); i++)
	{
		deck_[i]->setCard();
	}
}

std::vector<Card*> Deck::getDeck() {
	return deck_;
}