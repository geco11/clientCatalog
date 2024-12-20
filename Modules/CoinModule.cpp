#include "CoinModule.h"

Modules CoinModule::activate(std::any& context)
{
	Collection collection = std::any_cast<Collection>(context);
	std::vector<CoinPtr> coins = controller->search(collection);
	int i = 0;
	for (const CoinPtr a : coins) {
		std::cout << ++i << " " <<a->id<<"  " << a->name << " " << a->quantity << "  ";
		if (a->IsFavorite) std::cout << "+";
		else std::cout << "-";
		puts("");
	}
	printf("chosse the number of the coin or enter 0 to exit, enter -1 to go back to collections: ");
	int cmd;
	std::cin >> cmd;
	if (cmd == 0)
		return Modules::Exit;
	if (cmd == -1)
		return Modules::Countries;
	context = coins[cmd-1];
	return Modules::Coins;
}
