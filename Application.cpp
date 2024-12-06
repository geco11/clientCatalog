#include"Modules/CollectionModule.h"
#include "Application.h"

void Application::run()
{
	Modules next=static_cast<Modules>(0);
	std::any context;
	while (next != Modules::Exit) {
		next=modules[next]->activate(context);
	}
}

Application::Application()
{
	controller=std::make_shared<Controller>();
	modules.resize(Modules::Exit);
	modules[Modules::Countries] = std::make_unique<CountriesModule>(controller);
	modules[Modules::Collections] = std::make_unique<CollectionModule>(controller);

}
