#pragma once
#include "typedefs.h"
#include "IDependency.h"
#include <vector>
#include <memory>

using namespace Candlelight::TypeDefs;

namespace Candlelight
{
	namespace Dependencies
	{
		struct DependenciesContainer
		{
			std::vector<sPtr<IDependency>> dependencies;

			template<typename T>
			sPtr<T> GetDependency()
			{
				sPtr<T> foundDependency;
				for (const auto& dependency : dependencies)
				{
					if (typeid(T) == typeid(*dependency))
						return foundDependency;
				}

				printf("%s\n", "Dependency does not exist!");

				return nullptr;
			}
		};
	}
}