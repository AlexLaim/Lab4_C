#pragma once

#include "Player.h"
#include "Deck.h"
#include <string>

class IFormattable
{
public:
    //Получение и смена форматов
    virtual Deck format(Player playerDeck_) =0;
    //Красивый вывод
    virtual void prettyPrint(Deck object)=0;
};