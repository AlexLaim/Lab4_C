#include "Adapter.h"

#include <string>
#include <iostream>
#include <windows.h>

//Конструктор
Adapter::Adapter() {

}
//Смена форматов
Deck Adapter::format(Player playerDeck_) {
	Deck newFormatPlayerDeck;
	newFormatPlayerDeck.setDeck(playerDeck_.getPlayerDeck());
	return newFormatPlayerDeck;
}
//Красивый вывод колоды игрока
void Adapter::prettyPrint(Deck formatDeck) {
	HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < formatDeck.getDeck().size(); i++)
	{
		SetConsoleTextAttribute(hwnd,12);
		std::cout << formatDeck.getDeck()[i];
	}
	SetConsoleTextAttribute(hwnd, 7);
}