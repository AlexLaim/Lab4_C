#pragma once
class Card
{
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
		A
	};
	enum suit {
		heart,
		diamond,
		club,
		spade
	};

	score score_card;
	suit suit_card;
public:
	Card();
	int getScore();
	const char* getSuit();
	void setCard();
};

