#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Game.h"

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	Game game;
	game.play();
}
