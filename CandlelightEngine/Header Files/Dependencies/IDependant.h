#pragma once
#include "DependenciesContainer.h"

namespace Candlelight
{
	namespace Dependencies
	{
		class IDependant
		{
		public:
			virtual void GetDependencies(DependenciesContainer& dependencies) = 0;
			virtual ~IDependant() {};
		};
	}
}