#pragma once

#include "Typedef.h"

#include <ostream>

namespace ecs
{

	using PackIndex = int32_t;

	class ComponentPack
	{
	public:
		ComponentPack() = default;
		ComponentPack(size_t elementSize);
		void* Get(const EntityID& id);
		void* Add(const EntityID& id);
		void Remove(const EntityID& id);
	protected:
		Ref<std::vector<char>> mData;
		Ref<std::vector<size_t>> mIndexToEntity;
		Ref<std::array<size_t, gMaxEntities>> mEntityToIndex;
		size_t mElementSize;
		uint32_t mLength{ 0 };
	};

}
