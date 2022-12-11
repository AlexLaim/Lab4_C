#include "Dealer.h"

Dealer::Dealer() {

}

std::vector<Card> Dealer::getDealerDeck() {
	return dealerCard;
}

Card Dealer::getCard(int i) {
	return dealerCard[i];
}

void Dealer::setCard(Card card) {
	dealerCard.push_back(card);
}