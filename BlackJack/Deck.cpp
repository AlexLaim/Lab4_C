#include "Deck.h"
Deck::Deck() {
	
}

void Deck::generateDeck() {
	deck_.resize(52);
	for (size_t i = 0; i < deck_.size(); i++)
	{
		deck_[i];
	}
}

std::vector<Card> Deck::getDeck() {
	return deck_;
}

Card Deck::getCard(int i) {
	Card tmp = deck_[i];
	deck_.erase(deck_.begin());
	return tmp;
}