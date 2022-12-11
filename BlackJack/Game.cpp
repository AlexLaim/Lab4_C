#include "Game.h"


Game::Game() {
	decks.resize(4);
	for (size_t i = 0; i < decks.size(); i++)
	{
		decks[i].generateDeck();
	}
}

void Game::showDeck() {
	for (size_t i = 0; i < decks.size(); i++)
	{
		for (size_t j = 0; j < decks[i].getDeck().size(); j++)
		{
			std::cout << decks[i].getCard(j);
		}
		std::cout << "\nNEXT DECK" << std::endl;
	}
}

void Game::play() {
	Dealer dealer_;
	Player player_;
	bool flag = true, isDouble = true;
		std::cout << "Ваша ставка?\n";
		std::cin >> bet;
		int numberDeck = rand() % 4;
		dealer_.setCard(decks[numberDeck].getCard(0));
		player_.setCard(decks[numberDeck].getCard(0));
		player_.setCard(decks[numberDeck].getCard(0));
		std::cout << "Колоды: " << "[" << decks[0].getDeck().size() <<"] " << "[" << decks[1].getDeck().size() << "] " << "[" << decks[2].getDeck().size() << "] " << "[" << decks[3].getDeck().size() << "]\n";
		std::cout << "Дилер:";
		for (size_t i = 0; i < dealer_.getDealerDeck().size(); i++)
		{
			std::cout << dealer_.getCard(i);
		}
		std::cout << "\nВы:";
		for (size_t i = 0; i < player_.getPlayerDeck().size(); i++)
		{
			std::cout << player_.getCard(i);
			if (player_.getPlayerDeck().size() == 3 && player_.getCard(0).getScoreCard(player_.getCard(0)) == 12 && player_.getCard(1).getScoreCard(player_.getCard(1))) {
				std::cout << "Поздравляем! У вас пара тузов! Ваш выигрыш: " << bet << " Всего: " << bet * 2;
				flag = false;
				break;
			}
		}
	while (flag)
	{
		if (player_.getPlayerDeck().size() == 2) {
			std::cout << "\n1. Хватит\n2. Еще\n3. Дабл\n";
		}else std::cout << "\n1. Хватит\n2. Еще\n";
		int action;
		std::cin >> action;
		if (action == 3 && isDouble) {
			bet *= 2;
			std::cout << "Вы удвоили ставку! Ваша ставка: " << bet << std::endl;
			player_.setCard(decks[numberDeck].getCard(0));
			for (size_t i = 0; i < player_.getPlayerDeck().size(); i++)
			{
				std::cout << player_.getCard(i);
			}
			playerScore = 0;
			for (size_t i = 0; i < player_.getPlayerDeck().size(); i++)
			{
				playerScore += player_.getCard(i).getScore();
			}
			if (playerScore > 21) {
				std::cout << "\nВы проиграли! Перебор!";
				flag = false;
				break;
			}
			else if (playerScore == 21) {
				std::cout << "\nБлек-джек! Ваш выигрыш: " << bet << " Всего: " << bet * 2;
				flag = false;
				break;
			}
			while (dealerScore < 18) {
				numberDeck = rand() % 4;
				dealer_.setCard(decks[numberDeck].getCard(0));
				dealerScore = 0;
				for (size_t i = 0; i < dealer_.getDealerDeck().size(); i++)
				{
					if (dealer_.getDealerDeck().size() == 3 && dealer_.getCard(0).getScoreCard(dealer_.getCard(0)) == 12 && dealer_.getCard(1).getScoreCard(dealer_.getCard(1)) == 12) {
						std::cout << "Проигрыш! У дилера пара тузов!";
						flag = false;
						break;
					}
					dealerScore += dealer_.getCard(i).getScoreDealer(dealerScore);
				}
			}
			dealerScore = 0;
			std::cout << "Колоды: " << "[" << decks[0].getDeck().size() << "] " << "[" << decks[1].getDeck().size() << "] " << "[" << decks[2].getDeck().size() << "] " << "[" << decks[3].getDeck().size() << "]\n";
			std::cout << "Дилер:";
			for (size_t i = 0; i < dealer_.getDealerDeck().size(); i++)
			{
				std::cout << dealer_.getCard(i);
				dealerScore += dealer_.getCard(i).getScoreDealer(dealerScore);
				if (dealerScore > 21) {
					std::cout << "\nВы выиграли! У дилера перебор! Ваш выигрыш: " << bet << " Всего: " << bet * 2;
					flag = false;
					break;
				}
			}
			std::cout << "\nВы:";
			for (size_t i = 0; i < player_.getPlayerDeck().size(); i++)
			{
				std::cout << player_.getCard(i);
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
					while (dealerScore < 18) {
						numberDeck = rand() % 4;
						dealer_.setCard(decks[numberDeck].getCard(0));
						dealerScore = 0;
						for (size_t i = 0; i < dealer_.getDealerDeck().size(); i++)
						{
							if (dealer_.getDealerDeck().size() == 3 && dealer_.getCard(0).getScoreCard(dealer_.getCard(0)) == 12 && dealer_.getCard(1).getScoreCard(dealer_.getCard(1)) == 12) {
								std::cout << "Проигрыш! У дилера пара тузов!";
								flag = false;
								break;
							}
							dealerScore += dealer_.getCard(i).getScoreDealer(dealerScore);
						}
					}
					dealerScore = 0;
					std::cout << "Колоды: " << "[" << decks[0].getDeck().size() << "] " << "[" << decks[1].getDeck().size() << "] " << "[" << decks[2].getDeck().size() << "] " << "[" << decks[3].getDeck().size() << "]\n";
					std::cout << "Дилер:";
					for (size_t i = 0; i < dealer_.getDealerDeck().size(); i++)
					{
						std::cout << dealer_.getCard(i);
						dealerScore += dealer_.getCard(i).getScoreDealer(dealerScore);
						if (dealerScore > 21) {
							std::cout << "\nВы выиграли! У дилера перебор! Ваш выигрыш: " << bet << " Всего: " << bet * 2;
							flag = false;
							break;
						}
					}
					std::cout << "\nВы:";
					for (size_t i = 0; i < player_.getPlayerDeck().size(); i++)
					{
						std::cout << player_.getCard(i);						
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
					player_.setCard(decks[numberDeck].getCard(0));
					std::cout << "Колоды: " << "[" << decks[0].getDeck().size() << "] " << "[" << decks[1].getDeck().size() << "] " << "[" << decks[2].getDeck().size() << "] " << "[" << decks[3].getDeck().size() << "]\n";
					std::cout << "Дилер:";
					dealerScore = 0;
					for (size_t i = 0; i < dealer_.getDealerDeck().size(); i++)
					{
						std::cout << dealer_.getCard(i);
					}
					std::cout << "\nВы:";
					for (size_t i = 0; i < player_.getPlayerDeck().size(); i++)
					{
						std::cout << player_.getCard(i);
					}
					playerScore = 0;
					for (size_t i = 0; i < player_.getPlayerDeck().size(); i++)
					{
						playerScore += player_.getCard(i).getScore();
					}
					if (playerScore > 21) {
						std::cout << "\nВы проиграли! Перебор!";
						flag = false;
					}
					else if (playerScore == 21) {
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

