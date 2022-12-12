#include <iostream>
#include "Adapter.h"
int main()
{
	IFormattable* adapter = new Adapter();
	Deck deck;
	adapter->prettyPrint(deck);
}
