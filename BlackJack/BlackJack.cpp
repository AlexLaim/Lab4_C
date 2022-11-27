#include <iostream>
#include "Card.h"

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
    //std::cout << "\x06";
	Card carta;
	carta.setCard();
	std::cout << carta.getScore() << std::endl;
	std::cout << carta.getSuit() << std::endl;
}
