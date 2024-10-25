#include "Controller.h"

Controller::Controller(){
	client = std::make_unique<rpc::client>("localhost",8080);
}
std::vector<std::string> Controller::getAllCountries() {
	return client->call("getAllCountries").as<std::vector<std::string>>();
}
int Controller::increment(size_t id) {
	return client->call("increment", id).as<int>();
}
int Controller::decrement(size_t id) {
	return client->call("decrement", id).as<int>();
}
