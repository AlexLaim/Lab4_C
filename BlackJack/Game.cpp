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
		std::cout << "���� ������?\n";
		std::cin >> bet;
		int numberDeck = rand() % 4;
		dealer_.setCard(decks[numberDeck].getCard(0));
		player_.setCard(decks[numberDeck].getCard(0));
		player_.setCard(decks[numberDeck].getCard(0));
		std::cout << "������: " << "[" << decks[0].getDeck().size() <<"] " << "[" << decks[1].getDeck().size() << "] " << "[" << decks[2].getDeck().size() << "] " << "[" << decks[3].getDeck().size() << "]\n";
		std::cout << "�����:";
		for (size_t i = 0; i < dealer_.getDealerDeck().size(); i++)
		{
			std::cout << dealer_.getCard(i);
		}
		std::cout << "\n��:";
		for (size_t i = 0; i < player_.getPlayerDeck().size(); i++)
		{
			std::cout << player_.getCard(i);
			if (player_.getPlayerDeck().size() == 3 && player_.getCard(0).getScoreCard(player_.getCard(0)) == 12 && player_.getCard(1).getScoreCard(player_.getCard(1))) {
				std::cout << "�����������! � ��� ���� �����! ��� �������: " << bet << " �����: " << bet * 2;
				flag = false;
				break;
			}
		}
	while (flag)
	{
		if (player_.getPlayerDeck().size() == 2) {
			std::cout << "\n1. ������\n2. ���\n3. ����\n";
		}else std::cout << "\n1. ������\n2. ���\n";
		int action;
		std::cin >> action;
		if (action == 3 && isDouble) {
			bet *= 2;
			std::cout << "�� ������� ������! ���� ������: " << bet << std::endl;
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
				std::cout << "\n�� ���������! �������!";
				flag = false;
				break;
			}
			else if (playerScore == 21) {
				std::cout << "\n����-����! ��� �������: " << bet << " �����: " << bet * 2;
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
						std::cout << "��������! � ������ ���� �����!";
						flag = false;
						break;
					}
					dealerScore += dealer_.getCard(i).getScoreDealer(dealerScore);
				}
			}
			dealerScore = 0;
			std::cout << "������: " << "[" << decks[0].getDeck().size() << "] " << "[" << decks[1].getDeck().size() << "] " << "[" << decks[2].getDeck().size() << "] " << "[" << decks[3].getDeck().size() << "]\n";
			std::cout << "�����:";
			for (size_t i = 0; i < dealer_.getDealerDeck().size(); i++)
			{
				std::cout << dealer_.getCard(i);
				dealerScore += dealer_.getCard(i).getScoreDealer(dealerScore);
				if (dealerScore > 21) {
					std::cout << "\n�� ��������! � ������ �������! ��� �������: " << bet << " �����: " << bet * 2;
					flag = false;
					break;
				}
			}
			std::cout << "\n��:";
			for (size_t i = 0; i < player_.getPlayerDeck().size(); i++)
			{
				std::cout << player_.getCard(i);
			}
			if (dealerScore == 21) {
				std::cout << "\n�� ���������! � ������ ����-����!";
			}
			else if (playerScore == dealerScore) {
				std::cout << "\n�����! ���� ������ ���������! �����: " << bet;
			}
			else if (playerScore > dealerScore && dealerScore < 21) {
				std::cout << "\n�� �������� �� �����! ��� �������: " << bet << " �����: " << bet * 2;
			}
			else if (dealerScore > playerScore && dealerScore < 21) {
				std::cout << "\n�� ��������� �� �����!";
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
								std::cout << "��������! � ������ ���� �����!";
								flag = false;
								break;
							}
							dealerScore += dealer_.getCard(i).getScoreDealer(dealerScore);
						}
					}
					dealerScore = 0;
					std::cout << "������: " << "[" << decks[0].getDeck().size() << "] " << "[" << decks[1].getDeck().size() << "] " << "[" << decks[2].getDeck().size() << "] " << "[" << decks[3].getDeck().size() << "]\n";
					std::cout << "�����:";
					for (size_t i = 0; i < dealer_.getDealerDeck().size(); i++)
					{
						std::cout << dealer_.getCard(i);
						dealerScore += dealer_.getCard(i).getScoreDealer(dealerScore);
						if (dealerScore > 21) {
							std::cout << "\n�� ��������! � ������ �������! ��� �������: " << bet << " �����: " << bet * 2;
							flag = false;
							break;
						}
					}
					std::cout << "\n��:";
					for (size_t i = 0; i < player_.getPlayerDeck().size(); i++)
					{
						std::cout << player_.getCard(i);						
					}
					if (dealerScore == 21) {
						std::cout << "\n�� ���������! � ������ ����-����!";
					}
					else if (playerScore == dealerScore) {
						std::cout << "\n�����! ���� ������ ���������! �����: " << bet;
					}
					else if (playerScore > dealerScore && dealerScore < 21) {
						std::cout << "\n�� �������� �� �����! ��� �������: " << bet << " �����: " << bet * 2;
					}
					else if (dealerScore > playerScore && dealerScore < 21) {
						std::cout << "\n�� ��������� �� �����!";
					}
					flag = false;
					break;
				case 2:
					player_.setCard(decks[numberDeck].getCard(0));
					std::cout << "������: " << "[" << decks[0].getDeck().size() << "] " << "[" << decks[1].getDeck().size() << "] " << "[" << decks[2].getDeck().size() << "] " << "[" << decks[3].getDeck().size() << "]\n";
					std::cout << "�����:";
					dealerScore = 0;
					for (size_t i = 0; i < dealer_.getDealerDeck().size(); i++)
					{
						std::cout << dealer_.getCard(i);
					}
					std::cout << "\n��:";
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
						std::cout << "\n�� ���������! �������!";
						flag = false;
					}
					else if (playerScore == 21) {
						std::cout << "\n����-����! ��� �������: " << bet << " �����: " << bet * 2;
						flag = false;
					}
					break;
				default:
					std::cout << "\n����������� ��������!\n";
					break;
				}
		}
	}
}

