#include <iostream>
#include "Card.h"
#include "Deck.h"

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
    //std::cout << "\x06";
	/*Card carta;
	carta.setCard();
	std::cout << carta.getScore() << std::endl;
	std::cout << carta.getSuit() << std::endl;*/
	Deck deck1;
	deck1.generateDeck();
	for (size_t i = 0; i < deck1.getDeck().size(); i++)
	{
		std::cout << deck1.getDeck()[i]->getScore()<< " ";
		std::cout << deck1.getDeck()[i]->getSuit() << std::endl;
	}
}
