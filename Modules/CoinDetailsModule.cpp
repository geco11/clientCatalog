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
	std::cout << *coin;
	int cmd = 1;
	printf("enter 1 to toggle isFavorite enter 0 to exit, enter -1 to go back to coins: ");
	while (cmd == 1) {
		std::cin >> cmd;
		if (cmd == 1)
			MakeFavorite(coin);
		if (cmd == 0)
			return Modules::Exit;
		if (cmd == -1)
			return Modules::Coins;
		std::cout << *coin;
		printf("enter 1 to toggle isFavorite enter 0 to exit, enter -1 to go back to coins: ");

	}
}
