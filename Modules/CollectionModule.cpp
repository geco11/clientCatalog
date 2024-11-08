#include "CollectionModule.h"

Modules CollectionModule::activate(std::any& context)
{
	std::string country = std::any_cast<std::string>(context);
}
