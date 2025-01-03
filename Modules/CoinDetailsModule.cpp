#include "CoinDetailsModule.h"

void CoinDetailsModule::MakeFavorite(CoinPtr coin)
{
	controller->toggleMark(coin->id);
	coin->IsFavorite = !coin->IsFavorite;
}

Modules CoinDetailsModule::activate(std::any& context)
{
	CoinPtr coin = std::any_cast<CoinPtr>(context);
	context.reset();
	int cmd = 0;
	while (true) {
	    std::cout << *coin;
	    printf("enter 3 to decrement,enter 2 to add a coin,enter 1 to toggle isFavorite, enter 0 to exit, enter -1 to go back to coins: ");
		std::cin >> cmd;
		if (cmd == 2) {
			controller->increment(coin->id);
			coin->quantity++;
		}
		if (cmd == 3&&coin->quantity>0) {
			controller->decrement(coin->id);
			coin->quantity--;
		}
		if (cmd == 1)
			MakeFavorite(coin);
		if (cmd == 0)
			return Modules::Exit;
		if (cmd == -1)
			return Modules::Coins;
	}
}
