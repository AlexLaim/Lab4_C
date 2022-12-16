#pragma once
#include <ostream>
class Card
{
	friend std::ostream& operator<< (std::ostream& out, const Card& card);
private:
	//Ранг карты
	enum score {
		two,
		three,
		four,
		five,
		six,
		seven,
		eight,
		nine,
		ten,
		J,
		Q,
		K,
		A,
		end_card
	};
	//Масть карты
	enum suit {
		heart,
		diamond,
		club,
		spade,
		end_suit
	};
	// Переменные ранга и масти
	score score_card;
	suit suit_card;
public:
	//Контруктор
	Card();
	//Метод расчета очков
	virtual int getScore();
	//Отдельный метод расчета очков для дилера
	virtual int getScoreDealer(int dealerScore_);
	//Деструктор
	virtual ~Card(){};
	//Получение числа очков карты
	Card::score getScoreCard(const Card& card);
};

