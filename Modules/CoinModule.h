#pragma once
#include "Module.h"
class CoinModule :public Module
{
public:
	CoinModule(ControllerPtr c) :Module(c) {};
	Modules activate(std::any& context)override;
};

