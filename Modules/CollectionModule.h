#pragma once
#include"Module.h"
class CollectionModule :public Module
{
public:
	CollectionModule(ControllerPtr c) :Module(c) {};
	Modules activate(std::any& context)override;
};

