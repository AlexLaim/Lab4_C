#include "Dealer.h"
//Конструктор
Dealer::Dealer() {

}
//Получение карт дилера
std::vector<Card> Dealer::getDealerDeck() {
	return dealerCard;
}
//Получение карты
Card Dealer::getCard(int i) {
	return dealerCard[i];
}
//Установка карты в массив карт
void Dealer::setCard(Card card) {
	dealerCard.push_back(card);
}