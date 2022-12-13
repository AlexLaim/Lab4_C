#pragma once

#include "Player.h"
#include "Deck.h"
#include <string>

class IFormattable
{
public:
    virtual Deck format(Player playerDeck_) =0;
    virtual void prettyPrint(Deck object)=0;
};