#pragma once
#include <memory>

namespace Candlelight
{
	namespace TypeDefs
	{
		template <typename T>
		using sPtr = std::shared_ptr<T>;

		template<typename T>
		using uPtr = std::unique_ptr<T>;

		template<typename T>
		using wPtr = std::weak_ptr<T>;
	}
}