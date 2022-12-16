#include "Deck.h"
//Конструктор
Deck::Deck() {
	
}
//Заполнение колоды рандомными картами
void Deck::generateDeck() {
	deck_.resize(52);
	for (int i = 0; i < deck_.size(); i++)
	{
		deck_[i];
	}
}
//Получение колоды
std::vector<Card> Deck::getDeck() {
	return deck_;
}
//Создание колоды новой колоды
std::vector<Card> Deck::setDeck(std::vector<Card> vec) {
	deck_.resize(vec.size());
	for (int i = 0; i < vec.size(); i++)
	{
		deck_[i] = vec[i];
	}
	return deck_;
}
//Получение карты
Card Deck::getCard(int i) {
	Card tmp = deck_[i];
	deck_.erase(deck_.begin());
	return tmp;
}