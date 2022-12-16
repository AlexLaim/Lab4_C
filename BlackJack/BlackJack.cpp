#include <iostream>
#include "Game.h"

int main()
{
	//Рандом
	srand(time(NULL));
	//Установка русского языка
	setlocale(LC_ALL, "ru");
	//Создание и запуск игры
	Game game;
	game.play();
}
