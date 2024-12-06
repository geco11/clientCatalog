#include "CoinModule.h"

Modules CoinModule::activate(std::any& context)
{
	Collection collection = std::any_cast<Collection>(context);
	std::vector<Coin> coins = controller->search(collection);
	int i = 0;
	for (const Collection& a : coins) {
		std::cout << i++ << " " << a.getName() << " " << a.getCountOfCoins() << "\n";
	}
	printf("chosse the number of the collection or enter 0 to exit, enter -1 to go back to countries: ");
	int cmd;
	std::cin >> cmd;
	if (cmd == 0)
		return Modules::Exit;
	if (cmd == -1)
		return Modules::Countries;
	context = collections[cmd - 1];
	return Modules::Coins;
}
