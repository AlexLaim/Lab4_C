#include "Player.h"
Player::Player() {

}

std::vector<Card> Player::getPlayerDeck() {
	return playerCard;
}

Card Player::getCard(int i) {
	return playerCard[i];
}

void Player::setCard(Card card) {
	playerCard.push_back(card);
}