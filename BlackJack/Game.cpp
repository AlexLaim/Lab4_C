#include "Game.h"
#include "Adapter.h"

//Контруктор
Game::Game() {
	decks.resize(4);
	for (int i = 0; i < decks.size(); i++)
	{
		decks[i].generateDeck();
	}
}
//Показать колоду
void Game::showDeck() {
	for (int i = 0; i < decks.size(); i++)
	{
		std::cout << "\nDECK №" << i << std::endl;
		for (int j = 0; j < decks[i].getDeck().size(); j++)
		{
			std::cout << decks[i].getCard(j);
		}
	}
}
//Метод игры
void Game::play() {
	IFormattable*  adapter = new Adapter();
	Dealer dealer_;
	Player player_;
	bool flag = true, isDouble = true;
	//Интерактив с игроком
		std::cout << "Ваша ставка?\n";
		//Ставка
		std::cin >> bet;
		//Рандомный выбор колоды
		int numberDeck = rand() % 4;
		//Добавление карт в колоды дилера и игрока
		dealer_.setCard(decks[numberDeck].getCard(0));
		player_.setCard(decks[numberDeck].getCard(0));
		player_.setCard(decks[numberDeck].getCard(0));
		std::cout << "Колоды: " << "[" << decks[0].getDeck().size() <<"] " << "[" << decks[1].getDeck().size() << "] " << "[" << decks[2].getDeck().size() << "] " << "[" << decks[3].getDeck().size() << "]\n";
		std::cout << "Дилер:";
		//Вывод карт дилера
		for (int i = 0; i < dealer_.getDealerDeck().size(); i++)
		{
			std::cout << dealer_.getCard(i);
		}
		std::cout << "\nВы:";
		//Отдельный вывод для карт игрока
		adapter->prettyPrint(adapter->format(player_));
		//Цикл проверки карт
		for (int i = 0; i < player_.getPlayerDeck().size(); i++)
		{
			if (player_.getPlayerDeck().size() == 3 && player_.getCard(0).getScoreCard(player_.getCard(0)) == 12 && player_.getCard(1).getScoreCard(player_.getCard(1))) {
				std::cout << "Поздравляем! У вас пара тузов! Ваш выигрыш: " << bet << " Всего: " << bet * 2;
				flag = false;
				break;
			}
		}
	while (flag)
	{
		//Если это первый ход, то можно удвоить ставку, в противном случае нельзя.
		if (player_.getPlayerDeck().size() == 2) {
			std::cout << "\n1. Хватит\n2. Еще\n3. Дабл\n";
		}else std::cout << "\n1. Хватит\n2. Еще\n";
		int action;
		std::cin >> action;
		//Если ставка была удвоена
		if (action == 3 && isDouble) {
			bet *= 2;
			std::cout << "Вы удвоили ставку! Ваша ставка: " << bet << std::endl;
			player_.setCard(decks[numberDeck].getCard(0));
			adapter->prettyPrint(adapter->format(player_));
			playerScore = 0;
			//подсчет очков игрока
			for (int i = 0; i < player_.getPlayerDeck().size(); i++)
			{
				playerScore += player_.getCard(i).getScore();
			}
			try
			{
				if (playerScore > 21) {
					//Генерация исключения
					throw std::invalid_argument("Вы проиграли! Перебор!");
				}
			}
			catch (const std::invalid_argument& e)
			{
				//Обработка в случае исключения
				flag = false;
				std::cout << "\nВы проиграли! Перебор!";
				break;
			}
			//Если у игрока Бдек-джек
			 if (playerScore == 21) {
				std::cout << "\nБлек-джек! Ваш выигрыш: " << bet << " Всего: " << bet * 2;
				flag = false;
				break;
			}
			 //Цикл набора карт дилером
			while (dealerScore < 18) {
				numberDeck = rand() % 4;
				dealer_.setCard(decks[numberDeck].getCard(0));
				dealerScore = 0;
				//Подсчет очков дилера
				for (int i = 0; i < dealer_.getDealerDeck().size(); i++)
				{
					//Если у дилера пара тузов
					if (dealer_.getDealerDeck().size() == 3 && dealer_.getCard(0).getScoreCard(dealer_.getCard(0)) == 12 && dealer_.getCard(1).getScoreCard(dealer_.getCard(1)) == 12) {
						std::cout << "Проигрыш! У дилера пара тузов!";
						flag = false;
					}
					dealerScore += dealer_.getCard(i).getScoreDealer(dealerScore);
				}
			}
			dealerScore = 0;
			//Вывод колод
			std::cout << "Колоды: " << "[" << decks[0].getDeck().size() << "] " << "[" << decks[1].getDeck().size() << "] " << "[" << decks[2].getDeck().size() << "] " << "[" << decks[3].getDeck().size() << "]\n";
			std::cout << "Дилер:";
			for (int i = 0; i < dealer_.getDealerDeck().size(); i++)
			{
				std::cout << dealer_.getCard(i);
				dealerScore += dealer_.getCard(i).getScoreDealer(dealerScore);
			}
			std::cout << "\nВы:";
			adapter->prettyPrint(adapter->format(player_));
			//Вариации конца игры
			try
			{
				if (dealerScore > 21) {
					throw std::invalid_argument("Вы выиграли! У дилера перебор!");
				}
			}
			catch (const std::invalid_argument& e)
			{
				flag = false;
				std::cout << "\nВы выиграли! У дилера перебор! Ваш выигрыш: " << bet << " Всего: " << bet * 2;
				break;
			}
			 if (dealerScore == 21) {
				std::cout << "\nВы проиграли! У дилера блек-джек!";
			}
			else if (playerScore == dealerScore) {
				std::cout << "\nРовно! Ваша ставка вернулась! Всего: " << bet;
			}
			else if (playerScore > dealerScore && dealerScore < 21) {
				std::cout << "\nВы выиграли по очкам! Ваш выигрыш: " << bet << " Всего: " << bet * 2;
			}
			else if (dealerScore > playerScore && dealerScore < 21) {
				std::cout << "\nВы проиграли по очкам!";
			}
			flag = false;
		}
		if (action != 3) {
			isDouble = false;
			switch (action)
			{
				case 1:
					//Цикл набора карт дилером
					while (dealerScore < 18) {
						numberDeck = rand() % 4;
						dealer_.setCard(decks[numberDeck].getCard(0));
						dealerScore = 0;
						//Подсчет очков дилера
						for (int i = 0; i < dealer_.getDealerDeck().size(); i++)
						{
							//Если у дилера пара тузов
							if (dealer_.getDealerDeck().size() == 3 && dealer_.getCard(0).getScoreCard(dealer_.getCard(0)) == 12 && dealer_.getCard(1).getScoreCard(dealer_.getCard(1)) == 12) {
								std::cout << "Проигрыш! У дилера пара тузов!";
								flag = false;
								break;
							}
							dealerScore += dealer_.getCard(i).getScoreDealer(dealerScore);
						}
					}
					dealerScore = 0;
					//Вывод колод
					std::cout << "Колоды: " << "[" << decks[0].getDeck().size() << "] " << "[" << decks[1].getDeck().size() << "] " << "[" << decks[2].getDeck().size() << "] " << "[" << decks[3].getDeck().size() << "]\n";
					std::cout << "Дилер:";
					for (int i = 0; i < dealer_.getDealerDeck().size(); i++)
					{
						std::cout << dealer_.getCard(i);
						dealerScore += dealer_.getCard(i).getScoreDealer(dealerScore);
					}
					std::cout << "\nВы:";
					adapter->prettyPrint(adapter->format(player_));
					playerScore = 0;
					//Вариации конца игры
					for (int i = 0; i < player_.getPlayerDeck().size(); i++)
					{
						playerScore += player_.getCard(i).getScore();
					}
					try
					{
						if (dealerScore > 21) {
							throw std::invalid_argument("Вы выиграли! У дилера перебор!");
						}
					}
					catch (const std::invalid_argument& e)
					{
						flag = false;
						std::cout << "\nВы выиграли! У дилера перебор! Ваш выигрыш: " << bet << " Всего: " << bet * 2;
						break;
					}
					if (dealerScore == 21) {
						std::cout << "\nВы проиграли! У дилера блек-джек!";
					}
					else if (playerScore == dealerScore) {
						std::cout << "\nРовно! Ваша ставка вернулась! Всего: " << bet;
					}
					else if (playerScore > dealerScore && dealerScore < 21) {
						std::cout << "\nВы выиграли по очкам! Ваш выигрыш: " << bet << " Всего: " << bet * 2;
					}
					else if (dealerScore > playerScore && dealerScore < 21) {
						std::cout << "\nВы проиграли по очкам!";
					}
					flag = false;
					break;
				case 2:
					//Взятие карты
					player_.setCard(decks[numberDeck].getCard(0));
					//Вывод колод
					std::cout << "Колоды: " << "[" << decks[0].getDeck().size() << "] " << "[" << decks[1].getDeck().size() << "] " << "[" << decks[2].getDeck().size() << "] " << "[" << decks[3].getDeck().size() << "]\n";
					std::cout << "Дилер:";
					dealerScore = 0;
					for (int i = 0; i < dealer_.getDealerDeck().size(); i++)
					{
						std::cout << dealer_.getCard(i);
					}
					std::cout << "\nВы:";
					adapter->prettyPrint(adapter->format(player_));
					playerScore = 0;
					//Расчет очков игрока и отдельные случаи победы-поражения
					for (int i = 0; i < player_.getPlayerDeck().size(); i++)
					{
						playerScore += player_.getCard(i).getScore();
					}
					try
					{
						if (playerScore > 21) {
							throw std::invalid_argument("Вы проиграли! Перебор!");
						}
					}
					catch (const std::invalid_argument& e)
					{
						flag = false;
						std::cout << "\nВы проиграли! Перебор!";
						break;
					}
					if (playerScore == 21) {
						std::cout << "\nБлек-джек! Ваш выигрыш: " << bet << " Всего: " << bet * 2;
						flag = false;
					}
					break;
				default:
					std::cout << "\nНеизвестное действие!\n";
					break;
				}
		}
	}
}

