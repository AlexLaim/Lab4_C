#pragma once
#include <ostream>
class Card
{
	friend std::ostream& operator<< (std::ostream& out, const Card& card);
private:
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
	enum suit {
		heart,
		diamond,
		club,
		spade,
		end_suit
	};
	score score_card;
	suit suit_card;
public:
	Card();
	virtual int getScore();
	virtual int getScoreDealer(int dealerScore_);
	virtual ~Card(){};
	Card::score getScoreCard(const Card& card);
};

