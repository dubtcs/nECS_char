#pragma once

#include <memory>
#include <bitset>

namespace ecs
{

	constexpr uint32_t gMaxEntities{ 1'000'000 }; // 100
	constexpr uint32_t gMaxEntitiesOOB{ gMaxEntities + 1 }; // 101
	constexpr uint16_t gMaxComponents{ 32 }; // 16

	using Signature = std::bitset< gMaxComponents >;
	using EntityID = uint64_t;

	// make sure gMaxComponents and ComponentTypeID share same bit size
	using ComponentTypeID = uint32_t;

	// smart pointers
	template<typename T>
	using Ref = std::shared_ptr<T>;

	template<typename T, typename... A>
	constexpr Ref<T> NewRef(A&&... a) {
		return std::make_shared<T>(std::forward<A>(a)...);
	}

	template<typename T>
	using Unique = std::unique_ptr<T>;

	template<typename T, typename... A>
	constexpr Unique<T> NewUnique(A&&... a) {
		return std::make_unique<T>(std::forward<A>(a)...);
	}

}
