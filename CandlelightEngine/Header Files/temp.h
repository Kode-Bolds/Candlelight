#pragma once
#include "Dependencies.h"

class Temp : public Candlelight::Dependencies::IDependant
{
public:

	void GetDependencies(Candlelight::Dependencies::DependenciesContainer& dependencies);
	void Help();
};