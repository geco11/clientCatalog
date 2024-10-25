#pragma once
#include<rpc/client.h>
#include<IController.h>
class Controller :public IController
{
	std::unique_ptr<rpc::client>client=nullptr;
public:
	std::vector<CoinPtr> search(Collection collection)override;
	bool toggleMark(size_t id)override;
	int increment(size_t id)override;
	int decrement(size_t id)override;
	std::vector<std::string> getAllCountries()override;
	std::vector<Collection> getCollections(std::string_view country)override;
	Controller();
	~Controller();
};

