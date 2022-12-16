#include "Player.h"
//Конструктор
Player::Player() {

}
//Получение карт игрока
std::vector<Card> Player::getPlayerDeck() {
	return playerCard;
}
//Получение карты
Card Player::getCard(int i) {
	return playerCard[i];
}
//Установка карты в массив карт игрока
void Player::setCard(Card card) {
	playerCard.push_back(card);
}