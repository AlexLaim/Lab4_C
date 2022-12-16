#include "Card.h"
#include <iostream>
#include <random>
#include <windows.h>

//Конструктор
Card::Card()
{
	suit_card = static_cast<suit>(rand() % end_suit);
	score_card = static_cast<score>(rand() % end_card);
}
//Перегрузка оператора вывода
std::ostream& operator<<(std::ostream &out, const Card &card) {
	char suit;
	HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	if (card.suit_card == 0)
	{
		suit = '\x04';
	}
	else if (card.suit_card == 1) {
		suit = '\x05';
	}
	else if (card.suit_card == 2) {
		suit = '\x06';
	}
	else {
		suit = '\x03';
	}
	
	if (card.score_card <= 8) {
		out << card.score_card + 2 << suit << " ";
	}
	else if (card.score_card == 9) {
		out << 'J' << suit << " ";
	}
	else if (card.score_card == 10) {
		out << 'Q' << suit << " ";
	}
	else if (card.score_card == 11) {
		out << 'K' << suit << " ";
	}
	else if (card.score_card >= 12) {
		out << 'A' << suit << " ";
	}
	return out;
}

//Метод расчета очков
int Card::getScore() {
	if (score_card < 8) {
		return score_card + 2;
	}
	else if (score_card >= 8 && score_card < 12) {
		return 10;
	}
	else {
		while (true)
		{
			int value = 0;
			std::cout << "\nВведите значение туза: 1 или 11" << std::endl;
				std::cin >> value;
				switch (value)
				{
				case 1:
					return 1;
					break;
				case 11:
					return 11;
					break;
				default:
					std::cout << "Введено неверное значение!" << std::endl;
					break;
				}
		}
	}
}
//Отдельный метод расчета очков для дилера
int Card::getScoreDealer(int dealerScore_) {
	if (score_card < 8) {
		return score_card + 2;
	}
	else if (score_card >= 8 && score_card < 12) {
		return 10;
	}
	else {
		if (dealerScore_ <=10) {
			return 11;
		}
		else {
			return 1;
		}
	}
}
//Получение числа очков карты
Card::score Card::getScoreCard(const Card& card) {
	return card.score_card;
}

